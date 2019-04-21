#include "stdafx.h"


CHAR szID[256] = { 0 };

DWORD isDbg = 0;

SOCKET m_Socket;

#define MAX_BUF_SIZE 1024

CHAR szUser[255] = { 0 };

//CHAR szTime[255] = { 0 };

DWORD szTime = 0;

CHAR szNotice[255] = { 0 };

BOOL isLogin = FALSE;



BOOL GetHDID(PCHAR pIDBufer)
{
	VMProtectBegin(NULL);

		HKEY hkey;
		LPCTSTR data_set = _T("SOFTWARE\\Microsoft\\Cryptography");

		if (ERROR_SUCCESS == ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_set, 0, KEY_READ, &hkey))
		{
			

			DWORD dwSzType = REG_SZ;
			DWORD dwSize = sizeof(szID);
			if (::RegQueryValueEx(hkey, _T("MachineGuid"), 0, &dwSzType, (LPBYTE)&szID, &dwSize) != ERROR_SUCCESS)
			{
				return FALSE;
			}

			
			
			
			return TRUE;
		}

		::RegCloseKey(hkey);

		return FALSE;

		VMProtectEnd();
	
}

BOOL GetProcessIDFromName(char *name)
{
	VMProtectBegin(NULL);

	HANDLE snapshot;
	PROCESSENTRY32 processinfo;
	processinfo.dwSize = sizeof(processinfo);
	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == NULL)
		return FALSE;

	BOOL status = Process32First(snapshot, &processinfo);
	while (status)
	{
		if (_stricmp(name, processinfo.szExeFile) == 0)
			return TRUE;
		status = Process32Next(snapshot, &processinfo);
	}

	VMProtectEnd();


	return FALSE;


}

