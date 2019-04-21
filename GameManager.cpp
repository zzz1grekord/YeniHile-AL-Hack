#include "stdafx.h"
#include "GameManager.h"
namespace  _Bone
{
	
	int Bone_medium_bloodhound[15] = { 12, 9,7,14, 18, 28,47, 51, 58,88, 89, 91,93, 94, 96 };
	int Bone_medium_bloodhound1[15] = { 12, 9,7, 14, 18, 21,	40, 44, 47, 65, 66, 68, 70, 71, 73 };
	int Bone_medium_bloodhound2[15] = { 12, 9,7, 14, 17, 20, 39, 42, 45,63, 64, 66, 68, 69, 71 };

	int Bone_heavy_gibraltar[15] = { 12, 9,7, 14, 18, 21, 41, 45, 48,72, 73, 75, 77, 78, 80 };
	int Bone_heavy_gibraltar2[15] = { 12, 9,7,	14, 17, 20,40, 43, 46,64, 65, 67,69, 70, 72 };

	int Bone_light_support[15] = { 12, 9,7,	14, 17, 20,39, 42, 45,63, 64, 66,68, 69, 71 };

	int Bone_heavy_pathfinder[15] = { 10, 9, 7,	14, 16, 17,27, 29, 30,66, 67, 68,70, 71, 72 };
	int Bone_heavy_pathfinder1[15] = { 10, 9, 7,	14, 17, 19,27, 30, 32,68, 69, 70,72, 73, 74 };
	int Bone_heavy_pathfinder2[15] = { 10, 9, 7,	14, 17, 19,27, 29, 31,67, 68, 69,71, 72, 73 };

	int Bone_light_wraith[15] = { 10, 9, 7,	14, 17, 20,39, 42, 45,91, 92, 94,96, 97, 99 };
	int Bone_light_wraith1[15] = { 10, 9, 7,	14, 17, 20,39, 42, 45,79, 80, 82,84, 85, 87 };
	int Bone_light_wraith2[15] = { 10, 9, 7,	14, 16, 19,38, 40, 42,60, 61, 63,65, 66, 68 };

	int Bone_medium_bangalore[15] = { 12, 9,7,	14, 17, 20,43, 46, 49,81, 82, 84,86, 87, 89 };
	int Bone_medium_bangalore1[15] = { 12, 9,7,	14, 16, 18,41, 43, 45,77, 78, 80,82, 83, 85 };
	int Bone_medium_bangalore2[15] = { 12, 9,7,	14, 17, 19,42, 45, 47,79, 80, 82,84, 85, 87 };

	int Bone_heavy_caustic[15] = { 10, 9, 7,	14, 16, 19,38, 40, 43,74, 75, 77,79, 80, 82 };
	int Bone_heavy_caustic1[15] = { 10, 9, 7,	14, 17, 20,39, 42, 45,72, 73, 75,77, 78, 80 };
	int Bone_heavy_caustic2[15] = { 10, 9, 7,	14, 16, 18,37, 39, 41,60, 61, 62,64, 65, 66 };

	int Bone_medium_holo[15] = { 10, 9, 7,	14, 16, 19,41, 43, 46,84, 85, 87,89, 90, 92 };
	int Bone_medium_holo1[15] = { 10, 9, 7,	21, 24, 27,46, 49, 52,78, 79, 81,83, 84, 86 };
	int Bone_medium_holo2[15] = { 10, 9, 7,	14, 17, 20,42, 45, 48,69, 70, 72,74, 75, 77 };

	int Bone_medium_stim[15] = { 12, 9,7,	15, 17, 20,43, 46, 49,81, 82, 83,85, 86, 87 };
	int Bone_medium_stim1[15] = { 12, 9,7,	15, 17, 20,43, 46, 49,81, 82, 83,85, 86, 87 };
	int Bone_medium_stim2[15] = { 12, 9,7,	15, 17, 20,43, 46, 49,81, 82, 83,85, 86, 87 };


};

DrawEntity ToAimBot;
bool isAimBot;
DrawEntity Local = DrawEntity();
bool __fastcall GetAimKey()
{
	if (AimBot->iKey == 2)
	{
		return   GetAsyncKeyState(5);
	}
	if (AimBot->iKey == 3)
	{
		return   GetAsyncKeyState(6);
	}
	if (AimBot->iKey == 4)
	{
		return   GetAsyncKeyState(84);
	}
	if (AimBot->iKey == 5)
	{
		return   GetAsyncKeyState(70);
	}
	return   GetAsyncKeyState(AimBot->iKey + 1);
}

bool __fastcall GetAimKey2()
{
	if (AimBot->iKey2 == 2)
	{
		return   GetAsyncKeyState(5);
	}
	if (AimBot->iKey2 == 3)
	{
		return   GetAsyncKeyState(6);
	}
	if (AimBot->iKey2 == 4)
	{
		return   GetAsyncKeyState(84);
	}
	if (AimBot->iKey2 == 5)
	{
		return   GetAsyncKeyState(70);
	}
	return   GetAsyncKeyState(AimBot->iKey2 + 1);
}

bool __fastcall GetSpeedKey()
{
	ImGuiIO io = ImGui::GetIO();
	if (AimBot->iSKey == 0)
	{
		return  io.KeysDown[VK_SHIFT];
	}
	if (AimBot->iSKey == 2)
	{
		return   io.KeysDown[VK_CONTROL];
	}
	if (AimBot->iKey == 2)
	{
		return  io.MouseDown[4];
	}
	if (AimBot->iKey == 3)
	{
		return  io.MouseDown[5];
	}
	if (AimBot->iSKey == 4)
	{
		return   io.KeysDown[84];
	}
	if (AimBot->iSKey == 5)
	{
		return    io.KeysDown[70];
	}
}

#define M_PI       3.14159265358979323846   // pi
Vector3 __fastcall CalcAngles(Vector3 vOrigin, Vector3 aimPoint)
{
	Vector3   angles;
	aimPoint = aimPoint - vOrigin;
	XMVECTOR u = XMVector3Normalize(XMVectorSet(aimPoint.x, aimPoint.y, aimPoint.z, 0.0f));
	angles.x = 90 - atan2(u.m128_f32[0], u.m128_f32[1]) / (M_PI / 180);
	XMVECTOR l = XMVector2Length(XMVectorSet(u.m128_f32[0], u.m128_f32[1], 0.0f, 0.0f));
	angles.y = atan2(u.m128_f32[2], l.m128_f32[0]) / (M_PI / 180)*-1;
	return angles;
}

