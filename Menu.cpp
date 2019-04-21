#include "stdafx.h"
#include "Menu.h"

_Menu* _Menu::m_pInstance;
_Menu::_Menu()
{
	VMProtectBegin(__FUNCTION__);
	TitleColor = ImColor(255, 0, 0);
	WindowColor = ImColor(0, 0, 0);
	DisplayName = (CProcess.StringToUtf8(XORSTR("FL -Insï@/ë[")).c_str());
	//DisplayName = (CProcess.StringToUtf8(XORSTR("FLÕý°æ¾W±P:ApexFL.cccpan.com ÃÜ´a6666")).c_str());
	IsMenu = true;
	VMProtectEnd;
}

void __fastcall _Menu::Render()
{
	//VMProtectBegin(__FUNCTION__);
	ImGuiIO& io = ImGui::GetIO();
	auto& style = ImGui::GetStyle();
	int W, H;
	W = io.DisplaySize.x;
	H = io.DisplaySize.y;
	static int e = -1;
	if (IsMenu)
	{
		style.Colors[ImGuiCol_WindowBg] = TitleColor;
		ImGui::Begin("#", &IsMenu, WindowPos, 0.80, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
		{
			ImGui::SetWindowSize(ImVec2(WindowSize.x, 30));
			WindowSize = ImGui::GetWindowSize();
			WindowPos = ImGui::GetWindowPos();
			Renderer.Text(NULL, DisplayName, ImVec2(WindowSize.x / 1.6 + WindowPos.x, WindowSize.y*0.1 + WindowPos.y), int(WindowSize.y*0.8), 0xffFF4500, true);
		}ImGui::End();

		ImGui::SetNextWindowPos(ImVec2(WindowPos.x, WindowPos.y + 33));
		style.Colors[ImGuiCol_WindowBg] = WindowColor;
		ImGui::Begin("##", &IsMenu, ImVec2(0, 0), 0.70f, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
		{
			ImGui::SetWindowSize(ImVec2(WindowSize.x - 20, ItemMenu.size() * 38));
			WindowSize = ImGui::GetWindowSize();
			WindowPos = ImGui::GetWindowPos();
			for (auto i = ItemMenu.begin(); i != ItemMenu.end(); i++)
			{
				ImGui::RadioButton((*i)->DisplayName.c_str(), &e, (*i)->Id);
				ImGui::SameLine(0, 20);
				if (e == (*i)->Id)
				{
					(*i)->IsMenu = true;
				}
				else (*i)->IsMenu = false;
			}
		}ImGui::End();
		ImGui::SetNextWindowPos(ImVec2(WindowPos.x, WindowPos.y + WindowSize.y + 1));
		ESP->Manu();
		AimBot->Manu();
		Misc->Manu();
		
	}
	else  e = -1;
	//VMProtectEnd;
}

_Menu* _Menu::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new _Menu();

	return m_pInstance;
}