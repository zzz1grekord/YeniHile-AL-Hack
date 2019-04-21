#include "stdafx.h"
#include "AimBot.h"

_AimBot* _AimBot::m_pInstance;
string a1 = CProcess.StringToUtf8(XORSTR("a1"));
string a2 = CProcess.StringToUtf8(XORSTR("a2"));
string a3 = CProcess.StringToUtf8(XORSTR("a3"));
string a4 = CProcess.StringToUtf8(XORSTR("a4"));
string T鍵 = CProcess.StringToUtf8(XORSTR("T-鍵"));
string F鍵 = CProcess.StringToUtf8(XORSTR("F-鍵"));
string Shirt鍵 = CProcess.StringToUtf8(XORSTR("Shirt"));
string Ctrl键 = CProcess.StringToUtf8(XORSTR("Ctrl"));

string a5 = CProcess.StringToUtf8(XORSTR("頭"));
string a6 = CProcess.StringToUtf8(XORSTR("脖"));
string a7 = CProcess.StringToUtf8(XORSTR("身"));
string a8 = CProcess.StringToUtf8(XORSTR("a8"));

const char* iKeyText[] = {a1.c_str(),a2.c_str()
, a3.c_str(), a4.c_str(),T鍵.c_str(),F鍵.c_str()};

const char* iPosText[] = { a5.c_str(),a6.c_str(), a7.c_str(), a8.c_str() };

const char* iSKeyText[] = { Shirt鍵.c_str(),Ctrl键.c_str()
, a3.c_str(), a4.c_str(),T鍵.c_str(),F鍵.c_str() };

void __fastcall _AimBot::Manu()
{
	VMProtectBegin(__FUNCTION__);
	auto& style = ImGui::GetStyle();
	if (!mMenu)
	{
		mMenu = new MenuItem;
		mMenu->DisplayName = CProcess.StringToUtf8(XORSTR("AimBot"));
		mMenu->IsMenu = false;
		mMenu->Id = Menu->ItemMenu.size();
		Menu->ItemMenu.push_back(mMenu);
	}
	else
	{
		if (mMenu->IsMenu)
		{
			style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0);
			auto tmp = style.Colors[ImGuiCol_Text];
			style.Colors[ImGuiCol_Text] = ImColor(255, 255, 100);
			ImGui::Begin(mMenu->DisplayName.c_str(),&mMenu->IsMenu, ImVec2(200, 200), 0.70, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
			{
				ImGui::Text(CProcess.StringToUtf8(XORSTR("Aimbot:")).c_str());
				ImGui::Separator();
				{
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("內存瞄準")).c_str(), &bAimBot);
					ImGui::SameLine(0, 60);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("無後坐力")).c_str(), &bRecoil);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("倒地不瞄")).c_str(), &bKneelDown);
					//if (ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("超級加速")).c_str(), &bSpeed))
					//{
					//	GameManager::SpeedInt(bSpeed, iSpeed);
					//}
					//if (IsValid(CProcess._pBase))
					//{
					//	DWORD old;
					//	__int64 address = CProcess._pBase + (int)Game::gVoidMemory + 0xb0;
					//	VirtualProtect((LPVOID)address, 8, PAGE_EXECUTE_READWRITE, &old);
					//	Write<double>(address, iSpeed*0.01);
					//	VirtualProtect((LPVOID)address, 8, old, &old);
					//}
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("瞄準鍵/部位")).c_str());
				{
					ImGui::PushItemWidth(75);

					ImGui::Combo(CProcess.StringToUtf8(XORSTR("瞄準鍵")).c_str(), &iKey, iKeyText, IM_ARRAYSIZE(iKeyText));
					//ImGui::SameLine(0, 15);
					//ImGui::Combo(u8"按键2", &iKey2, u8"左键\0右键\0侧键1\0侧键2\0T键\0F键\0\0\0\0");

					ImGui::Combo(CProcess.StringToUtf8(XORSTR("瞄準部位")).c_str(), &iPos,iPosText , IM_ARRAYSIZE(iPosText));
					//ImGui::SameLine(0, 15);
					//ImGui::Combo(u8"部位2", &iPos2, u8"头部\0颈部\0a7\0随机\0\0\0\0");
			/*		ImGui::Combo(CProcess.StringToUtf8(XORSTR("加速鍵")).c_str(), &iSKey, iSKeyText, IM_ARRAYSIZE(iSKeyText));*/
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("瞄准范围:")).c_str());
				{
					ImGui::PushItemWidth(189);
					ImGui::SliderFloat(CProcess.StringToUtf8(XORSTR("M", )).c_str(),&fFov, 0, 800, (CProcess.StringToUtf8(XORSTR("%.0f")).c_str()));
					ImGui::SliderFloat(CProcess.StringToUtf8(XORSTR("预判高度", )).c_str(), &fHeight, 0, 20, (CProcess.StringToUtf8(XORSTR("%.2f")).c_str()));

					/*	ImGui::SliderFloat(u8"预判高度2", &fHeight2, 0, 20, "%.2f");*/

					ImGui::SliderInt(CProcess.StringToUtf8(XORSTR("压枪左右")).c_str(), &iRecoilX, 1, 100);
					ImGui::SliderInt(CProcess.StringToUtf8(XORSTR("压枪上下")).c_str(), &iRecoilY, 1, 100);
					ImGui::Text(CProcess.StringToUtf8(XORSTR("压枪数值越大幅度越大")).c_str());
					ImGui::Text(CProcess.StringToUtf8(XORSTR("预判数值对应抬枪")).c_str());
					ImGui::Text(CProcess.StringToUtf8(XORSTR("预判数值越大,抬枪得越高")).c_str());
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("颜色：")).c_str());
				{
					ImGui::PushItemWidth(150);
					ImGui::ColorEdit3(CProcess.StringToUtf8(XORSTR("自喵色")).c_str(), (float*)&cAim);
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("FL唯一正版網盤")).c_str());
				ImGui::Text(CProcess.StringToUtf8(XORSTR("ApexFL.cccpan.com密碼6666")).c_str());
				ImGui::Separator();
			}ImGui::End();
			style.Colors[ImGuiCol_Text] = tmp;
		}
	}
	VMProtectEnd;
}

_AimBot* _AimBot::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new _AimBot();

	return m_pInstance;
}