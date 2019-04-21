#include "stdafx.h"
#include "Misc.h"
_Misc* _Misc::m_pInstance;

void __fastcall _Misc::Manu()
{
	VMProtectBegin(__FUNCTION__);
	auto& style = ImGui::GetStyle();
	if (!mMenu)
	{
		mMenu = new MenuItem;
		mMenu->DisplayName = CProcess.StringToUtf8(XORSTR("Misc"));
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
			style.Colors[ImGuiCol_Text] = ImColor(255, 69, 0);
			ImGui::Begin(mMenu->DisplayName.c_str(),&mMenu->IsMenu, ImVec2(200, 200), 0.70, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
			{
				ImGui::Text(CProcess.StringToUtf8(XORSTR("【戰鬥模式:~鍵】")).c_str());
				ImGui::Separator();
				{
				  
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("裝備護肩")).c_str(), &bEquip);
					ImGui::SameLine(0, 60);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("自動彈藥")).c_str(), &bAutoAmmo);
					
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("投擲品")).c_str(), &bGrenades);
					ImGui::SameLine(0, 75);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("藥品")).c_str(), &bItems);

					ImGui::Text(CProcess.StringToUtf8(XORSTR("武器欄目：")).c_str());
					{
						ImGui::PushItemWidth(179);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("重型槍")).c_str(), &bHc);
					ImGui::SameLine(0, 75);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("輕型槍")).c_str(), &bSc);
					
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("霞彈槍")).c_str(), &bShg);
					ImGui::SameLine(0, 75);
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("能量槍")).c_str(), &bNrg );
						ImGui::PopItemWidth();
					}
					ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("配件")).c_str(), &bParts);
					ImGui::SameLine(0, 75);
					//ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("LOOT")).c_str(), &bLoot);

					//ImGui::Checkbox(CProcess.StringToUtf8(XORSTR("传送门/毒气")).c_str(), &bTrap);
					

				}
				ImGui::Separator();
				ImGui::Text(CProcess.StringToUtf8(XORSTR("显示范围:")).c_str());
				{
					ImGui::PushItemWidth(179);
					ImGui::SliderInt(CProcess.StringToUtf8(XORSTR("M")).c_str(), &iItemsShow, 0, 200);
					ImGui::Text(CProcess.StringToUtf8(XORSTR("智能子弹开启后")).c_str());
					ImGui::Text(CProcess.StringToUtf8(XORSTR("手中拿的是什么类型武器")).c_str());
					ImGui::Text(CProcess.StringToUtf8(XORSTR("自动显示手中武器子弹")).c_str());
					//ImGui::Text(CProcess.StringToUtf8(XORSTR("传送门/毒气,会透視傳送門地點")).c_str());

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

_Misc* _Misc::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new _Misc();

	return m_pInstance;
}