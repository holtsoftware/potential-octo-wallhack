#pragma once
#include <fstream>

using namespace Microsoft::WRL;
using namespace Windows::UI::Core;
using namespace Platform;
using namespace DirectX;

Array<byte>^ LoadShaderFile(std::string File);

class Game
{
protected:
	ComPtr<ID3D11Device1> dev;              // the device interface
	ComPtr<ID3D11DeviceContext1> devcon;    // the device context interface
	ComPtr<IDXGISwapChain1> swapchain;      // the swap chain interface
	ComPtr<ID3D11RenderTargetView> rendertarget;    // added to the CGame class
	ComPtr<ID3D11Buffer> vertexbuffer;
	ComPtr<ID3D11VertexShader> vertexshader;
	ComPtr<ID3D11PixelShader> pixelshader;
	ComPtr<ID3D11InputLayout> inputlayout;    // the input layout interface


public:
	void Initialize();
	void Update();
	void Render();
	void InitGraphics();
	void InitPipeline();
};