__int64 __fastcall GameManager::GetEntityList()
{
	//VMProtectBegin(__FUNCTION__);//(已经被_Administer::ThreadManager占用)
	return ((int)Game::gEntityList + CProcess._pBase);
	//VMProtectEnd;
}
D3D11PresentHook  GameManager::phookD3D11Present = NULL;
extern HRESULT __stdcall MyPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
bool __fastcall GameManager::HookInt(int64_t DxBase)
{
	//VMProtectBegin(__FUNCTION__);/*（已经被_Input::StartSetWindowWndProc()占用）*/
	if (!IsValid(DxBase))return false;
	if (!phookD3D11Present)phookD3D11Present = (D3D11PresentHook)Read<__int64>(DxBase + (int)Game::gPresent);
	Write<int64_t>(DxBase + (int)Game::gPresent, (int64_t)MyPresent);
	return true;
	//VMProtectEnd;
}

__int64 HookSpeedViodAddress = 0;
bool bSpeed = false;
//bool __fastcall GameManager::SpeedInt(bool B, int a)
//{
//	VMProtectBegin(__FUNCTION__);
//	if (!IsValid(CProcess._pBase))return false;
//	HookSpeedViodAddress = CProcess._pBase + (int)Game::gVoidMemory;
//	if (!bSpeed)
//	{
//		byte ByteAddress[83] = { 0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//			0x48,0x3B,0x44,0x24,0x30,
//			0x74, 0x0C,
//			0x48, 0xB8,0, 0, 0, 0, 0, 0, 0, 0,
//			0xFF, 0xE0,
//			0x48, 0xB8,0, 0, 0, 0, 0, 0, 0, 0,
//			0x48, 0x89, 0x44, 0x24, 0x30,
//			0xEB, 0xE3,
//			0x48, 0xB8,0, 0, 0, 0, 0, 0, 0, 0,
//			0x0F, 0x28, 0xC8,
//			0x80, 0x38, 0x01,
//			0x74, 0x0c,
//			0x48, 0xB8,0, 0, 0, 0, 0, 0, 0, 0,
//			0xFF, 0xE0,
//			0xF2, 0x0F, 0x58, 0x48, 0x10,
//			0xEB, 0xED };
//
//		*PLONG64(ByteAddress + 2) = CProcess._pBase + (int)Game::gGameSpeedRSP;
//		*PLONG64(ByteAddress + 19) = (DWORD64)GetProcAddress(GetModuleHandleA("kernel32.dll"), "QueryPerformanceCounter");
//		*PLONG64(ByteAddress + 31) = HookSpeedViodAddress + 0x2e;
//		*PLONG64(ByteAddress + 48) = HookSpeedViodAddress + 0xa0;
//		*PLONG64(ByteAddress + 66) = CProcess._pBase + (int)Game::gGameSpeedRSP + 3;
//
//		Write_(HookSpeedViodAddress, (__int64)&ByteAddress, sizeof(ByteAddress));
//		DWORD old;
//		VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xb0), 8, PAGE_EXECUTE_READWRITE, &old);
//		Write<double>(HookSpeedViodAddress + 0xb0, a*0.01);
//		VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xb0), 8, old, &old);
//		if (B)
//		{
//			Write<__int64>(CProcess._pBase + (int)Game::gGameSpeed, HookSpeedViodAddress);
//		}
//		else
//		{
//			Write<__int64>(CProcess._pBase + (int)Game::gGameSpeed, (DWORD64)GetProcAddress(GetModuleHandleA("kernel32.dll"), "QueryPerformanceCounter"));
//		}
//		bSpeed = true;
//		return true;
//	}
//	if (B)
//	{
//		Write<__int64>(CProcess._pBase + (int)Game::gGameSpeed, HookSpeedViodAddress);
//	}
//	else
//	{
//		Write<__int64>(CProcess._pBase + (int)Game::gGameSpeed, (DWORD64)GetProcAddress(GetModuleHandleA("kernel32.dll"), "QueryPerformanceCounter"));
//	}
//
//	return true;
//
//	VMProtectEnd;
//}


_GameView __fastcall GameManager::GetView()
{
	GameView.pAddr = Read<__int64>(CProcess._pBase + (int)Game::gView);
	GameView.m_Pos = Read<Vector3>(GameView.pAddr + (int)Game::pView_Pos);
	GameView.m_Matrix = Read<XMMATRIX>(GameView.pAddr + (int)Game::pView_Mat);
	GameView.m_Matrix = XMMatrixTranspose(GameView.m_Matrix);
	auto FOV = Read<XMMATRIX>(GameView.pAddr + (int)Game::pView_Fov);
	GameView.m_Matrix = XMMatrixMultiply(GameView.m_Matrix, FOV);
	return GameView;
}

bool __fastcall _GameView::WorldToScreen(Vector3 Position, ImVec2 &DrawPosition)
{
	ImGuiIO& io = ImGui::GetIO();
	if (_isnan(Position.x) || _isnan(Position.y) || _isnan(Position.z))return false;
	float ScreenW = (m_Matrix._13 * Position.x) + (m_Matrix._23* Position.y) + (m_Matrix._33 * Position.z + m_Matrix._43);
	if (ScreenW < 0.0001f)return false;
	float ScreenY = (m_Matrix._12 * Position.x) + (m_Matrix._22 * Position.y) + (m_Matrix._32 * Position.z + m_Matrix._42);
	float ScreenX = (m_Matrix._11 * Position.x) + (m_Matrix._21 * Position.y) + (m_Matrix._31 * Position.z + m_Matrix._41);

	DrawPosition.x = (io.DisplaySize.x / 2) + (io.DisplaySize.x / 2) * ScreenX / ScreenW;
	DrawPosition.y = (io.DisplaySize.y / 2) - (io.DisplaySize.y / 2) * ScreenY / ScreenW;
	return true;
}

