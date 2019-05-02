#pragma once
class DirectX
{
public:
	IDXGISwapChain* m_swapChain; //Swap chain objects
	ID3D11Device* m_device;  //Device objects
	ID3D11DeviceContext* m_deviceContext; //Device context object
	ID3D11RenderTargetView* m_renderTargetView; //Render target view

	static DirectX* __fastcall GetInstance();
	char* __fastcall GetCardDescription();
	int __fastcall GetCardMemory();
	void __fastcall  EndScene();

	void __fastcall CreateRenderTarget();
	void __fastcall CleanupRenderTarget();
	bool __fastcall Initialize(int, int, bool, HWND);
	void __fastcall CleanupDevice();

private:
	DirectX();
	bool m_vsync_enabled; //Whether Vertical Sync is enabled
	int m_videoCardMemory; //Memory size
	char m_videoCardDescription[128]; //Video card name

	static DirectX* m_pInstance;
};
