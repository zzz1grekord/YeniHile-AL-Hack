#include "Renderer.h"

using namespace std;

void _Renderer::Initialize()
{
	VMProtectBegin(__FUNCTION__);
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	auto& style = ImGui::GetStyle();
	style.FrameBorderSize = 0;
	style.WindowRounding = 0;
	style.Colors[ImGuiCol_Border] = ImVec4();
	style.Colors[ImGuiCol_BorderShadow] = ImVec4();

	m_pDefault = io.Fonts->AddFontFromFileTTF(CProcess.StringToUtf8(XORSTR("c:\\Windows\\Fonts\\msyh.ttf")).c_str(), 20.0f, NULL, io.Fonts->GetGlyphRangesChinese());
	if (!m_pDefault)
		m_pDefault = io.Fonts->AddFontFromFileTTF(CProcess.StringToUtf8(XORSTR("c:\\Windows\\Fonts\\msyh.ttc")).c_str(), 20.0f, NULL, io.Fonts->GetGlyphRangesChinese());
	VMProtectEnd;
}
void __fastcall _Renderer::ShaderResourceIni(ID3D11Device * D3d11Device)
{
	VMProtectBegin(__FUNCTION__);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_AmmoNrg, sizeof(Texture_AmmoNrg), 0, 0, &pIBuf_Nrg, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_AmmoHc, sizeof(Texture_AmmoHc), 0, 0, &pIBuf_Hc, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_AmmoSc, sizeof(Texture_AmmoSc), 0, 0, &pIBuf_Sc, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_AmmoShg, sizeof(Texture_AmmoShg), 0, 0, &pIBuf_Shg, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Havoc, sizeof(Texture_Havoc), 0, 0, &pIBuf_Havoc, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Hemlock, sizeof(Texture_Hemlock), 0, 0, &pIBuf_Hemlock, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Doubletake, sizeof(Texture_Doubletake), 0, 0, &pIBuf_Doubletake, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_G2, sizeof(Texture_G2), 0, 0, &pIBuf_G2, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_P2011, sizeof(Texture_P2011), 0, 0, &pIBuf_P2011, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_R97, sizeof(Texture_R97), 0, 0, &pIBuf_R97, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Rspn101, sizeof(Texture_Rspn101), 0, 0, &pIBuf_Rspn101, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_P2011_Auto, sizeof(Texture_P2011_Auto), 0, 0, &pIBuf_P2011_Auto, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Alternator_Smg, sizeof(Texture_Alternator_Smg), 0, 0, &pIBuf_Alternator_Smg, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_W1128, sizeof(Texture_W1128), 0, 0, &pIBuf_W1128, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Peacekeeper, sizeof(Texture_Peacekeeper), 0, 0, &pIBuf_Peacekeeper, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Pstl_Sa3, sizeof(Texture_Pstl_Sa3), 0, 0, &pIBuf_Pstl_Sa3, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Mastiff_Stgn, sizeof(Texture_Mastiff_Stgn), 0, 0, &pIBuf_Mastiff_Stgn, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_At_Rifle, sizeof(Texture_At_Rifle), 0, 0, &pIBuf_At_Rifle, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_M1a1_Hemlok, sizeof(Texture_M1a1_Hemlok), 0, 0, &pIBuf_M1a1_Hemlok, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Prowler_Smg, sizeof(Texture_Prowler_Smg), 0, 0, &pIBuf_Prowler_Smg, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Lmg_Hemlok, sizeof(Texture_Lmg_Hemlok), 0, 0, &pIBuf_Lmg_Hemlok, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Vinson, sizeof(Texture_Vinson), 0, 0, &pIBuf_Vinson, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_B3wing, sizeof(Texture_B3wing), 0, 0, &pIBuf_B3wing, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Rspn101_Dmr, sizeof(Texture_Rspn101_Dmr), 0, 0, &pIBuf_Rspn101_Dmr, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Thermite_Grenade, sizeof(Texture_Thermite_Grenade), 0, 0, &pIBuf_Thermite_Grenade, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shuriken, sizeof(Texture_Shuriken), 0, 0, &pIBuf_Shuriken, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_M20_Grenade, sizeof(Texture_M20_Grenade), 0, 0, &pIBuf_M20_Grenade, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shield_Battery_Small, sizeof(Texture_Shield_Battery_Small), 0, 0, &pIBuf_Shield_Battery_Small, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shield_Battery_Large, sizeof(Texture_Shield_Battery_Large), 0, 0, &pIBuf_Shield_Battery_Large, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Health_Main_Small, sizeof(Texture_Health_Main_Small), 0, 0, &pIBuf_Health_Main_Small, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Health_Main_Large, sizeof(Texture_Health_Main_Large), 0, 0, &pIBuf_Health_Main_Large, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Phoenix_Kit, sizeof(Texture_Phoenix_Kit), 0, 0, &pIBuf_Phoenix_Kit, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Accelerant, sizeof(Texture_Accelerant), 0, 0, &pIBuf_Accelerant, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Backpack_Light, sizeof(Texture_Backpack_Light), 0, 0, &pIBuf_Backpack_Light, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Backpack_Medium, sizeof(Texture_Backpack_Medium), 0, 0, &pIBuf_Backpack_Medium, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Backpack_Heavy, sizeof(Texture_Backpack_Heavy), 0, 0, &pIBuf_Backpack_Heavy, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shield_Down, sizeof(Texture_Shield_Down), 0, 0, &pIBuf_Shield_Down, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shield_Upgrade_Body, sizeof(Texture_Shield_Upgrade_Body), 0, 0, &pIBuf_Shield_Upgrade_Body, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Shield_Upgrade_Head, sizeof(Texture_Shield_Upgrade_Head), 0, 0, &pIBuf_Shield_Upgrade_Head, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Cq_Holo_Var_2x, sizeof(Texture_Optic_Cq_Holo_Var_2x), 0, 0, &pIBuf_Optic_Cq_Holo_Var_2x, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Cq_Holo_Var, sizeof(Texture_Optic_Cq_Holo_Var), 0, 0, &pIBuf_Optic_Cq_Holo_Var, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Cq_Hcog_R1, sizeof(Texture_Optic_Cq_Hcog_R1), 0, 0, &pIBuf_Optic_Cq_Hcog_R1, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Cq_Hcog_R2, sizeof(Texture_Optic_Cq_Hcog_R2), 0, 0, &pIBuf_Optic_Cq_Hcog_R2, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Cq_Threat, sizeof(Texture_Optic_Cq_Threat), 0, 0, &pIBuf_Optic_Cq_Threat, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Rng_Hcog_Acgs, sizeof(Texture_Optic_Rng_Hcog_Acgs), 0, 0, &pIBuf_Optic_Rng_Hcog_Acgs, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Rng_Aog_Var_R1, sizeof(Texture_Optic_Rng_Aog_Var_R1), 0, 0, &pIBuf_Optic_Rng_Aog_Var_R1, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Rng_Sni_Dcom, sizeof(Texture_Optic_Rng_Sni_Dcom), 0, 0, &pIBuf_Optic_Rng_Sni_Dcom, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Rng_Sni_Var_Talon, sizeof(Texture_Optic_Rng_Sni_Var_Talon), 0, 0, &pIBuf_Optic_Rng_Sni_Var_Talon, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Optic_Rng_Aog_Var_R2, sizeof(Texture_Optic_Rng_Aog_Var_R2), 0, 0, &pIBuf_Optic_Rng_Aog_Var_R2, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Suppr_V2b, sizeof(Texture_Suppr_V2b), 0, 0, &pIBuf_Suppr_V2b, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Mag_V1b, sizeof(Texture_Mag_V1b), 0, 0, &pIBuf_Mag_V1b, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Mag_V2b, sizeof(Texture_Mag_V2b), 0, 0, &pIBuf_Mag_V2b, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Mag_V3b, sizeof(Texture_Mag_V3b), 0, 0, &pIBuf_Mag_V3b, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Stock_Folded_Regular, sizeof(Texture_Stock_Folded_Regular), 0, 0, &pIBuf_Stock_Folded_Regular, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Stock_Folded_Sniper, sizeof(Texture_Stock_Folded_Sniper), 0, 0, &pIBuf_Stock_Folded_Sniper, 0);

	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Chip_V1, sizeof(Texture_Chip_V1), 0, 0, &pIBuf_Chip_V1, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Chip_V2, sizeof(Texture_Chip_V2), 0, 0, &pIBuf_Chip_V2, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Chip_V3, sizeof(Texture_Chip_V3), 0, 0, &pIBuf_Chip_V3, 0);
	D3DX11CreateShaderResourceViewFromMemory(D3d11Device, Texture_Chip_V4, sizeof(Texture_Chip_V4), 0, 0, &pIBuf_Chip_V4, 0);

	VMProtectEnd;
}
void _Renderer::BeginScene()
{
	//VMProtectBegin(__FUNCTION__);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
	ImGui::Begin(CProcess.StringToUtf8(XORSTR("DrawWindow")).c_str(), reinterpret_cast<bool*>(true), ImVec2(0, 0), 0.0f,
		ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse
		| ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoInputs);
	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiSetCond_Always);
	ImGui::SetWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiSetCond_Always);
	//VMProtectEnd;
}

