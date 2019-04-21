#pragma once
#define Input _Input::Instance()
class _Input
{
public:
	void __fastcall StartSetWindowWndProc();

	HANDLE m_hThread;
	static _Input& Instance() {
		static _Input _Handle;
		return _Handle;
	}
};
