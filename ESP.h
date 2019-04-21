#pragma once
#define ESP _ESP::GetInstance()
class _ESP
{
public:

	void __fastcall		Manu();
	bool b2DBox = true,//·½¿ò
		bTeam = false,
		bDistance = true,
		bHealth = true,
		bName = false,
		bBone = true,
		
		
		bHero = true;

	int iPlayerShow = 600;
	

	ImVec4 cPlayer = ImColor(255, 255, 0),
		cTeam = ImColor(0, 255, 0),
		cDead = ImColor(255, 0, 0),
		cBuild = ImColor(255, 255, 255);



	MenuItem *mMenu = 0;

	static _ESP* GetInstance();

private:

	static _ESP* m_pInstance;
};
