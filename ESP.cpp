#include "stdafx.h"
#include "ESP.h"



_ESP* _ESP::m_pInstance;
void __fastcall _ESP::Manu()
{
	VMProtectBegin(__FUNCTION__);
	auto& style = ImGui::GetStyle();
	if (!mMenu)
	{
		mMenu = new MenuItem;
		mMenu->DisplayName = CProcess.StringToUtf8(XORSTR("ESP"));
		mMenu->IsMenu = false;
		mMenu->Id = Menu->ItemMenu.size();
		Menu->ItemMenu.push_back(mMenu);
	}
	else
	{
		if (mMenu->IsMenu)
		{
			style.Colors[ImGuiCol_WindowBg] = ImColor(0,0,0);
			auto tmp= style.Colors[ImGuiCol_Text];
			style.Colors[ImGuiCol_Text] = ImColor(255,255,100);
			ImGui::Begin(mMenu->DisplayName.c_str(), &mMenu->IsMenu, ImVec2(200, 200), 0.70, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
			{
				ImGui::Text(CProcess.StringToUtf8(XORSTR("BOX:")).c_str());
				ImGui::Separator();
				{
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("方塊")).c_str(), &b2DBox);
					ImGui::SameLine(0, 25);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("隊友")).c_str(), &bTeam);
					ImGui::SameLine(0, 35);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("距離")).c_str(), &bDistance);

					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("血量")).c_str(), &bHealth);
					ImGui::SameLine(0, 25);
					//ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("名字")).c_str(), &bName);				
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("英雄")).c_str(), &bHero);
					ImGui::SameLine(0, 35);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("骨骼")).c_str(), &bBone);

				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("显示范围:")).c_str());
				{
					ImGui::PushItemWidth(179);
					ImGui::SliderInt(CProcess.StringToUtf8(XORSTR("M")).c_str(), &iPlayerShow, 0, 600);
					ImGui::PopItemWidth();
				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("颜色：")).c_str());
				{
					ImGui::PushItemWidth(150);
					ImGui::ColorEdit3(CProcess.StringToUtf8(XORSTR("方框颜色")).c_str(), (float*)&cPlayer);
					ImGui::PopItemWidth();
					ImGui::PushItemWidth(150);
					ImGui::ColorEdit3(CProcess.StringToUtf8(XORSTR("可见敌人颜色")).c_str(), (float*)&cTeam);
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

_ESP* _ESP::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new _ESP();

	return m_pInstance;
}