bool __fastcall _GameView::WorldToScreen(Vector3 Position, Vector3 &DrawPosition)
{
	ImGuiIO& io = ImGui::GetIO();
	if (_isnan(Position.x) || _isnan(Position.y) || _isnan(Position.z))return false;
	float ScreenW = (m_Matrix._13 * Position.x) + (m_Matrix._23* Position.y) + (m_Matrix._33 * Position.z + m_Matrix._43);
	if (ScreenW < 0.0001f)return false;
	float ScreenY = (m_Matrix._12 * Position.x) + (m_Matrix._22 * Position.y) + (m_Matrix._32 * Position.z + m_Matrix._42);
	float ScreenX = (m_Matrix._11 * Position.x) + (m_Matrix._21 * Position.y) + (m_Matrix._31 * Position.z + m_Matrix._41);

	DrawPosition.x = (io.DisplaySize.x / 2) + (io.DisplaySize.x / 2) * ScreenX / ScreenW;
	DrawPosition.y = (io.DisplaySize.y / 2) - (io.DisplaySize.y / 2) * ScreenY / ScreenW;
	DrawPosition.z = 0;
	return true;
}

bool __fastcall DrawEntity::IsTeam()
{
	return (Team == Local.Team);
}

bool __fastcall DrawEntity::IsDead(__int64 Adds)
{
	if (!IsValid(Adds))
	{
		auto Health = Read<int>(pAddr + (int)ObjectManager::Info_Health);
		auto MaxHealth = Read<int>(pAddr + (int)ObjectManager::Info_HealthMax);
		if (Health == 0 | MaxHealth == 0)return true;
		return  false;
	}
	else
	{
		auto Health = Read<int>(Adds + (int)ObjectManager::Info_Health);
		auto MaxHealth = Read<int>(Adds + (int)ObjectManager::Info_HealthMax);
		if (Health == 0 | MaxHealth == 0)return true;
		return  false;
	}
}

bool __fastcall DrawEntity::IsbKneelDown(__int64 Adds)
{
	if (!IsValid(Adds))
	{
		if (Read<int>(pAddr + (__int64)ObjectManager::Info_Dead) == 2)return true;
		return  false;
	}
	else
	{
		if (Read<float>(Adds + (__int64)ObjectManager::Info_Dead) == 2)return true;
		return  false;
	}
}

bool __fastcall DrawEntity::GetHealth(float &Health, float &MaxHealth, __int64 Adds)
{
	if (!IsValid(Adds))
	{
		Health = Read<int>(pAddr + (int)ObjectManager::Info_Health);
		MaxHealth = Read<int>(pAddr + (int)ObjectManager::Info_HealthMax);
		if (Health == 0 | MaxHealth == 0)return false;
		return  true;
	}
	else
	{
		Health = Read<int>(Adds + (int)ObjectManager::Info_Health);
		MaxHealth = Read<int>(Adds + (int)ObjectManager::Info_HealthMax);
		if (Health == 0 | MaxHealth == 0)return false;
		return  true;
	}
}
bool __fastcall DrawEntity::GetShield(float &Shield, float &MaxShield, __int64 Adds)
{
	if (!IsValid(Adds))
	{
		Shield = Read<int>(pAddr + (int)ObjectManager::Info_Shield);
		MaxShield = Read<int>(pAddr + (int)ObjectManager::Info_ShieldMax);
		if (Shield == 0 | MaxShield == 0)return false;
		return  true;
	}
	else
	{
		Shield = Read<int>(Adds + (int)ObjectManager::Info_Shield);
		MaxShield = Read<int>(Adds + (int)ObjectManager::Info_ShieldMax);
		if (Shield == 0 | MaxShield == 0)return false;
		return  true;
	}
}

Vector3 __fastcall DrawEntity::GetMinPos(__int64 Addr)
{
	if (!IsValid(Addr))
	{
		if (!IsValid(pAddr)) return Vector3();
		auto pos = Read<Vector3>(pAddr + (int)ObjectManager::Info_Pos_Min);
		return pos;
	}
	else
	{
		auto pos = Read<Vector3>(Addr);
		return pos;
	}
}
Vector3 __fastcall DrawEntity::GetTopPos(__int64 Addr)
{
	if (!IsValid(Addr))
	{
		if (!IsValid(pAddr)) return Vector3();
		return Read<Vector3>(pAddr + (int)ObjectManager::Info_Pos_Top);
	}
	else
	{
		return  Read<Vector3>(Addr + (int)ObjectManager::Info_Pos_Top);
	}
}
trace_t __fastcall CalcVisable(Vector3 from, Vector3 to)//可视
{
	trace_t tr;
	ZeroMemory(&tr, sizeof(tr));
	if (!IsValid(CProcess._pBase))return tr;
	//if (*(int*)(CProcess._pBase + (int)Game::gManu) == 3)return tr;
	//((__int64(__fastcall*)(PVOID, PVOID, __int64, PVOID, PVOID, PVOID, PVOID, PVOID, PVOID))(CProcess._pBase + (int)Game::FnVisable))(
	//	&from, &to, 0x640400b, nullptr, nullptr, nullptr, nullptr, &tr, nullptr);//TRACE_MASK_VISIBLE和TRACE_MASK_VISIBLE_AND_NPCS 替换选择可视方式
	return tr;// 可视方式替换到0x640400b  默认的0x640400b是漏哪显哪
}

Vector3 __fastcall GetBonesMatrix(__int64 Adds)
{
	auto form = Read<XMMATRIX>(Adds);
	return Vector3(form._14, form._24, form._34);
}

