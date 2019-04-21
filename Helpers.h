#pragma once
#include "stdafx.h"

class StoT
{
public:
	StoT(const wstring& str) {
		new (this)StoT(str.c_str());
	}
	StoT(const string& str) {
		new (this)StoT(str.c_str());
	}
	StoT(const char* str) : m_lpw(NULL), m_lpc(NULL) {
		if (str) {
			size_t len = strlen(str);
			int wlen = MultiByteToWideChar(CP_ACP, NULL, str, (int)len, NULL, NULL);
			m_lpw = new wchar_t[wlen + 1];
			MultiByteToWideChar(CP_ACP, 0, str, (int)len, m_lpw, wlen);
			m_lpw[wlen] = 0; len = strlen(str) + 1; m_lpc = new char[len]; m_Len = len; m_Size = len * sizeof(char); strcpy_s(m_lpc, len, str);
		}
	}
	StoT(const wchar_t* str) : m_lpw(NULL), m_lpc(NULL) {
		if (str) {
			size_t len = wcslen(str); int clen = WideCharToMultiByte(CP_ACP, NULL, str, (int)len, NULL, NULL, NULL, NULL); m_lpc = new char[clen + 1]; WideCharToMultiByte(CP_ACP, 0, str, (int)len, m_lpc, clen, NULL, NULL); m_lpc[clen] = 0; len = wcslen(str) + 1; m_lpw = new wchar_t[len]; m_Len = len; m_Size = len * sizeof(wchar_t); wcscpy_s(m_lpw, len, str);
		}
	}
	~StoT() {
		if (m_lpc) {
			delete[] m_lpc;
		}
		if (m_lpw) {
			delete[] m_lpw;
		}
	}
#if (defined(_UNICODE) || defined(UNICODE))
	const wchar_t* GetCT()
	{
		return m_lpw;
	}
#else
	const char* GetCT()
	{
		return m_lpc;
	}
#endif
	const char* GetCA()
	{
		return m_lpc;
	}
	const wchar_t* GetCW()
	{
		return m_lpw;
	}
	ULONG GetLen() {
		return m_Len;
	}
	ULONG GetSize() {
		return m_Size;
	}
private:
	wchar_t* m_lpw;
	char* m_lpc;
	ULONG m_Len;
	ULONG m_Size;
};

namespace utils {
	template <int X> struct EnsureCompileTime {
		enum : int {
			Value = X
		};
	};

	//Use Compile-Time as seed
#define compile_seed (	(__TIME__[7] - '0') * 1  + (__TIME__[6] - '0') * 10		+	\
						(__TIME__[4] - '0') * 60   + (__TIME__[3] - '0') * 600	+	\
						(__TIME__[1] - '0') * 3600 + (__TIME__[0] - '0') * 36000	)

	constexpr int LinearCongruentGenerator(int Rounds) {
		return 1013904223 + 1664525 * ((Rounds > 0) ? LinearCongruentGenerator(Rounds - 1) : compile_seed & 0xFFFFFFFF);
	}

#define Random() EnsureCompileTime<LinearCongruentGenerator(10)>::Value //10 Rounds
#define RandomNumber(Min, Max) (Min + (Random() % (Max - Min + 1)))

	template <int... Pack> struct IndexList {};

	template <typename IndexList, int Right> struct Append;
	template <int... Left, int Right> struct Append<IndexList<Left...>, Right> {
		typedef IndexList<Left..., Right> Result;
	};

	template <int N> struct ConstructIndexList {
		typedef typename Append<typename ConstructIndexList<N - 1>::Result, N - 1>::Result Result;
	};

	template <> struct ConstructIndexList<0> {
		typedef IndexList<> Result;
	};

	template <typename Char, typename IndexList> class XorStringT;
	template <typename Char, int... Index> class XorStringT<Char, IndexList<Index...> > {
	private:
		Char Value[sizeof...(Index)+1];

		static const Char XORKEY = static_cast<Char>(RandomNumber(0, 0xFFFF));

		template <typename Char>
		constexpr Char EncryptCharacterT(const Char Character, int Index) {
			return Character ^ (XORKEY + Index);
		}

	public:
		__forceinline constexpr XorStringT(const Char* const String)
			: Value{ EncryptCharacterT(String[Index], Index)... } {}

		const Char *decrypt() {
			for (int t = 0; t < sizeof...(Index); t++) {
				Value[t] = Value[t] ^ (XORKEY + t);
			}

			Value[sizeof...(Index)] = static_cast<Char>(0);

			return Value;
		}

		const Char *get() {
			return Value;
		}
	};

#define XORSTR( String ) ( utils::XorStringT<char, utils::ConstructIndexList<sizeof( String ) - 1>::Result>( String ).decrypt() )
#define XORWSTR( String ) ( utils::XorStringT<wchar_t, utils::ConstructIndexList<(sizeof( String ) - 1) / 2>::Result>( String ).decrypt() )
}
namespace Helpers
{
	std::string VariableText(char* format, ...);
	void LogAddress(char* szName, int64_t iAddress);
	void LogFloat(char* szName, float fValue);
	void LogError(char* szMessage);
	void Log(const char* szMessage);
	void LogChar(char szMessage);
	void LogInt(char* szMessage, int iAdress);
	void LogString(char* szName, std::string sValue);

	inline void**& getvtable(void* inst, size_t offset = 0)
	{
		return *reinterpret_cast<void***>((size_t)inst + offset);
	}

	inline const void** getvtable(const void* inst, size_t offset = 0)
	{
		return *reinterpret_cast<const void***>((size_t)inst + offset);
	}

	template< typename Fn >
	inline Fn getvfunc(const void* inst, size_t index, size_t offset = 0)
	{
		return reinterpret_cast<Fn>(getvtable(inst, offset)[index]);
	}

	template< typename T > inline T* makeptr(void* ptr, int offset)
	{
		return reinterpret_cast<T*>((size_t)ptr + offset);
	}
	template< typename T > inline T* makeptr(DWORD ptr, int offset)
	{
		return reinterpret_cast<T*>((size_t)ptr + offset);
	}
}