CHAR* urlopen(CHAR* url)
{
	HINTERNET hSession = InternetOpen("UrlTest", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession != NULL)
	{
		HINTERNET hHttp = InternetOpenUrl(hSession, url, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (hHttp != NULL)
		{
			//wprintf_s(_T("%s\n"), url);
			CHAR *Temp = new CHAR[MAX_BUF_SIZE];
			ULONG Number = 1;
			while (Number > 0)
			{
				InternetReadFile(hHttp, Temp, MAX_BUF_SIZE - 1, &Number);
				Temp[Number] = '\0';
				return Temp;
			}
			InternetCloseHandle(hHttp);
			hHttp = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	}

	return NULL;
}

BOOL WinSockInit()
{

	WSADATA data = { 0 };
	if (WSAStartup(MAKEWORD(2, 2), &data))
		return FALSE;
	if (LOBYTE(data.wVersion) != 2 || HIBYTE(data.wVersion) != 2) {
		WSACleanup();
		return FALSE;
	}
	return TRUE;
}

BOOL SOCKET_Select(SOCKET hSocket, int nTimeOut, BOOL bRead)
{
	fd_set fdset;
	timeval tv;
	FD_ZERO(&fdset);
	FD_SET(hSocket, &fdset);
	nTimeOut = nTimeOut > 1000 ? 1000 : nTimeOut;
	tv.tv_sec = 0;
	tv.tv_usec = nTimeOut;

	int iRet = 0;
	if (bRead) {
		iRet = select(0, &fdset, NULL, NULL, &tv);
	}
	else {
		iRet = select(0, NULL, &fdset, NULL, &tv);
	}

	if (iRet <= 0) {
		return FALSE;
	}
	else if (FD_ISSET(hSocket, &fdset)) {
		return TRUE;
	}
	return FALSE;
}

BOOL ConnectServer()
{

	VMProtectBegin(NULL);

	WinSockInit();

	m_Socket = INVALID_SOCKET;
	m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_Socket == INVALID_SOCKET)
	{
		return TRUE;
	}
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(6901);/////服务器端口号
	//server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(m_Socket, (struct sockaddr *)&server, sizeof(struct sockaddr)) == SOCKET_ERROR)
	{
		closesocket(m_Socket);
		WSACleanup();
		return TRUE;
	}




	VMProtectEnd();

	return TRUE;

}

DWORD WINAPI myExitThread(LPVOID lPARAM)
{
	Sleep(3000); //信息框时间 3000为3秒

	ExitProcess(0);

	return 0;
}

BOOL TimeServer()
{
	VMProtectBegin(NULL);


	DWORD dwLast = 0;

	while (1)
	{
		dwLast = dwLast + 1;


		if (dwLast > szTime)
		{
			if (isLogin)
			{
				isLogin = FALSE;

				MessageBoxA(0, "账号已到期", "Message", 0);

				break;
			}
		}

			
		Sleep(1000);  //效验时间
			
		
		}



	return 0;
	VMProtectEnd;
}

//BOOL ReguserServer(LPCSTR UserName, LPCSTR PassWord, LPCSTR UserCard, CHAR *szMesasge)
//{
//	VMProtectBegin(NULL);
//
//	CHAR szSend[255] = { 0 };
//
//	sprintf(szSend, "Reguser@%s@%s@%s", UserName, PassWord, UserCard);
//
//	if (SOCKET_Select(m_Socket, 100, FALSE))
//	{
//		send(m_Socket, szSend, strlen(szSend), 0);
//
//		while (!SOCKET_Select(m_Socket, 100, TRUE))
//		{
//			CHAR szBuf[MAX_BUF_SIZE] = { 0 };
//
//			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
//			if (iRet > 0)
//			{
//
//				strcpy(szMesasge, &szBuf[4]);
//
//				break;
//			}
//
//		}
//
//	}
//
//	VMProtectEnd();
//
//	return FALSE;
//
//}
//
//BOOL PrepaidServer(LPCSTR UserName, LPCSTR UserCard, CHAR *szMesasge)
//{
//	VMProtectBegin(NULL);
//
//	CHAR szSend[255] = { 0 };
//
//	sprintf(szSend, "Prepaid@%s@%s", UserName, UserCard);
//
//	if (SOCKET_Select(m_Socket, 100, FALSE))
//	{
//		send(m_Socket, szSend, strlen(szSend), 0);
//
//		while (!SOCKET_Select(m_Socket, 100, TRUE))
//		{
//			CHAR szBuf[MAX_BUF_SIZE] = { 0 };
//
//			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
//
//			if (iRet > 0)
//			{
//
//				strcpy(szMesasge, &szBuf[4]);
//
//				break;
//			}
//
//		}
//
//	}
//
//	VMProtectEnd();
//
//	return FALSE;
//
//}
//
//BOOL UnbindServer(LPCSTR UserName, LPCSTR PassWord, CHAR *szMesasge)
//{
//	VMProtectBegin(NULL);
//
//	CHAR szSend[255] = { 0 };
//
//	sprintf(szSend, "Unbind@%s@%s", UserName, PassWord);
//
//	if (SOCKET_Select(m_Socket, 100, FALSE))
//	{
//		send(m_Socket, szSend, strlen(szSend), 0);
//
//		while (!SOCKET_Select(m_Socket, 100, TRUE))
//		{
//			CHAR szBuf[MAX_BUF_SIZE] = { 0 };
//
//			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
//			if (iRet > 0)
//			{
//
//				strcpy(szMesasge, &szBuf[4]);
//
//				break;
//			}
//
//		}
//
//	}
//
//	VMProtectEnd();
//
//	return FALSE;
//
//}

BOOL InitServer(DWORD dwVersion)
{
	VMProtectBegin(NULL);

	CHAR szSend[255] = { 0 };

	sprintf(szSend, "Init@%d", dwVersion);

	if (SOCKET_Select(m_Socket, 100, FALSE))
	{
		send(m_Socket, szSend, strlen(szSend), 0);

		while (!SOCKET_Select(m_Socket, 100, TRUE))
		{
			CHAR szBuf[MAX_BUF_SIZE] = { 0 };

			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
			if (iRet > 0)
			{

				strcpy(szNotice, &szBuf[4]);

				if (szBuf[0] == 1)
				{
					return TRUE;
				}

				break;
			}

		}

	}

	VMProtectEnd();

	return FALSE;

}

BOOL ApiServer()
{
	VMProtectBegin(NULL);

	CHAR szSend[255] = { 0 };

	DWORD dwAddr = (DWORD)malloc(5);

	DWORD dwCheck = dwAddr + 10086;

	dwCheck = dwCheck ^ 2019;
		
	dwCheck = dwCheck + 520 - 456 * 4;

	sprintf(szSend, "GetAddr@%d", dwAddr);

	if (SOCKET_Select(m_Socket, 100, FALSE))
	{
		send(m_Socket, szSend, strlen(szSend), 0);

		while (!SOCKET_Select(m_Socket, 100, TRUE))
		{
			CHAR szBuf[MAX_BUF_SIZE] = { 0 };

			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
			if (iRet > 0)
			{
				if (szBuf[0] == 1)
				{
					
					if (*(DWORD*)&szBuf[4] == dwCheck)
					{

						//CreateThread(NULL, NULL, TimeServer, NULL, NULL, NULL);

						//Game::gPresent = 0x162AA0;
						//Game::gEntityList = 0x1F6CAB8;

						//Game::gPresent = *(DWORD*)&szBuf[8];

						//*(DWORD*)Game::gEntityList = *(DWORD*)&szBuf[16];

						return TRUE;

					}

					break;




				}
			}

		}

	}

	VMProtectEnd();

	return FALSE;
}

BOOL LoginServer(LPCSTR UserName, LPCSTR PassWord, CHAR *szMessage)
{

	VMProtectBegin(NULL);

	CHAR szSend[255] = { 0 };

	ULONG64 dwRand = (DWORD)malloc(5);

	ULONG64 dwCheck = dwRand ^ 521314;

	dwCheck = dwCheck + 123 - 520 * 2;

	if (IsDebuggerPresent())
	{
		isDbg = 888;
	}

	if (GetProcessIDFromName("x64dbg.exe"))
	{
		isDbg = 888;
	}

	if (GetProcessIDFromName("e.exe"))
	{
		isDbg = 888;

	}
	if (GetProcessIDFromName("e1.exe"))
	{
		isDbg = 888;

		if (GetProcessIDFromName("dbg.exe"))
		{
			isDbg = 888;

		}
		if (GetProcessIDFromName("od.exe"))
		{
			isDbg = 888;

		}
		if (GetProcessIDFromName("64调试器.exe"))
		{
			isDbg = 888;

		}
		if (GetProcessIDFromName("调试器.exe"))
		{
			isDbg = 888;

		}
	}
	
	GetHDID(szID);

	//MessageBox(0, szID, 0, 0);

	DWORD ConnectAddr = (DWORD)GetProcAddress(GetModuleHandle("ws2_32.dll"), "connect");

	DWORD OldProtect;

	//VirtualProtect((LPVOID)ConnectAddr, 5, PAGE_EXECUTE_READWRITE, &OldProtect);

	//BYTE ConnectByte;

	//ReadProcessMemory(GetCurrentProcess(), (LPVOID)ConnectAddr, &ConnectByte, 1, NULL);

	//if (ConnectByte != 0x8B)
	//{
	//	isDbg = 888;
	//}



	sprintf(szSend, "Login@%s@%s@%s@%d@%d", UserName, PassWord, szID, dwRand, isDbg);


	if (SOCKET_Select(m_Socket, 100, FALSE))
	{
		send(m_Socket, szSend, strlen(szSend), 0);

		while (!SOCKET_Select(m_Socket, 100, TRUE))
		{
			CHAR szBuf[MAX_BUF_SIZE] = { 0 };

			int iRet = recv(m_Socket, (char *)szBuf, MAX_BUF_SIZE, 0);
			if (iRet > 0)
			{
				if (szBuf[0] == 1)
				{
					if (*(DWORD*)&szBuf[4] == dwCheck)
					{

						strcpy(szUser, UserName);

						//strcpy(szTime, &szBuf[8]);

						szTime = *(DWORD*)&szBuf[8];

						return TRUE;
					}
				}
				else
				{
					strcpy(szMessage, &szBuf[4]);
				}

				break;
			}

		}

	}

	VMProtectEnd();


	return FALSE;
}