bool __fastcall DrawEntity::DrawBones(_GameView View, Vector3 &Pos, int color, float thickness)
{
	if (!color)return false;
	Vector3 dPos[15];
	int Col[15];
	int Col2 = color;
	trace_t tr;
	trace_t tr2;
	if (ESP->bBone)
	{
		for (size_t i = 0; i < 15; i++)
		{
			Col[i] = Col2;
			dPos[i] = GetBonesMatrix(this->pBPos[i]);
			dPos[i] += Pos;
			tr2 = CalcVisable(View.m_Pos, dPos[i]);
			if (!View.WorldToScreen(dPos[i], dPos[i]))return false;

			if (tr2.fraction > 0.97f || tr2.m_pEnt == pAddr)
			{
				Col[i] = ImColor(ESP->cTeam);
			}
		}
		Pos = dPos[0];
		color = Col[0];

		Renderer.DrawCircle(ImVec2(dPos[0].x, dPos[0].y), dPos[1].distance(dPos[0]) + 1, Col[0], thickness);

		Renderer.DrawLine(ImVec2(dPos[9].x, dPos[9].y), ImVec2(dPos[3].x, dPos[3].y), Col[1], thickness);
		Renderer.DrawLine(ImVec2(dPos[9].x, dPos[9].y), ImVec2(dPos[12].x, dPos[12].y), Col[2], thickness);
		Renderer.DrawLine(ImVec2(dPos[6].x, dPos[6].y), ImVec2(dPos[12].x, dPos[12].y), Col[3], thickness);
		Renderer.DrawLine(ImVec2(dPos[6].x, dPos[6].y), ImVec2(dPos[3].x, dPos[3].y), Col[4], thickness);

		Renderer.DrawLine(ImVec2(dPos[3].x, dPos[3].y), ImVec2(dPos[4].x, dPos[4].y), Col[5], thickness);
		Renderer.DrawLine(ImVec2(dPos[4].x, dPos[4].y), ImVec2(dPos[5].x, dPos[5].y), Col[6], thickness);

		Renderer.DrawLine(ImVec2(dPos[6].x, dPos[6].y), ImVec2(dPos[7].x, dPos[7].y), Col[7], thickness);
		Renderer.DrawLine(ImVec2(dPos[7].x, dPos[7].y), ImVec2(dPos[8].x, dPos[8].y), Col[8], thickness);

		Renderer.DrawLine(ImVec2(dPos[9].x, dPos[9].y), ImVec2(dPos[10].x, dPos[10].y), Col[9], thickness);
		Renderer.DrawLine(ImVec2(dPos[10].x, dPos[10].y), ImVec2(dPos[11].x, dPos[11].y), Col[10], thickness);

		Renderer.DrawLine(ImVec2(dPos[12].x, dPos[12].y), ImVec2(dPos[13].x, dPos[13].y), Col[11], thickness);
		Renderer.DrawLine(ImVec2(dPos[13].x, dPos[13].y), ImVec2(dPos[14].x, dPos[14].y), Col[12], thickness);

	}
	else
	{
		Pos += GetBonesMatrix(this->pBPos[0]);
		tr = CalcVisable(View.m_Pos, Pos);
		if (tr.fraction > 0.97f || tr.m_pEnt == pAddr)
		{
			color = ImColor(ESP->cTeam);
		}
		if (!View.WorldToScreen(Pos, Pos))return false;
	}

	return true;
}

void __fastcall DrawEntity::GetClosestPlayerToCrossHair(Vector3 AimPos, float &max)
{
	if (!GetAimKey() || !isAimBot)
	{
		if (AimBot->bKneelDown)
		{
			if (IsbKneelDown()) return;
		}
		ImGuiIO& io = ImGui::GetIO();
		Vector3 DrawCenter = Vector3{ float(io.DisplaySize.x / 2),float(io.DisplaySize.y / 2),0 };
		float Dist = AimPos.distance(DrawCenter)*0.01905f;
		if (Dist < max)
		{
			max = Dist;
			CopyMemory(&ToAimBot, this, sizeof(ToAimBot));
		}
	}
}

void __fastcall DrawEntity::DrawInfo(ImVec2 dpos, int Dis, int color, bool DrawName, bool DrawHero, bool DrawDis)
{
	string draw;
	if (DrawName)
		draw = this->Name;
	if (DrawHero)
		draw = this->Hero;

	if (DrawDis)draw = string(draw + " [" + Helpers::VariableText("%d M", Dis) + "]");
	auto& style = ImGui::GetStyle();
	auto tmp = style.Colors[ImGuiCol_Text];
	style.Colors[ImGuiCol_Text] = ImColor(color);
	ImGui::RenderText(dpos, draw.c_str(), 0, false);
	style.Colors[ImGuiCol_Text] = tmp;
}
__int64 __fastcall GetBoneAddress(__int64 Address)
{
	//VMProtectBegin(__FUNCTION__);（已经被GameManager::rEntity占用）
	Address = Read<__int64>(Address + (int)ObjectManager::Info_Bone_Address);
	if (!IsValid(Address))return false;
	return Address;
	//VMProtectEnd;
}
bool __fastcall GetBonesPosAddress(__int64 b, __int64 *Address, int *Id, int size)
{
	b = GetBoneAddress(b);

	for (size_t i = 0; i < size; i++)
	{
		Address[i] = b + Id[i] * (int)ObjectManager::Info_Bone_Next;
		auto bb = Address[i];
		if (!IsValid(Address[i]))return false;
	}
	return true;
}

string __fastcall ReadTypeName(__int64 Address, const char* unknow)
{
	char Name[MAX_PATH] = {};
	if (!IsValid(Address))return unknow;
	auto c = Read<__int64>(Address + (int)ObjectManager::Info_TypeName);
	Read_(c, (__int64)&Name, sizeof(Name));
	if (strlen(Name) == 0)return unknow;
	return string(Name);
}
string __fastcall ReadName(__int64 Address, const char* unknow)
{
	char Name[MAX_PATH] = {};
	if (!IsValid(Address))return unknow;
	auto c = Read<__int64>(Address + (int)ObjectManager::Info_Name);
	Read_(c, (__int64)&Name, sizeof(Name));
	if (strlen(Name) == 0)return unknow;
	return string(Name);
}
string __fastcall ReadModName(__int64 Address, const char* unknow)
{
	char Name[MAX_PATH] = {};
	if (!IsValid(Address))return unknow;
	auto c = Read<__int64>(Address + (int)ObjectManager::Info_ModName);
	Read_(c, (__int64)&Name, sizeof(Name));
	if (strlen(Name) == 0)return unknow;
	return string(Name);
}