void _Renderer::EndScene()
{
	//VMProtectBegin(__FUNCTION__);
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->PushClipRectFullScreen();

	ImGui::End();
	ImGui::PopStyleColor();
	//VMProtectEnd;
}

void __fastcall _Renderer::DrawBox(const ImVec2& pos, const ImVec2& headPosition, uint32_t rounding, uint32_t color)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float width = (headPosition.y + 10 - pos.y) / 3.2f;

	window->DrawList->AddRect(ImVec2(pos.x + width, headPosition.y), ImVec2(pos.x - width, pos.y), color, rounding, 3);
}
void __fastcall _Renderer::DrawGapBox(float X, float Y, float W, float H, uint32_t Color)//缺口矩形
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float Div = W / 3;

	DrawLine(ImVec2(X, Y), ImVec2(X + Div, Y), Color);
	DrawLine(ImVec2(X, Y), ImVec2(X, Y + Div), Color);

	DrawLine(ImVec2(X + W - Div, Y), ImVec2(X + W, Y), Color);
	DrawLine(ImVec2(X + W, Y), ImVec2(X + W, Y + Div), Color);

	DrawLine(ImVec2(X, Y + H), ImVec2(X + Div, Y + H), Color);
	DrawLine(ImVec2(X, Y + H), ImVec2(X, Y + H - Div), Color);

	DrawLine(ImVec2(X + W - Div, Y + H), ImVec2(X + W, Y + H), Color);
	DrawLine(ImVec2(X + W, Y + H), ImVec2(X + W, Y + H - Div), Color);
}

