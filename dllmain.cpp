// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "Process.h"

extern HRESULT __stdcall MyPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);



CHAR szUserName[255] = { 0 };

CHAR szPassWord[255] = { 0 };

HANDLE mTimer = NULL;
HANDLE mTimerQueue = NULL;

extern BOOL isLogin;

extern DWORD szTime;

void __stdcall CheckTimer(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{

	TimeServer();

}


void __stdcall MainTimer(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{
	VMProtectBegin(__FUNCTION__);

	CHAR szMessage[255] = { 0 };

	GetPrivateProfileStringA(XORSTR("Soft_Config"), XORSTR("username"), "", szUserName, 255, XORSTR("C:\\FL.ini"));

	GetPrivateProfileStringA(XORSTR("Soft_Config"), XORSTR("password"), "", szPassWord, 255, XORSTR("C:\\FL.ini"));

	if (ConnectServer())
	{
		if (InitServer(2))
		{
			if (LoginServer(szUserName, szPassWord, szMessage))
			{

				if (ApiServer())
				{
					isLogin = TRUE;

					mTimerQueue = CreateTimerQueue();
					//_beginthread((_beginthread_proc_type)CheckTimer, 0, NULL);
					CreateTimerQueueTimer(&mTimer, mTimerQueue, (WAITORTIMERCALLBACK)CheckTimer, NULL, 1, NULL, NULL);
					CProcess.GetTargetProcessId(XORSTR("r5apex.exe"));
					while (CProcess.pId == 0)
					{
						CProcess.GetTargetProcessId(XORSTR("r5apex.exe"));
					}

					while (true)
					{
						CProcess.pWinhWnd = CProcess.GetTargethWnd(CProcess.GetTargetProcessId(CProcess.pName), XORSTR("Respawn001"), NULL);//获取窗口句柄
						if (CProcess.pWinhWnd != NULL)break;
					}

					Renderer.Initialize();
					Input.StartSetWindowWndProc();
					if (!GameManager::HookInt(CProcess.GetModuleBase(XORSTR("IGO64.dll")))) ExitProcess(0);
					CProcess._pBase = CProcess.GetModuleBase(XORSTR("r5apex.exe"));
					Administer.ThreadManager();
				}


			}
		}
	}
	VMProtectEnd;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	VMProtectBegin(__FUNCTION__);
	HANDLE mTimer = NULL;
	HANDLE mTimerQueue = NULL;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//AllocConsole(); // 控制台
		//freopen("CONIN$", "r", stdin); //控制台
		//freopen("CONOUT$", "w", stdout);
		mTimerQueue = CreateTimerQueue();
		CreateTimerQueueTimer(&mTimer, mTimerQueue, (WAITORTIMERCALLBACK)MainTimer, NULL, 1, NULL, NULL);
		//_beginthread((_beginthread_proc_type)MainTimer, 0, NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
	VMProtectEnd;
}