ID3D11ShaderResourceView * __fastcall JudgeItemsTexture(int ID)
{
	VMProtectBegin(__FUNCTION__);
#pragma region 武器
	if (ID == 5)return Renderer.pIBuf_Hemlock;//专注轻机枪

	if (ID == 3)return Renderer.pIBuf_Havoc;//哈沃克步枪

	if (ID == 7)return Renderer.pIBuf_Doubletake;//三重式狙击枪

	if (ID == 10)return Renderer.pIBuf_G2;//G7侦查枪

	if (ID == 26)return Renderer.pIBuf_P2011;//P2020手枪

	if (ID == 12)return Renderer.pIBuf_R97;//R99

	if (ID == 18)return Renderer.pIBuf_Rspn101;//R-301卡宾枪

	if (ID == 27)return Renderer.pIBuf_P2011_Auto;//RE-45自动手枪

	if (ID == 11)return Renderer.pIBuf_Alternator_Smg;//转换者冲锋枪

	if (ID == 20)return Renderer.pIBuf_W1128;//EVA-8自动散弹枪

	if (ID == 21)return Renderer.pIBuf_Peacekeeper;//和平捍卫者霞弹枪

	if (ID == 23)return Renderer.pIBuf_Pstl_Sa3;//莫桑比克霞弹枪

	if (ID == 1)return Renderer.pIBuf_Mastiff_Stgn;//敖犬散弹枪

	if (ID == 0)return Renderer.pIBuf_At_Rifle;//克雷贝尔.50口径狙击枪

	if (ID == 9)return Renderer.pIBuf_M1a1_Hemlok;//赫姆洛克连发突击步枪

	if (ID == 13)return Renderer.pIBuf_Prowler_Smg;//潜袭冲锋枪

	if (ID == 17)return Renderer.pIBuf_Lmg_Hemlok;//喷火枪

	if (ID == 8)return Renderer.pIBuf_Vinson;//VK-47平行步枪

	if (ID == 24)return Renderer.pIBuf_B3wing;//辅助手枪

	if (ID == 15)return Renderer.pIBuf_Rspn101_Dmr;//长弓精确步枪
#pragma endregion
	return 0;
	VMProtectEnd;
}
int __fastcall JudgeAmmo(int ID)
{
	VMProtectBegin(__FUNCTION__);
	if (ID == 5 | ID == 3 | ID == 7)
	{
		return 29;
	}

	if (ID == 10 | ID == 26 | ID == 12 | ID == 18 | ID == 27 | ID == 11)
	{
		return 28;
	}
	if (ID == 9 | ID == 13 | ID == 17 | ID == 8 | ID == 24 | ID == 15)
	{
		return 31;
	}
	if (ID == 20 | ID == 21 | ID == 23)
	{
		return 30;
	}
	if (ID == 1 | ID == 0)
	{
		return -1;
	}
	return 0;
	VMProtectEnd;
}
int __fastcall JudgeAmmo(string Name)
{
	VMProtectBegin(__FUNCTION__);
	if (strstr(Name.c_str(), XORSTR("/hemlock_br/")) != 0 | strstr(Name.c_str(), XORSTR("/beam_ar/")) != 0
		| strstr(Name.c_str(), XORSTR("/doubletake/")) != 0)
	{
		return 29;
	}

	if (strstr(Name.c_str(), XORSTR("/rspn101/")) != 0 | strstr(Name.c_str(), XORSTR("_g2a4.rmdl")) != 0 |
		strstr(Name.c_str(), XORSTR("_alternator_smg.rmdl")) != 0 | strstr(Name.c_str(), XORSTR("_r97.rmdl")) != 0 |
		strstr(Name.c_str(), XORSTR("_p2011.rmdl")) != 0 | strstr(Name.c_str(), XORSTR("_p2011_auto.rmdl")) != 0)
	{
		return 28;
	}
	if (strstr(Name.c_str(), XORSTR("_vinson.rmdl")) != 0 | strstr(Name.c_str(), XORSTR("/m1a1_hemlok/")) != 0 |
		strstr(Name.c_str(), XORSTR("/prowler_smg/")) != 0 | strstr(Name.c_str(), XORSTR("/rspn101_dmr/")) != 0 |
		strstr(Name.c_str(), XORSTR("/lmg_hemlok/")) != 0 | strstr(Name.c_str(), XORSTR("/b3wing/")) != 0)
	{
		return 31;
	}
	if (strstr(Name.c_str(), XORSTR("/peacekeeper/")) != 0 | strstr(Name.c_str(), XORSTR("/w1128/")) != 0 |
		strstr(Name.c_str(), XORSTR("/pstl_sa3/")) != 0)
	{
		return 30;
	}

	if (strstr(Name.c_str(), XORSTR("/at_rifle/")) != 0 | strstr(Name.c_str(), XORSTR("/mastiff_stgn/")) != 0)
	{
		return -1;
	}
	return 0;
	VMProtectEnd;
}

DrawEntity __fastcall GameManager::GetLocalPlayer()
{
	Local.pAddr = Read<__int64>((int)Game::gGameLocal + CProcess._pBase);
	if (!IsValid(Local.pAddr))return DrawEntity();
	Local.ID = Read<int>(Local.pAddr + (int)ObjectManager::Info_ID);
	Local.Team = Read<int>(Local.pAddr + (int)ObjectManager::Info_Team);
	auto WeaponId = Read<short>((int)ObjectManager::Info_Weapon + Local.pAddr) << 5;

	auto WeaponAddr = Read<__int64>(GetEntityList() + WeaponId);
	if (!IsValid(WeaponAddr))return Local;
	Local.Weapon.pAddr = WeaponAddr;
	auto WeaponName = ReadModName(Local.Weapon.pAddr, XORSTR("Unknown"));
	if (WeaponName.length() == NULL)return Local;
	Local.Weapon.Ammo = JudgeAmmo(WeaponName);
	Local.Weapon.Speed = Read<float>(Local.Weapon.pAddr + (int)ObjectManager::Info_Weapon_Speed)*0.019623;
	return Local;
}

