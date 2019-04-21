#pragma once

//#define _VM

//#define _TMD

#ifdef _TMD
#define VMPBegin(x) VM_TIGER_BLACK_START
#define VMPEnd() VM_TIGER_BLACK_END
#else
#ifdef _VM
#define VMPBegin(x)	VMProtectBeginUltra(x)
#define VMPEnd 	VMProtectBeginUltra
#else
#define VMPBegin(x)
#define VMPEnd()
#endif
#endif

#ifdef _WIN64
#define PTRMAXVAL (0x000F000000000000)
#else
#define PTRMAXVAL (0xFFF00000)
#endif

#define IsValid(x) ( ((x >= 0x400000) && (x < PTRMAXVAL)) ?true:false )

#define _TRY try{
#define _CATCH }catch (...){Helpers::Log(Helpers::VariableText("º¯Êý %s Î´ÖªÒì³£!", __FUNCTION__).c_str());}

template <class T> T
extern __fastcall Read(__int64);
template <class T> bool
extern __fastcall Write(__int64, T);
extern void __fastcall Read_(__int64, __int64, int);
extern void __fastcall Write_(__int64, __int64, int);

#define CProcess _CProcess::Instance()
class _CProcess
{
public:
	__int64 _pBase;
	HANDLE _Device;
	__int64 __fastcall GetProcessBase();
	__int64 __fastcall GetModuleBase(const char*);

	int __fastcall GetTargetProcessId(const char*);
	HWND __fastcall GetTargethWnd(int = NULL, const char* = NULL, const char* = NULL);

	string __fastcall StringToUtf8(string str);

	static _CProcess& Instance() {
		static _CProcess _Handle;
		return _Handle;
	}
public:
	_CProcess() {
		pName = "";
		pId = 0;
		_pBase = 0;
		_Device = INVALID_HANDLE_VALUE;
	}
	HWND pWinhWnd;
	int pId;
	const char*  pName;
};

template <class T> T
__fastcall Read(__int64 address)
{
	if (!IsValid(address))return T();
	T value;
	__try
	{
		ReadProcessMemory((HANDLE)-1, (LPVOID)address, &value, sizeof(T), NULL);
		return value;
	}
	__except (0) { return T(); }
}

template <class T>
bool __fastcall Write(__int64 address, T ValueToWrite)
{
	if (!IsValid(address))return false;
	T value;
	__try
	{
	return WriteProcessMemory((HANDLE)-1, (LPVOID)address, &ValueToWrite, sizeof(T), NULL);
	}
	__except (0) { return false; }
}