float __fastcall _Renderer::OutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, uint32_t color, bool center)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	std::stringstream steam(text);
	std::string line;
	float y = 0.0f;
	int i = 0;

	while (std::getline(steam, line))
	{
		if (pFont == NULL)
			pFont = GImGui->Font;
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());
		if (center)
		{
			window->DrawList->AddText(pFont, size + 0.2f, ImVec2(pos.x - textSize.x / 2.0f - 1, pos.y + textSize.y * i - 1), color, line.c_str());
			window->DrawList->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), color, line.c_str());
		}
		else
		{
			window->DrawList->AddText(pFont, size + 0.2f, ImVec2(pos.x - 1, pos.y + textSize.y * i - 1), color, line.c_str());
			window->DrawList->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), color, line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}

	return y;
}

float __fastcall _Renderer::Text(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, uint32_t color, bool center)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	std::stringstream steam(text);
	std::string line;
	float y = 0.0f;
	int i = 0;

	while (std::getline(steam, line))
	{
		if (pFont == NULL)
			pFont = GImGui->Font;
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());
		if (center)
		{
			window->DrawList->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), color, line.c_str());
		}
		else
		{
			window->DrawList->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), color, line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}

	return y;
}

void __fastcall _Renderer::DrawLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	//VMProtectBegin(__FUNCTION__);
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddLine(from, to, color, thickness);
	//VMProtectEnd;
}

