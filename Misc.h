#pragma once
#define Misc _Misc::GetInstance()
class _Misc
{
public:
	void __fastcall		Manu();

	bool bAutoAmmo = false,//子弹
		bGrenades = false,//手雷
		bEquip = true,//防具
		bItems = false,//消耗物品
		bParts = false,//配件
		bNrg = false,//能量武器
		bHc = true,//重型武器
		bSc = true,//轻型武器
		bShg = false,//霰弹武器
		bLoot = true,//战利品
		bTrap = false,//传送门
		bDistance = true;//物品距离


	int iItemsShow = 50;

	MenuItem *mMenu = 0;
	ImVec4 
		cEquip = ImColor(0, 255, 0),
		cParts = ImColor(0, 255, 0),
		cLoot = ImColor(0, 255, 0),
		cNrg = ImColor(0xAD, 0xFF, 0x2F),
		cHc = ImColor(0, 255, 255),
		cShg = ImColor(200, 5, 0),
		cSc = ImColor(255, 70, 0),

		cItems = ImColor(0, 0, 255),
		cGrenades = ImColor(200, 200, 200),

		cItemsCommon = ImColor(182, 182, 182),
		cItemsRare = ImColor(87, 179, 230),
		cItemsEpic = ImColor(197, 76, 249),
		cItemsLegendary = ImColor(251, 201, 58);


	static _Misc* GetInstance();

private:

	static _Misc* m_pInstance;
};

