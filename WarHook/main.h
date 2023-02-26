#pragma once
#include "includes.h"
#include "math.h"
#include "font.h"
#include "classes.h"
#include "sigs.h"
#include "sigScanner.h"


bool offscreen = false;
bool agree = false;
bool open = true;
bool tab_esp = false;
bool tab_misc = false;
bool tab_support = false;
bool def_tab = true;
bool def_choice = false;

bool esp_status = false;
bool remove_nature = false;
bool remove_smokes = false;
bool show_reload = false;
bool show_bots = false;
bool show_planes = false;
bool show_offscreen = false;

bool zoom_mod = false;
bool change_hud = false;
bool force_crosshair = false;
bool force_outline = false;
bool force_distance = false;
bool force_bombsight = false;
bool force_air_to_air = false;

float off_arrow_size = 2.f;
float off_radius = 100.f;
float off_color[]{ 0.f,0.f,0.f };

float zoom_mult = 3.f;
float alt_mult = 12.f;
float shadow_mult = 20.f;

constexpr auto DEFAULT_ZOOM_MULT = 5.f;
constexpr auto DEFAULT_ALT_MULT = 15.f;
constexpr auto DEFAULT_SHADOW_MULT = 20.f;

constexpr float timestep = 1.f / 96.f;
constexpr float gravity = 9.81f;
bool DeleteTexture = true;

ID3D11DepthStencilState* DepthStencilState_FALSE = NULL; //depth off
ID3D11DepthStencilState* DepthStencilState_ORIG = NULL; //depth on

ID3D11RasterizerState* DEPTHBIASState_FALSE;
ID3D11RasterizerState* DEPTHBIASState_TRUE;
ID3D11RasterizerState* DEPTHBIASState_ORIG;
#define DEPTH_BIAS_D32_FLOAT(d) (d/(1/pow(2,23)))

//viewport
UINT vps = 1;
D3D11_VIEWPORT viewport;
float ScreenCenterX;
float ScreenCenterY;

//create rendertarget
ID3D11RenderTargetView* RenderTargetView = NULL;

//vertex
ID3D11Buffer* veBuffer;
UINT Stride;
UINT veBufferOffset;
D3D11_BUFFER_DESC vedesc;

//index
ID3D11Buffer* inBuffer;
DXGI_FORMAT inFormat;
UINT        inOffset;
D3D11_BUFFER_DESC indesc;

//psgetConstantbuffers
UINT pscStartSlot;
ID3D11Buffer* pscBuffer;
D3D11_BUFFER_DESC pscdesc;

//vsgetconstantbuffers
UINT vscStartSlot;
ID3D11Buffer* vscBuffer;
D3D11_BUFFER_DESC vscdesc;

//pssetshaderresources
UINT pssrStartSlot ;
ID3D11Resource* Resource;
D3D11_SHADER_RESOURCE_VIEW_DESC Descr;
D3D11_TEXTURE2D_DESC texdesc;

//wndproc
bool ShowMenu = false;
static WNDPROC OriginalWndProcHandler = nullptr;

//logger, misc
int countnum = 4;
int countStride = 12;
int countIndexCount = 18;
int countpscdescByteWidth = 768;
int countindescByteWidth = 16777216;
int countvedescByteWidth = 67108864;

wchar_t reportValue[256];
#define SAFE_RELEASE(x) if (x) { x->Release(); x = NULL; }
HRESULT hr;