void __fastcall GameManager::ReadEntity(__int64 m_pArray)
{
	//VMProtectBegin(__FUNCTION__);（已经被_Administer::ThreadManager()占用）
	auto pAddress = m_pArray;
	for (size_t i = 0; i < 0x10000; i++)
	{
		pAddress = Read<__int64>(m_pArray + (i << 5));
		if (!IsValid(pAddress))continue;
		rEntity(pAddress);
	}
	//VMProtectEnd;

}
list <DrawEntity>tPlayers = list <DrawEntity>();
list <DrawEntity>tItems = list <DrawEntity>();
list <LootInfo>tLoot = list <LootInfo>();
void __fastcall GameManager::rEntity(__int64 pAddress)
{
	VMProtectBegin(__FUNCTION__);

	DrawEntity pEntity;
	pEntity.pAddr = pAddress;
	auto TypeName = ReadTypeName(pEntity.pAddr, XORSTR("#Nop"));
	auto pPos = Read<__int64>(CProcess._pBase + (int)Game::gView);
	auto vPos = Read<Vector3>(pPos + (int)Game::pView_Pos);
	auto pos = Read<Vector3>(pEntity.pAddr + (int)ObjectManager::Info_Pos_Min);
	if (TypeName == XORSTR("#Nop"))return;
	if (TypeName == XORSTR("player"))
	{
		auto	Dis = vPos.distance(pos)*0.01905f;
		if (ESP->iPlayerShow)
		{
			if (Dis > ESP->iPlayerShow + 10)return;
		}

		auto id = Read<int>(pEntity.pAddr + (int)ObjectManager::Info_ID);
		if (id == Local.ID)return;

		pEntity.Team = Read<int>(pEntity.pAddr + (int)ObjectManager::Info_Team);
		pEntity.Col = ImColor(ESP->cPlayer);
		if (Local.Team == pEntity.Team)
		{
			pEntity.Col = ImColor(ESP->cTeam);
		}
		pEntity.Name = ReadName(pEntity.pAddr, XORSTR("#Player"));
		string Hero = ReadModName(pEntity.pAddr, XORSTR( "#Nop"));
		if (strstr(Hero.c_str(), XORSTR("pilot_medium_holo")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_holo1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_holo2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_holo, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("幻象")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_heavy_caustic")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_caustic1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_caustic2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_caustic, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("侵蚀")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_heavy_gibraltar")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_gibraltar2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_gibraltar, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("直布罗陀")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_light_support")) != 0)
		{
			if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_light_support, 15))return;
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("命脉")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_heavy_pathfinder")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_pathfinder1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_pathfinder2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_heavy_pathfinder, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("探路者")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_medium_bloodhound")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bloodhound1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bloodhound2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bloodhound, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("寻血猎犬")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_light_wraith")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_light_wraith1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_light_wraith2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_light_wraith, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("恶灵")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}

		if (strstr(Hero.c_str(), XORSTR("pilot_medium_bangalore")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bangalore1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bangalore2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_bangalore, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("班加罗尔")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}
		if (strstr(Hero.c_str(), XORSTR("pilot_medium_stim")) != 0)
		{
			if (strstr(Hero.c_str(), XORSTR("legendary_01")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_stim1, 15))return;
			}
			else if (strstr(Hero.c_str(), XORSTR("legendary_02")) != 0)
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_stim2, 15))return;
			}
			else
			{
				if (!GetBonesPosAddress(pEntity.pAddr, pEntity.pBPos, _Bone::Bone_medium_stim, 15))return;
			}
			pEntity.Hero = (CProcess.StringToUtf8(XORSTR("动力小子")).c_str());
			tPlayers.push_back(pEntity);
			return;
		}
		return;
	}
	if (TypeName == XORSTR("prop_survival"))
	{
		auto	Dis = vPos.distance(pos)*0.01905f;
		if (Misc->iItemsShow)
		{
			if (Dis > Misc->iItemsShow + 10)return;
		}
		pEntity.ID = Read<int>(pEntity.pAddr + (int)ObjectManager::Info_ItemsID);
		pEntity.Col = ImColor(Misc->cItems);
		auto ammo = JudgeAmmo(pEntity.ID);
		if (Misc->bItems)
		{
			if (pEntity.ID == 35)
			{

				pEntity.pSBuf = Renderer.pIBuf_Health_Main_Small;//注射器
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 34)
			{
				
				pEntity.pSBuf = Renderer.pIBuf_Health_Main_Large;//大注射器";
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 37)
			{

				pEntity.pSBuf = Renderer.pIBuf_Shield_Battery_Small;//小型护盾电池
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 36)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Battery_Large;//大型护盾电池
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 33)
			{
	
				pEntity.pSBuf = Renderer.pIBuf_Phoenix_Kit;//凤凰治疗包;
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 32)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Accelerant;//绝招加速剂;
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
		}
		if (Misc->bGrenades)
		{
			if (pEntity.ID == 54)
			{
	
				pEntity.pSBuf = Renderer.pIBuf_Thermite_Grenade;//铝热剂手雷
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 55)
			{
			
				pEntity.pSBuf = Renderer.pIBuf_M20_Grenade;//碎片手雷
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 56)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shuriken;//电弧星
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
		}

		if (Misc->bEquip)
		{
			if (pEntity.ID == 46)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Down;//击倒护盾;v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 47)
			{
			
				pEntity.pSBuf = Renderer.pIBuf_Shield_Down;//击倒护盾;v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 48)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Down;//击倒护盾;v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 49)
			{
			
				pEntity.pSBuf = Renderer.pIBuf_Shield_Down;//击倒护盾;v4
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 42)
			{

				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Body; //"护甲";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 43)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Body; //"护甲";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 44)
			{

				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Body; //"护甲";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 45)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Body; //"护甲";v4
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 38)
			{
		
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Head;// "头盔";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 39)
			{
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Head;// "头盔";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 40)
			{
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Head;// "头盔";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 41)
			{
				pEntity.pSBuf = Renderer.pIBuf_Shield_Upgrade_Head;// "头盔";v4
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 50)
			{
				pEntity.pSBuf = Renderer.pIBuf_Backpack_Light;//小型背包;
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 51)
			{
				pEntity.pSBuf = Renderer.pIBuf_Backpack_Medium;//中型背包;
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 52)
			{
				pEntity.pSBuf = Renderer.pIBuf_Backpack_Heavy;//大型背包;
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 53)
			{
				pEntity.pSBuf = Renderer.pIBuf_Backpack_Heavy;//大型背包;
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}
		}

		if (Misc->bParts)
		{
			if (pEntity.ID == 86)
			{
				pEntity.pSBuf = Renderer.pIBuf_Chip_V1;//涡轮增压器
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 87)
			{
				pEntity.pSBuf = Renderer.pIBuf_Chip_V2;//选择射击模式接收器
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 88)
			{
				pEntity.pSBuf = Renderer.pIBuf_Chip_V3;//精密扼流圈
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 89)
			{
				pEntity.pSBuf = Renderer.pIBuf_Chip_V4;//穿心膛线
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 57)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Cq_Holo_Var;//"1X全息镜";
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 58)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Cq_Holo_Var_2x;//2倍全息瞄准镜
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 59)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Cq_Hcog_R1;//"单倍幻影";
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 60)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Cq_Hcog_R2;//"单倍至2倍可调节幻影瞄准镜";
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 61)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Cq_Threat;//单倍数字化威胁
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 62)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Rng_Hcog_Acgs;//"3倍全息瞄准镜";
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 63)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Rng_Aog_Var_R1;//"2倍至4倍可调节式高级光学瞄准镜";
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}

			//狙击配件
			if (pEntity.ID == 64)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Rng_Sni_Dcom;//"6x狙击镜";
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 65)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Rng_Sni_Var_Talon;//"4X-8X可调整狙击";
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 66)
			{
				pEntity.pSBuf = Renderer.pIBuf_Optic_Rng_Aog_Var_R2;//4倍至10倍可调节式狙击数字化威胁
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 67)
			{
				pEntity.pSBuf = Renderer.pIBuf_Suppr_V2b;//"枪管稳定器";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 68)
			{
				pEntity.pSBuf = Renderer.pIBuf_Suppr_V2b;//"枪管稳定器";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 69)
			{
				pEntity.pSBuf = Renderer.pIBuf_Suppr_V2b;//"枪管稳定器";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 70)
			{
				pEntity.pSBuf = Renderer.pIBuf_Suppr_V2b;//"枪管稳定器";v4
				pEntity.Col = ImColor(Misc->cItemsLegendary);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 80)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Regular;//"标准枪托";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 81)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Regular;//"标准枪托";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 82)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Regular;//"标准枪托";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 83)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Sniper;//"狙击枪托";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 84)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Sniper;//"狙击枪托";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}

			if (pEntity.ID == 85)
			{
				pEntity.pSBuf = Renderer.pIBuf_Stock_Folded_Sniper;//"狙击枪托";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}

		}

#pragma region 能量武器

		if (Misc->bNrg)
		{
			if (ammo == 29)
			{
				pEntity.pSBuf = JudgeItemsTexture(pEntity.ID);
				pEntity.Col = ImColor(Misc->cNrg);
				tItems.push_back(pEntity);
				return;
			}
		}
		if (Misc->bAutoAmmo)
		{
			if (pEntity.ID == 29)
			{
				pEntity.pSBuf = Renderer.pIBuf_Nrg;
				pEntity.Col = ImColor(Misc->cNrg);
				tItems.push_back(pEntity);
				return;
			}
		}

#pragma endregion

#pragma region 重型武器

		if (Misc->bHc)
		{
			if (ammo == 31)
			{
				pEntity.pSBuf = JudgeItemsTexture(pEntity.ID);
				pEntity.Col = ImColor(Misc->cHc);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 74)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V2b;//"重型配件";v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 75)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V2b;//"重型配件";v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 76)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V2b;//"重型配件";v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
		}
		if (Misc->bAutoAmmo)
		{
			if (pEntity.ID == 31)
			{
				pEntity.Col = ImColor(Misc->cHc);
				pEntity.pSBuf = Renderer.pIBuf_Hc;//重型子弹
				tItems.push_back(pEntity);
				return;
			}
		}

#pragma endregion

#pragma region 轻型武器

		if (Misc->bSc)
		{
			if (ammo == 28)
			{
				pEntity.pSBuf = JudgeItemsTexture(pEntity.ID);
				pEntity.Col = ImColor(Misc->cSc);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 71)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V1b;//加长式轻型弹夹v1
				pEntity.Col = ImColor(Misc->cItemsCommon);;
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 72)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V1b;//加长式轻型弹夹v2
				pEntity.Col = ImColor(Misc->cItemsRare);;
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 73)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V1b;//加长式轻型弹夹v3
				pEntity.Col = ImColor(Misc->cItemsEpic);;
				tItems.push_back(pEntity);
				return;
			}
		}

		if (Misc->bAutoAmmo)
		{
			if (pEntity.ID == 28)
			{
				pEntity.pSBuf = Renderer.pIBuf_Sc;//轻型子弹
				pEntity.Col = ImColor(Misc->cSc);
				tItems.push_back(pEntity);
				return;
			}
		}

