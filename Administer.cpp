#include "stdafx.h"
#include "Administer.h"

bool tEntity;
list <DrawEntity>Players = list <DrawEntity>();
list <DrawEntity>Items = list <DrawEntity>();
list <LootInfo>Loot = list <LootInfo>();
// //////////////////////////////////////////////////////////////Поток & рисовать
extern list <DrawEntity>tPlayers;
extern list <DrawEntity>tItems;
extern list <LootInfo>tLoot;
extern DrawEntity Local;
extern BOOL isLogin;
void __fastcall _Administer::ThreadManager()
{
	VMProtectBegin(__FUNCTION__);
	while (true)
	{
		auto pArray = GameManager::GetEntityList();
		Local = GameManager::GetLocalPlayer();
		if (!tEntity)
		{
			GameManager::ReadEntity(pArray);
			tEntity = true;
		}
		Sleep(1);
	}
	VMProtectEnd;
}
bool __fastcall is_entity_alive(int64_t ent)
{
	bool result; // al@2

	if (*(byte *)(ent + 80) & 1)
		result = 0;
	else
		result = *(byte *)(ent + 1816) == 0;
	return result;
}
void __fastcall _Administer::StartThreadManager()
{
	hManager = CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(ThreadManager), NULL, NULL, NULL);
}

void __fastcall Draw()
{
	VMProtectBegin(__FUNCTION__);
	auto pView = GameManager::GetView();
	float AimMax = 9999999;
	float AimMax1 = 9999999;
	Vector3 Position, HeadPosition;
	ImVec2 DrawPosition, DrawHeadPosition;
	float Health, MaxHealth, Shield, MaxShield, Dis;

	for (auto i = Players.begin(); i != Players.end(); i++)
	{
		auto dead = i->IsDead();
		if (dead)continue;

		Position = i->GetMinPos();
		HeadPosition = Position;
		Dis = pView.m_Pos.distance(Position)*0.01905f;
		if (ESP->iPlayerShow)
		{
			if (Dis > ESP->iPlayerShow)continue;
		}

		if (!ESP->bTeam)
		{
			if (i->IsTeam())continue;
		}
		else
		{
			if (i->IsTeam())
				i->Col = (ImColor)ESP->cTeam;
		}
		if (i->IsbKneelDown())i->Col = (ImColor)ESP->cDead;

		i->DrawBones(pView, HeadPosition, i->Col);
		DrawHeadPosition = ImVec2(HeadPosition.x, HeadPosition.y - 4);
		if (pView.WorldToScreen(Position, DrawPosition))
		{
			//if (i->Col == ImColor(ESP->cTeam))
			//{
			//	i->GetClosestPlayerToCrossHair(Vector3(DrawHeadPosition.x, DrawHeadPosition.y, 0), AimMax);
			//}
			i->GetClosestPlayerToCrossHair(Vector3(DrawHeadPosition.x, DrawHeadPosition.y, 0), AimMax);
			float Draw_h = (DrawHeadPosition.y - DrawPosition.y);
			float Draw_w = Draw_h / 2;
			float Draw_x = DrawPosition.x - Draw_w / 2;
			float h = (DrawPosition.y - DrawHeadPosition.y);
			float w = h / 2;
			float x = DrawPosition.x - w / 2;
			if (ESP->b2DBox)
				Renderer.DrawGapBox(Draw_x, DrawPosition.y, Draw_w, Draw_h, i->Col);
			if (ESP->bHealth)
				if (i->GetShield(Shield, MaxShield))
				{
					Renderer.DrawShield(x, DrawHeadPosition.y - 5, w, 2.5f, Shield, MaxShield);
				}
				else
				{
					i->GetHealth(Health, MaxHealth);
					Renderer.DrawHealth(x, DrawHeadPosition.y - 5, w, 2.5f, Health, MaxHealth);
				}
			i->DrawInfo(ImVec2(x, DrawPosition.y), Dis, i->Col, ESP->bName, ESP->bHero, ESP->bDistance);
		}
		continue;
	}

	byte bLootSize[MAXBYTE] = { 0 };
	ZeroMemory(bLootSize, MAXBYTE);
	for (auto i = Items.begin(); i != Items.end(); i++)
	{
		if (Misc->bAutoAmmo)
		{
			if (Local.Weapon.Ammo == 29)
			{
				if (i->ID == 28) continue;
				if (i->ID == 31) continue;
				if (i->ID == 30) continue;
			}
			if (Local.Weapon.Ammo == 28)
			{
				if (i->ID == 29) continue;
				if (i->ID == 31) continue;
				if (i->ID == 30) continue;
			}
			if (Local.Weapon.Ammo == 31)
			{
				if (i->ID == 28) continue;
				if (i->ID == 29) continue;
				if (i->ID == 30) continue;
			}
			if (Local.Weapon.Ammo == 30)
			{
				if (i->ID == 28) continue;
				if (i->ID == 31) continue;
				if (i->ID == 29) continue;
			}
			if (Local.Weapon.Ammo == -1)
			{
				if (i->ID == 28) continue;
				if (i->ID == 31) continue;
				if (i->ID == 30) continue;
				if (i->ID == 29) continue;
			}
		}
		Position = i->GetMinPos();

		Dis = pView.m_Pos.distance(Position)*0.01905f;
		if (Misc->iItemsShow)
		{
			if (Dis > Misc->iItemsShow)continue;
		}
		if (pView.WorldToScreen(Position, DrawPosition))
		{
			bool bDis = Misc->bDistance;
			if (i->Name != CProcess.StringToUtf8(XORSTR("Booty")).c_str())
			{
				int iLootSize = 0;

				for (auto p = Loot.begin(); p != Loot.end(); p++)
				{
					if (Position.distance(p->Pos) < 5)
					{
						if (!Misc->bLoot)continue;
						bLootSize[iLootSize] += 1;
						DrawPosition.y -= 15 * bLootSize[iLootSize];
						bDis = false;
					}
					iLootSize++;
				}
			}

			if (i->pSBuf)
			{
				int a = (160 - (int((Dis / (float)(Misc->iItemsShow + 1)) * 100) & 0xff)) << 24;
				int c = i->Col & 0xfffffff;

				if (i->ID == 5 | i->ID == 3 | i->ID == 7 | i->ID == 10 | i->ID == 12 | i->ID == 18 | i->ID == 20 | i->ID == 24 |
					i->ID == 21 | i->ID == 1 | i->ID == 0 | i->ID == 9 | i->ID == 13 | i->ID == 17 | i->ID == 8 | i->ID == 15)
				{
					Renderer.DrawIco(ImVec2(DrawPosition.x - 47, DrawPosition.y + 4), ImVec2(50, 16), i->pSBuf, a + c);
				}
				else
				{
					Renderer.DrawIco(ImVec2(DrawPosition.x - 17, DrawPosition.y + 2), ImVec2(20, 20), i->pSBuf, a + c);
				}
				i->DrawInfo(DrawPosition, Dis, a + c, false, false, bDis);
				continue;
			}
			i->DrawInfo(DrawPosition, Dis, i->Col, ESP->bName, false, bDis);
		}
	}

	if (tEntity == true)
	{
		Players = tPlayers;
		Items = tItems;
		Loot = tLoot;
		tItems.clear();
		tPlayers.clear();
		tLoot.clear();
		tEntity = false;
	}
	VMProtectEnd;
}

