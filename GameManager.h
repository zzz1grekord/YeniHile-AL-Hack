#pragma once

#define GameView _GameView::Instance()
struct _GameView
{
	__int64 pAddr;
	Vector3 m_Pos;
	XMMATRIX m_Matrix;
	bool __fastcall WorldToScreen(Vector3 Position, ImVec2 &DrawPosition);
	bool __fastcall WorldToScreen(Vector3 Position, Vector3 &DrawPosition);
	_GameView()
	{
		pAddr = 0;
		m_Pos = Vector3(0, 0, 0);
		m_Matrix = XMMATRIX(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}
	static _GameView& Instance() {
		static _GameView _Handle;
		return _Handle;
	}
};

struct cplane_t
{
	Vector3			surfaceNormal;			//0x0000
	float			dist;					//0x000C
}; //0x0010

struct csurface_t
{
	const char*		name;					//0x0000
	short			surfaceProp;			//0x0008
	unsigned short	flags;					//0x000A
}; //0x0010 (aligned)

struct trace_t
{
	Vector3			start;						//0x0000
	int				_0x000C;					//0x000C
	Vector3			endpos;						//0x0010
	char			_unk0x001C[0x4];			//0x001C
	cplane_t		plane;						//0x0020
	float			fraction;					//0x0030
	int				contents;					//0x0034
	bool			allSolid;					//0x0038
	bool			startSolid;					//0x0039
	char			_unk0x003A[0x6];			//0x003A
	csurface_t		surface;					//0x0040
	char			_unk0x0050[0x4];			//0x0050
	int				hitgroup;					//0x0054
	short			physicsBone;				//0x0058
	char			_unk0x005A[0x6];			//0x005A
	int64_t			m_pEnt;					//0x0060
	int				hitbox;						//0x0068
	char			_unk0x006C[0x114];			//0x006C
};

struct WeaponInfo
{
	__int64 pAddr;//基指针
	string Name;//名字
	int Ammo;
	float Speed;
	int AmmoSurplus;
};
struct LootInfo
{
	Vector3 Pos;
	int size;
	LootInfo()
	{
		Pos=Vector3();
		size = 0;
	}
};

struct DrawEntity
{
	__int64 pAddr;//基指针
	int ID;
	WeaponInfo Weapon;
	__int64 pHAddr;//血量指针
	string Name;//名字
	string Hero;
	__int64 pBPos[15];
	int Col;
	int Team;
	ID3D11ShaderResourceView*	pSBuf;

	bool __fastcall IsDead(__int64 = 0);
	bool __fastcall IsbKneelDown(__int64 = 0);
	bool __fastcall IsTeam();
	bool __fastcall GetHealth(float &, float &, __int64 = 0);
	bool __fastcall GetShield(float &, float &, __int64 = 0);
	Vector3 __fastcall GetMinPos(__int64 = 0);
	Vector3 __fastcall GetTopPos(__int64 = 0);
	bool __fastcall DrawBones(_GameView, Vector3&, int = 0, float = 1.0f);
	void __fastcall GetClosestPlayerToCrossHair(Vector3 AimPos, float &max);
	void __fastcall DrawInfo(ImVec2 dpos, int Dis, int color = 0, bool DrawName = 0, bool = 0, bool DrawDis = 0);
	DrawEntity()
	{
		pAddr = 0;
		ID = 0;
		pHAddr = 0;
		Name = "null";
		Hero = "null";
		Col = 0;
		Team = 0;
	}
};
typedef HRESULT(__stdcall *D3D11PresentHook) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
class GameManager
{
public:
	static D3D11PresentHook phookD3D11Present;

	static bool __fastcall HookInt(int64_t=0);
	static bool __fastcall SpeedInt(bool, int);

	static __int64 __fastcall GetEntityList();
	static DrawEntity __fastcall GetLocalPlayer();

	static _GameView rView;
	static _GameView __fastcall GetView();
	static void __fastcall ReadEntity(__int64);

	static void __fastcall rEntity(__int64);
	static void __fastcall GameAimBot();
};




