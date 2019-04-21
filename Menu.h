#pragma once
#include "MenuItem.h"
#define Menu _Menu::GetInstance()
class _Menu
{
public:
	_Menu();
	ImColor TitleColor;
	ImColor WindowColor;
	string DisplayName;
	bool IsMenu;
	list<MenuItem*>ItemMenu;
	ImVec2 WindowPos;
	ImVec2 WindowSize;
	void __fastcall Render();

	static _Menu* GetInstance();



private:

	static _Menu* m_pInstance;
};

