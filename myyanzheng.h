#pragma once

#include <Windows.h>

#include <stdio.h>

#include "VMProtectSDK.h"

#include <TlHelp32.h>

#include <WinInet.h>

#pragma comment(lib,"wininet.lib")

#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")

#include <Iphlpapi.h>

#pragma comment( lib,"Iphlpapi.lib" )


void GetNetCardID();

BOOL GetProcessIDFromName(char *name);

CHAR* urlopen(CHAR* url);

BOOL WinSockInit();

BOOL SOCKET_Select(SOCKET hSocket, int nTimeOut, BOOL bRead);

BOOL ConnectServer();

DWORD WINAPI myExitThread(LPVOID lPARAM);

BOOL TimeServer();

BOOL ReguserServer(LPCSTR UserName, LPCSTR PassWord, LPCSTR UserCard, CHAR *szMesasge);

BOOL PrepaidServer(LPCSTR UserName, LPCSTR UserCard, CHAR *szMesasge);

BOOL UnbindServer(LPCSTR UserName, LPCSTR PassWord, CHAR *szMesasge);

BOOL InitServer(DWORD dwVersion);

BOOL ApiServer();

BOOL LoginServer(LPCSTR UserName, LPCSTR PassWord, CHAR *szMessage);

BOOL GetHDID(PCHAR pIDBufer);




