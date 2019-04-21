#include "stdafx.h"
#include "DirectX.h"
DirectX::DirectX()
{
	m_swapChain = 0;
	m_device = 0;
	m_deviceContext = 0;
	m_renderTargetView = 0;
}


bool __fastcall DirectX::Initialize(int screenWidth, int screenHeight, bool vsync, HWND hwnd)
{
	HRESULT result;
	IDXGIFactory* factory;
	IDXGIAdapter* adapter;
	IDXGIOutput* adapterOutput;
	unsigned int numModes, i, numerator, denominator;
	DXGI_MODE_DESC* displayModeList;
	DXGI_ADAPTER_DESC adapterDesc;

	//D3D_FEATURE_LEVEL featureLevel;
	ID3D11Texture2D* backBufferPtr;


	m_vsync_enabled = vsync;	// 保存垂直同步设置
	// 创建一个DirectX graphics interface factory.
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(result))return false;


	// 用接口工厂创建一个主显卡的适配
	result = factory->EnumAdapters(0, &adapter);
	if (FAILED(result))return false;


	// 得到主适配器的输出.
	result = adapter->EnumOutputs(0, &adapterOutput);
	if (FAILED(result))	return false;


	//得到适合 DXGI_FORMAT_R8G8B8A8_UNORM 的显示模式.
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, NULL);
	if (FAILED(result))
	{
		return false;
	}

	displayModeList = new DXGI_MODE_DESC[numModes];
	if (!displayModeList)
	{
		return false;
	}

	// 保存显示模式到displayModeList中
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result))
	{
		return false;
	}

	//遍历所有显示模式，得到刷新率两个参数值numerator 和 denominato
	for (i = 0; i < numModes; i++)
	{
		if (displayModeList[i].Width == (unsigned int)screenWidth)
		{
			if (displayModeList[i].Height == (unsigned int)screenHeight)
			{
				numerator = displayModeList[i].RefreshRate.Numerator;
				denominator = displayModeList[i].RefreshRate.Denominator;
			}
		}
	}
	// 得到显卡描述
	result = adapter->GetDesc(&adapterDesc);
	if (FAILED(result))
	{
		return false;
	}
	m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);

	 sprintf(m_videoCardDescription, "%ws",  adapterDesc.Description);
	// 释放显示模式列表
	delete[] displayModeList;
	displayModeList = 0;

	//释放适配器输出.
	adapterOutput->Release();
	adapterOutput = 0;

	//释放适配器
	adapter->Release();
	adapter = 0;

	// 释放接口工厂.
	factory->Release();
	factory = 0;


	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	result = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, &featureLevel, &m_deviceContext);

	if (FAILED(result))
	{
		return false;
	}
	CreateRenderTarget();
	return true;
}

void __fastcall DirectX::EndScene()
{
	//渲染完成后，把后缓冲内容present到前缓冲
	if (m_vsync_enabled)
	{
		// 锁定屏幕刷新率.
		m_swapChain->Present(1, 0);
	}
	else
	{
		// 尽可能快的present后缓冲.
		m_swapChain->Present(0, 0);
	}
}

int __fastcall DirectX::GetCardMemory()
{
	return m_videoCardMemory;
}
char* __fastcall DirectX::GetCardDescription()
{
	return m_videoCardDescription;
}

void __fastcall DirectX::CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	m_device->CreateRenderTargetView(pBackBuffer, NULL, &m_renderTargetView);
	pBackBuffer->Release();
}
void __fastcall  DirectX::CleanupRenderTarget()
{
	if (m_renderTargetView) { m_renderTargetView->Release(); m_renderTargetView = NULL; }
}
void __fastcall DirectX::CleanupDevice()
{
		if (m_renderTargetView)
		{
			m_renderTargetView->Release();
			m_renderTargetView = 0;
		}
		if (m_swapChain)
		{
			m_swapChain->Release();
			m_swapChain = 0;
		}
		if (m_deviceContext)
		{
			m_deviceContext->Release();
			m_deviceContext = 0;
		}

		if (m_device)
		{
			m_device->Release();
			m_device = 0;
		}


}
DirectX* DirectX::m_pInstance;
DirectX* __fastcall DirectX::GetInstance()
{
		if (!m_pInstance)
			m_pInstance = new DirectX();
	return m_pInstance;
}