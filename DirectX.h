#pragma once
class DirectX
{
public:
	IDXGISwapChain* m_swapChain; //交换链对象
	ID3D11Device* m_device;  //设备对象
	ID3D11DeviceContext* m_deviceContext; //设备上下文对象
	ID3D11RenderTargetView* m_renderTargetView; //渲染目标视图

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
	bool m_vsync_enabled; //是否启用垂直同步
	int m_videoCardMemory; //显存大小
	char m_videoCardDescription[128]; //显卡名字

	static DirectX* m_pInstance;
};