#pragma endregion
#pragma region 霰弹武器
		if (Misc->bShg)
		{
			if (ammo == 30)
			{
				pEntity.pSBuf = JudgeItemsTexture(pEntity.ID);
				pEntity.Col = ImColor(Misc->cShg);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 77)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V3b;//霞弹枪枪栓v1
				pEntity.Col = ImColor(Misc->cItemsCommon);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 78)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V3b;//霞弹枪枪栓v2
				pEntity.Col = ImColor(Misc->cItemsRare);
				tItems.push_back(pEntity);
				return;
			}
			if (pEntity.ID == 79)
			{
				pEntity.pSBuf = Renderer.pIBuf_Mag_V3b;//霞弹枪枪栓v3
				pEntity.Col = ImColor(Misc->cItemsEpic);
				tItems.push_back(pEntity);
				return;
			}
		}
		if (Misc->bAutoAmmo)
		{
			if (pEntity.ID == 30)
			{
				pEntity.pSBuf = Renderer.pIBuf_Shg;//霰弹枪子弹
				pEntity.Col = ImColor(Misc->cShg);
				tItems.push_back(pEntity);
				return;
			}
		}

#pragma endregion
#pragma region 特殊武器
		if (ammo == -1)
		{
			pEntity.pSBuf = JudgeItemsTexture(pEntity.ID);
			pEntity.Col = 0xFF00D7FF;
			tItems.push_back(pEntity);
			return;
		}
#pragma endregion

		// 		tItems.push_back(pEntity);
		// 		return;
	}

	return;
	VMProtectEnd;
}
Vector3 aimCorrection(Vector3 localPos, Vector3 aimPoint, Vector3 targetVelocity, float bulletSpeed, float gravity)
{
	if (bulletSpeed > 10.0f)
	{
		float distance = localPos.distance(aimPoint);
		float flTime = (distance*0.01905f) / fabs(bulletSpeed);
		gravity = flTime * flTime*375.f;

		aimPoint.x += flTime * targetVelocity.x;
		aimPoint.y += flTime * targetVelocity.y;
		aimPoint.z += flTime * targetVelocity.z + gravity;
		return aimPoint;
	}
	return aimPoint;
}

