/**
* Overlord Project
* Copyright (C) 2016-2017 RangeMachine
*/

#pragma once
#include "stdafx.h"
#include "Input.h"
#include "ImGui/imgui.h"

static WNDPROC OldLongWinProc = NULL;
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK NewWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
	return CallWindowProc(OldLongWinProc, hwnd, uMsg, wParam, lParam);
}
void __fastcall _Input::StartSetWindowWndProc()
{
	//VMProtectBegin(__FUNCTION__);
	OldLongWinProc = (WNDPROC)SetWindowLongPtr(CProcess.pWinhWnd, GWLP_WNDPROC, (__int64)NewWndProc);
	//VMProtectEnd;
}
