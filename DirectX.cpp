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


	m_vsync_enabled = vsync;	// Saving vertical sync settings
	// Create a DirectX graphics interface factory.
	result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
	if (FAILED(result))return false;


	// Create an adapter for the main graphics card with the interface factory
	result = factory->EnumAdapters(0, &adapter);
	if (FAILED(result))return false;


	// Get the output of the main adapter.
	result = adapter->EnumOutputs(0, &adapterOutput);
	if (FAILED(result))	return false;


	//Get fit DXGI_FORMAT_R8G8B8A8_UNORM The display mode.
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

	// Save the display mode to displayModeList Medium
	result = adapterOutput->GetDisplayModeList(DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_ENUM_MODES_INTERLACED, &numModes, displayModeList);
	if (FAILED(result))
	{
		return false;
	}

	//Iterate through all display modes to get the refresh rate for two parameter values numerator And denominato
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
	// Get the video card description
	result = adapter->GetDesc(&adapterDesc);
	if (FAILED(result))
	{
		return false;
	}
	m_videoCardMemory = (int)(adapterDesc.DedicatedVideoMemory / 1024 / 1024);

	 sprintf(m_videoCardDescription, "%ws",  adapterDesc.Description);
	// Release the display mode list
	delete[] displayModeList;
	displayModeList = 0;

	//Release adapter output.
	adapterOutput->Release();
	adapterOutput = 0;

	//Release adapter
	adapter->Release();
	adapter = 0;

	// Release the interface factory.
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
	//After the dye is completed, put the contents of the buffer present To the front buffer
	if (m_vsync_enabled)
	{
		// Lock screen refresh rate.
		m_swapChain->Present(1, 0);
	}
	else
	{
		//  As fast as you can. present After buffering.
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