ID3D11Device *pDevice;
ID3D11DeviceContext *pContext;
ID3D11RenderTargetView* pRenderTargetView;
ID3D11Texture2D* renderTargetTexture = nullptr;
HRESULT __stdcall MyPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	VMProtectBegin(__FUNCTION__);
	if (!isLogin)
	{
		return GameManager::phookD3D11Present(pSwapChain, SyncInterval, Flags);
	}
	ImGuiIO io = ImGui::GetIO();

	if (ImGui::IsKeyPressed(VK_INSERT))
	{
		Menu->IsMenu = !Menu->IsMenu;
	}
	if (ImGui::IsKeyPressed(VK_OEM_3))//一Key to cancel
	{
		Misc->bAutoAmmo = false;
		Misc->bGrenades = false;
		Misc->bEquip = false;
		Misc->bItems = false;
		Misc->bParts = false;
		Misc->bNrg = false;
		Misc->bHc = false;
		Misc->bSc = false;
		Misc->bShg = false;
	}

	if (!pDevice | !pContext)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void **)&pDevice)))
		{
			pSwapChain->GetDevice(__uuidof(pDevice), (void**)&pDevice);
			pDevice->GetImmediateContext(&pContext);
		}
		Renderer.ShaderResourceIni(pDevice);
		ImGui_ImplDX11_Init(CProcess.pWinhWnd, pDevice, pContext);
	}
	else
	{
		if (!pRenderTargetView)
		{
			if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&renderTargetTexture))))
			{
				pDevice->CreateRenderTargetView(renderTargetTexture, NULL, &pRenderTargetView);
				renderTargetTexture->Release();
			}
		}
		ImGui_ImplDX11_NewFrame();

		Renderer.BeginScene();
		Draw();
		GameManager::GameAimBot();
		Renderer.EndScene();
		Menu->Render();

		ImGui::Render();
		pContext->OMSetRenderTargets(1, &pRenderTargetView, NULL);

		if (pRenderTargetView)
		{
			pRenderTargetView->Release();
			pRenderTargetView = 0;
		}
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	return GameManager::phookD3D11Present(pSwapChain, SyncInterval, Flags);
	VMProtectEnd;
}
