#pragma once
#define AimBot _AimBot::GetInstance()
class _AimBot
{
public:
	void __fastcall		Manu();
	int		iKey = 1,
		iKey2 = 2,
		iSKey = 0,
		iType = 0,
		iPos = 0,
		iPos2 = 2;

	bool	bAimBot = true,
		bAimBot2 = false,
		bRecoil = true,
		bSpeed = false,
		bKneelDown = true;

	float	fFov = 200,
		fHeight = 18,
		fHeight2 = 0;
	int	iRecoilX = 8,
		iRecoilY = 5,
		iSpeed = 18;


	ImVec4 cAim = ImColor(255, 0, 255);

	MenuItem *mMenu = 0;
	static _AimBot* GetInstance();

private:

	static _AimBot* m_pInstance;
};