void __fastcall _Renderer::DrawShield(float X, float Y, float W, float H, float Shield, float MaxShield)
{
	uint32_t backcolor = 0x55010101;
	float progress = Shield / (MaxShield / 100);
	if (W <= 20)	W = 20.1;
	float w = W / 100 * progress;

	uint32_t color = 0xffffF8F8;
	if (progress >= 20) color = 0xffED9564;
	if (progress >= 40) color = 0xFFCD5A6A;
	if (progress >= 60) color = 0xFFE22B8A;
	if (progress >= 80) color = 0xFFFF00FF;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddRectFilled(ImVec2(X, Y), ImVec2(X + W, Y + H), backcolor, 5);//最大血量黑色
	window->DrawList->AddRectFilled(ImVec2(X - 1, Y), ImVec2(X + w, Y + H), color, 5);
}
void __fastcall _Renderer::DrawHealth(float X, float Y, float W, float H, float Health, float MaxHealth)
{
	VMProtectBegin(__FUNCTION__);
	uint32_t backcolor = 0x55010101;
	float progress = Health / (MaxHealth / 100);
	if (W <= 20)	W = 20.1;
	float w = W / 100 * progress;

	uint32_t color = 0xFF0000FF;
	if (progress >= 20) color = 0xFF008CFF;
	if (progress >= 40) color = 0xFF00FFFF;
	if (progress >= 60) color = 0xFF00d090;
	if (progress >= 80) color = 0xFF00FF00;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddRectFilled(ImVec2(X, Y), ImVec2(X + W, Y + H), backcolor, 5);//最大血量黑色
	window->DrawList->AddRectFilled(ImVec2(X - 1, Y), ImVec2(X + w, Y + H), color, 5);
	VMProtectEnd;
}

void __fastcall _Renderer::DrawMultiHealth(float X, float Y, float W, float H, float Health, float MaxHealth, uint32_t col_left, uint32_t col_right)
{
	if (H < 1.5) H = 1.5;

	uint32_t backcolor = 0xFF010101;
	float progress = Health / (MaxHealth / 100);
	if (W <= 20)	W = 21;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddRectFilledMultiColor(ImVec2(X, Y), ImVec2(X + W, Y + H), col_left, col_right, col_right, col_left);
	window->DrawList->AddRectFilled(ImVec2((X + W) - (W - (W / 100 * progress)), Y), ImVec2(X + W, Y + H), backcolor);
}

void __fastcall _Renderer::DrawCircle(const ImVec2& position, float radius, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircle(position, radius, color, 12, thickness);
}

void _Renderer::DrawCircleScale(const ImVec2& position, float radius, uint32_t color, const ImVec2& scalepos, const ImVec2& scaleheadPosition, float thickness)
{
	float rad = (scaleheadPosition.y + 15 - scalepos.y) / 10.5f;
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircle(position, rad, color, 12, thickness);
}

void _Renderer::DrawCircleFilled(const ImVec2& position, float radius, uint32_t color)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircleFilled(position, radius, color, 12);
}
void __fastcall _Renderer::DrawIco(ImVec2 pos, ImVec2 size, PVOID64 Buff, uint32_t color)
{
	VMProtectBegin(__FUNCTION__);
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (!Buff)return;
	if (!color)return;
	ImGui::GetOverlayDrawList()->AddImage(Buff, pos, ImVec2(pos.x + size.x, pos.y + size.y), ImVec2(0, 0), ImVec2(1, 1), color);
	VMProtectEnd;
}