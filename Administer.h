#pragma once

#define Administer _Administer::Instance()
class _Administer
{
 public:
	void __fastcall StartThreadManager();
	static _Administer& Instance() {
		static _Administer _Handle;
		return _Handle;
	}
// 	static void __fastcall ThreadOperation();
 	HANDLE hManager;
 	HANDLE hThreadOperation;
 	static void __fastcall ThreadManager();
};

