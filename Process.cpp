#include "stdafx.h"
#include "Process.h"

HANDLE __fastcall Open(DWORD Id)
{
	return OpenProcess(PROCESS_ALL_ACCESS, NULL, Id);
}
BOOL __fastcall Close(HANDLE handle)
{
	return CloseHandle(handle);
}

int __fastcall _CProcess::GetTargetProcessId(const char* Name)
{
	VMProtectBegin(__FUNCTION__);
	_TRY
		pName = Name;
	PROCESSENTRY32 pProcessInfo;
	pProcessInfo.dwSize = sizeof(PROCESSENTRY32);
	auto hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (hSnapshot == NULL)
	{
		return 0;
	}
	auto status = Process32First(hSnapshot, &pProcessInfo);
	while (status)
	{
		if (pProcessInfo.szExeFile)
		{
			if (strstr(pProcessInfo.szExeFile, pName) != 0)
			{
				pId = pProcessInfo.th32ProcessID;
				if (hSnapshot)
				{
					CloseHandle(hSnapshot);
				}
				return pId;
			}
		}
		status = Process32Next(hSnapshot, &pProcessInfo);
	}
	if (hSnapshot)
	{
		CloseHandle(hSnapshot);
	}
	return pId;
	_CATCH
		VMProtectEnd;
}

HWND __fastcall _CProcess::GetTargethWnd(int ProcessId, const char* ClassName, const char* WindowName)
{
	VMProtectBegin(__FUNCTION__);
	HWND	hWndTemp = GetWindow(GetDesktopWindow(), GW_CHILD);
	DWORD	hWndProcessID = 0;
	HWND	RethWnd = 0;
	while (hWndTemp)
	{
		hWndTemp = GetWindow(hWndTemp, GW_HWNDNEXT);
		if (hWndTemp)
		{
			GetWindowThreadProcessId(hWndTemp, &hWndProcessID);
			if (hWndProcessID == ProcessId) {
				char	ClassStrBuf[MAX_PATH];
				GetClassNameA(hWndTemp, ClassStrBuf, MAX_PATH);
				if (WindowName == NULL)
				{
					if (!strcmp(ClassStrBuf, ClassName))
					{
						RtlZeroMemory(&ClassStrBuf, sizeof(ClassStrBuf));
						RethWnd = hWndTemp;
						break;
					}
				}
				else
				{
					char	TextStrBuf[MAX_PATH];
					GetWindowTextA(hWndTemp, TextStrBuf, MAX_PATH);
					if (ClassName == NULL)
					{
						if (!strcmp(TextStrBuf, ClassName))
						{
							RtlZeroMemory(&TextStrBuf, sizeof(TextStrBuf));
							RethWnd = hWndTemp;
							break;
						}
					}
					else
					{
						if (!strcmp(TextStrBuf, WindowName) && !strcmp(ClassStrBuf, ClassName))
						{
							RtlZeroMemory(&TextStrBuf, sizeof(TextStrBuf));
							RtlZeroMemory(&ClassStrBuf, sizeof(ClassStrBuf));
							RethWnd = hWndTemp;
							break;
						}
					}
				}
			}
		}
	}
	RtlZeroMemory(&ClassName, sizeof(ClassName));
	RtlZeroMemory(&WindowName, sizeof(WindowName));
	return RethWnd;
	VMProtectEnd;
}

__int64 __fastcall _CProcess::GetProcessBase()
{
	if (pName == "")return 0;
	if (pId == 0)return 0;

	wstring  wstr;
	int nLen = strlen(pName);
	wstr.resize(nLen, L' ');
	MultiByteToWideChar(CP_ACP, 0, pName, nLen, (LPWSTR)wstr.c_str(), nLen);
	//Z_GetModuleInfo(pId, _pBase, (wchar_t*)wstr.c_str());
	return _pBase;
}
__int64 __fastcall _CProcess::GetModuleBase(const char* ModuleName)
{
	return (int64_t)GetModuleHandle(ModuleName);
}

void __fastcall Read_(__int64 address, __int64 buffer, int size)
{
	if (!IsValid(address))return;
	__try
	{
		ReadProcessMemory((HANDLE)-1, (LPVOID)address, (LPVOID)buffer, size, NULL);
	}
	__except (0) { return; }
}
void __fastcall Write_(__int64 address, __int64 buffer, int size)
{
	if (!IsValid(address))return;
	__try
	{
		WriteProcessMemory((HANDLE)-1, (LPVOID)address, (LPVOID)buffer, size, NULL);
	}
	__except (0) { return; }
}

string  __fastcall _CProcess::StringToUtf8(string str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}