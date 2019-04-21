#pragma once
#include "stdafx.h"
#define Renderer _Renderer::Instance()
class _Renderer
{
public:
	void Initialize();
	void __fastcall ShaderResourceIni(ID3D11Device *);
	void BeginScene();
	void EndScene();

	float __fastcall OutlinedText(ImFont* pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center);
	float __fastcall Text(ImFont* pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center);
	void __fastcall DrawLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void __fastcall DrawCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f);
	void __fastcall DrawCircleScale(const ImVec2& position, float radius, uint32_t color, const ImVec2& scalepos, const ImVec2& scaleheadPosition, float thickness = 1.0f);
	void __fastcall DrawCircleFilled(const ImVec2& position, float radius, uint32_t color);
	void __fastcall DrawBox(const ImVec2& position, const ImVec2& headPosition, uint32_t=0, uint32_t =0);
	void __fastcall DrawGapBox(float, float, float, float, uint32_t =0);
	void __fastcall DrawHealth(float X, float Y, float W, float H, float Health, float MaxHealth);
	void __fastcall DrawShield(float X, float Y, float W, float H, float Health, float MaxHealth);
	void __fastcall DrawIco(ImVec2, ImVec2, PVOID64, uint32_t = 0xffffffff);
	void __fastcall DrawMultiHealth(float X, float Y, float W, float H, float Health, float MaxHealth, uint32_t col_left, uint32_t col_right);

	ImFont* m_pDefault;
	static _Renderer& Instance() {
		static _Renderer _Handle;
		return _Handle;
	}

	ID3D11ShaderResourceView*	pIBuf_Nrg;
	ID3D11ShaderResourceView*	pIBuf_Hc;
	ID3D11ShaderResourceView*	pIBuf_Sc;
	ID3D11ShaderResourceView*	pIBuf_Shg;

	ID3D11ShaderResourceView*	pIBuf_Havoc;
	ID3D11ShaderResourceView*	pIBuf_Hemlock;
	ID3D11ShaderResourceView*	pIBuf_Doubletake;

	ID3D11ShaderResourceView*	pIBuf_G2;
	ID3D11ShaderResourceView*	pIBuf_P2011;
	ID3D11ShaderResourceView*	pIBuf_R97;
	ID3D11ShaderResourceView*	pIBuf_Rspn101;
	ID3D11ShaderResourceView*	pIBuf_P2011_Auto;
	ID3D11ShaderResourceView*	pIBuf_Alternator_Smg;

	ID3D11ShaderResourceView*	pIBuf_W1128;
	ID3D11ShaderResourceView*	pIBuf_Peacekeeper;
	ID3D11ShaderResourceView*	pIBuf_Pstl_Sa3;

	ID3D11ShaderResourceView*	pIBuf_Mastiff_Stgn;
	ID3D11ShaderResourceView*	pIBuf_At_Rifle;

	ID3D11ShaderResourceView*	pIBuf_M1a1_Hemlok;
	ID3D11ShaderResourceView*	pIBuf_Prowler_Smg;
	ID3D11ShaderResourceView*	pIBuf_Lmg_Hemlok;
	ID3D11ShaderResourceView*	pIBuf_Vinson;
	ID3D11ShaderResourceView*	pIBuf_B3wing;
	ID3D11ShaderResourceView*	pIBuf_Rspn101_Dmr;

	ID3D11ShaderResourceView*	pIBuf_Thermite_Grenade;
	ID3D11ShaderResourceView*	pIBuf_Shuriken;
	ID3D11ShaderResourceView*	pIBuf_M20_Grenade;

	ID3D11ShaderResourceView*	pIBuf_Shield_Battery_Small;
	ID3D11ShaderResourceView*	pIBuf_Shield_Battery_Large;

	ID3D11ShaderResourceView*	pIBuf_Health_Main_Small;
	ID3D11ShaderResourceView*	pIBuf_Health_Main_Large;

	ID3D11ShaderResourceView*	pIBuf_Phoenix_Kit;

	ID3D11ShaderResourceView*	pIBuf_Accelerant;

	ID3D11ShaderResourceView*	pIBuf_Backpack_Light;
	ID3D11ShaderResourceView*	pIBuf_Backpack_Medium;
	ID3D11ShaderResourceView*	pIBuf_Backpack_Heavy;
	ID3D11ShaderResourceView*	pIBuf_Shield_Down;
	ID3D11ShaderResourceView*	pIBuf_Shield_Upgrade_Body;
	ID3D11ShaderResourceView*	pIBuf_Shield_Upgrade_Head;

	ID3D11ShaderResourceView*	pIBuf_Optic_Cq_Holo_Var;
	ID3D11ShaderResourceView*	pIBuf_Optic_Cq_Holo_Var_2x;
	ID3D11ShaderResourceView*	pIBuf_Optic_Cq_Hcog_R1;
	ID3D11ShaderResourceView*	pIBuf_Optic_Cq_Hcog_R2;
	ID3D11ShaderResourceView*	pIBuf_Optic_Cq_Threat;
	ID3D11ShaderResourceView*	pIBuf_Optic_Rng_Hcog_Acgs;
	ID3D11ShaderResourceView*	pIBuf_Optic_Rng_Aog_Var_R1;
	ID3D11ShaderResourceView*	pIBuf_Optic_Rng_Sni_Dcom;
	ID3D11ShaderResourceView*	pIBuf_Optic_Rng_Sni_Var_Talon;
	ID3D11ShaderResourceView*	pIBuf_Optic_Rng_Aog_Var_R2;

	ID3D11ShaderResourceView*	pIBuf_Suppr_V2b;

	ID3D11ShaderResourceView*	pIBuf_Mag_V1b;
	ID3D11ShaderResourceView*	pIBuf_Mag_V2b;
	ID3D11ShaderResourceView*	pIBuf_Mag_V3b;

	ID3D11ShaderResourceView*	pIBuf_Stock_Folded_Regular;
	ID3D11ShaderResourceView*	pIBuf_Stock_Folded_Sniper;

	ID3D11ShaderResourceView*	pIBuf_Chip_V1;
	ID3D11ShaderResourceView*	pIBuf_Chip_V2;
	ID3D11ShaderResourceView*	pIBuf_Chip_V3;
	ID3D11ShaderResourceView*	pIBuf_Chip_V4;
};