void __fastcall GameAimInit(DrawEntity &To)
{
	if (!IsValid(To.pAddr))
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
		return;
	}
	if (!IsValid(Local.pAddr))
	{
		ZeroMemory(&To, sizeof(To));
		ZeroMemory(&Local, sizeof(Local));
		isAimBot = false;
		return;
	}
	if (To.IsDead())
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
		return;
	}
	if (AimBot->bKneelDown)
	{
		if (To.IsbKneelDown())
		{
			ZeroMemory(&To, sizeof(To));
			isAimBot = false;
			return;
		}
	}

	Vector3 AimPos, AimPos2, DrawAim;
	auto pView = GameManager::GetView();
	if (AimBot->iPos == 3)
	{
		int r = rand() % 3;
		AimPos = GetBonesMatrix(To.pBPos[r]);
	}
	else
	{
		AimPos = GetBonesMatrix(To.pBPos[AimBot->iPos]);
	}
	AimPos += To.GetMinPos();
	AimPos = aimCorrection(pView.m_Pos, AimPos, Read<Vector3>(To.pAddr + (int)ObjectManager::Info_Pos_Pro), Local.Weapon.Speed, AimBot->fHeight);

	if (pView.WorldToScreen(AimPos, DrawAim))
	{
		ImGuiIO& io = ImGui::GetIO();
		Vector3 ScreenCenter = Vector3{ float(io.DisplaySize.x / 2),float(io.DisplaySize.y / 2),0 };
		if ((DrawAim.distance(ScreenCenter) <= AimBot->fFov || isAimBot))
		{
			Renderer.DrawCircle(ImVec2(DrawAim.x, DrawAim.y), 3, (ImColor)AimBot->cAim, 1.5f);
			isAimBot = true;

			auto aAimPos = CalcAngles(pView.m_Pos, AimPos);
			Write<Vector2>(Local.pAddr + (int)Game::pAimBot_Address, Vector2(aAimPos.y -
				Read<float>(Local.pAddr + (int)Game::pRecoil)*(1 + (AimBot->iRecoilY*0.01)),
				aAimPos.x - Read<float>(Local.pAddr + (int)Game::pRecoil + 4)*(1 + (AimBot->iRecoilX*0.01))));
		}
		else
		{
			ZeroMemory(&To, sizeof(To));
			isAimBot = false;
		}
	}
	else
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
	}
}

void __fastcall GameAimInit2(DrawEntity &To)
{
	if (!IsValid(To.pAddr))
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
		return;
	}
	if (!IsValid(Local.pAddr))
	{
		ZeroMemory(&To, sizeof(To));
		ZeroMemory(&Local, sizeof(Local));
		isAimBot = false;
		return;
	}

	if (To.IsDead())
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
		return;
	}

	Vector3 AimPos, AimPos2, DrawAim;
	auto pView = GameManager::GetView();
	if (AimBot->iPos2 == 3)
	{
		int r = rand() % 3;
		AimPos = GetBonesMatrix(To.pBPos[r]);
	}
	else
	{
		AimPos = GetBonesMatrix(To.pBPos[AimBot->iPos2]);
	}
	AimPos += To.GetMinPos();
	AimPos = aimCorrection(pView.m_Pos, AimPos, Read<Vector3>(To.pAddr + (int)ObjectManager::Info_Pos_Pro), Local.Weapon.Speed, AimBot->fHeight2);

	if (pView.WorldToScreen(AimPos, DrawAim))
	{
		Renderer.DrawCircle(ImVec2(DrawAim.x, DrawAim.y), 3, (ImColor)AimBot->cAim, 1.5f);
		ImGuiIO& io = ImGui::GetIO();
		Vector3 ScreenCenter = Vector3{ float(io.DisplaySize.x / 2),float(io.DisplaySize.y / 2),0 };
		if ((DrawAim.distance(ScreenCenter) <= AimBot->fFov || isAimBot))
		{
			Renderer.DrawCircle(ImVec2(DrawAim.x, DrawAim.y), 3, (ImColor)AimBot->cAim, 1.5f);
			isAimBot = true;

			auto aAimPos = CalcAngles(pView.m_Pos, AimPos);
			Write<Vector2>(Local.pAddr + (int)Game::pAimBot_Address, Vector2(aAimPos.y -
				Read<float>(Local.pAddr + (int)Game::pRecoil)*(1 + (AimBot->iRecoilY*0.01)),
				aAimPos.x - Read<float>(Local.pAddr + (int)Game::pRecoil + 4)*(1 + (AimBot->iRecoilX*0.01))));
		}
		else
		{
			ZeroMemory(&To, sizeof(To));
			isAimBot = false;
		}
	}
	else
	{
		ZeroMemory(&To, sizeof(To));
		isAimBot = false;
	}
}
void __fastcall GameManager::GameAimBot()
{
	VMProtectBegin(__FUNCTION__);
	if (AimBot->bAimBot)
	{
		if (GetAimKey())
		{
			GameAimInit(ToAimBot);
		}
		else
		{
			isAimBot = false;
		}
	}
	if (AimBot->bAimBot2)
	{
		if (GetAimKey2())
		{
			GameAimInit2(ToAimBot);
		}
		else
		{
			isAimBot = false;
		}
	}
	if (!isAimBot)
	{
		if (AimBot->bSpeed)
		{
			DWORD old;
			if (GetSpeedKey())
			{
				VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, PAGE_EXECUTE_READWRITE, &old);
				Write<byte>(HookSpeedViodAddress + 0xa0, 1);
				VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, old, &old);
			}
			else
			{
				VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, PAGE_EXECUTE_READWRITE, &old);
				Write<byte>(HookSpeedViodAddress + 0xa0, 0);
				VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, old, &old);
			}
		}
		else
		{
			DWORD old;
			VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, PAGE_EXECUTE_READWRITE, &old);
			Write<byte>(HookSpeedViodAddress + 0xa0, 0);
			VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, old, &old);
		}
	}
	else
	{
		DWORD old;
		VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, PAGE_EXECUTE_READWRITE, &old);
		Write<byte>(HookSpeedViodAddress + 0xa0, 0);
		VirtualProtect((LPVOID)(HookSpeedViodAddress + 0xa0), 8, old, &old);
	}

	if (AimBot->bRecoil)
	{
		if (!IsValid(Local.pAddr) | !IsValid(Local.Weapon.pAddr))
		{
			ZeroMemory(&Local, sizeof(Local));
			isAimBot = false;
			return;
		}
		Write<float>(Local.Weapon.pAddr + 0x1330, 0);
		Write<float>(Local.Weapon.pAddr + 0x1340, 0);
		Write<__int64>(Local.Weapon.pAddr + 0x1334, 0);
	}
	VMProtectEnd;
}