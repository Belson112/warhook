#include "includes.h"
#include "main.h"
#include "math.h"
#include "classes.h"
#include "font.h"

constexpr auto off_cGame = 0x4318E28;
constexpr auto off_localplayer = 0x41E9DE8;
constexpr auto off_isScoping = 0x41E3F68;
constexpr auto off_scrW = 0x436C8A0;
constexpr auto off_scrH = 0x436C8A4;

	
void SetupImGuiStyle()
{
	ImGui::GetStyle().FrameRounding = 6.f;
	ImGui::GetStyle().WindowBorderSize = 0.f;
	ImGui::GetStyle().ChildBorderSize = 0.f;
	ImGui::GetStyle().WindowTitleAlign.x = 0.5f;
	ImGui::GetStyle().WindowTitleAlign.y = 0.4f;
	ImGui::GetStyle().TabRounding = 0.f;
	ImGui::GetStyle().WindowPadding.x = 0.f;


	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.09f, 0.07f, 0.11f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.17f, 0.14f, 0.22f, 0.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.17f, 0.14f, 0.22f, 0.72f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.17f, 0.14f, 0.22f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.31f, 0.15f, 0.31f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.79f, 0.15f, 0.81f, 0.79f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.02f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 0.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	colors[ImGuiCol_Tab] = ImVec4(0.49f, 0.10f, 0.51f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.79f, 0.15f, 0.81f, 0.78f);
	colors[ImGuiCol_TabActive] = ImVec4(0.79f, 0.15f, 0.81f, 1.00f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 0.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

}

float Distance(Vector3 target, Vector3 localplayer)
{
	float distance = std::sqrtf((target.x - localplayer.x) * (target.x - localplayer.x) +
		(target.y - localplayer.y) * (target.y - localplayer.y) +
		(target.z - localplayer.z) * (target.z - localplayer.z)) * 0.001f;
	return distance;
}

uintptr_t modulebase = (uintptr_t)GetModuleHandle(NULL);
uintptr_t cGame = *(uintptr_t*)(modulebase + off_cGame);
const int scrW = *(int*)(modulebase + off_scrW);
const int scrH = *(int*)(modulebase + off_scrH);

const Vector2 scrsize = { (float)scrW,(float)scrH };
bool WorldToScreen(const Vector3& in, Vector3& out) noexcept
{
	const ViewMatrix& mat = *(ViewMatrix*)(cGame + 0x760);
	
	float width = mat[0][3] * in.x + mat[1][3] * in.y + mat[2][3] * in.z + mat[3][3];

	bool visible = width >= 0.1f;
	if (!visible)
		return false;
	else
		width = 1.0 / width;

	float x = in.x * mat[0][0] + in.y * mat[1][0] + in.z * mat[2][0] + mat[3][0];
	float y = in.x * mat[0][1] + in.y * mat[1][1] + in.z * mat[2][1] + mat[3][1];
	float z = in.x * mat[0][2] + in.y * mat[1][2] + in.z * mat[2][2] + mat[3][2];

	float nx = x * width;
	float ny = y * width;
	float nz = z * width;


	out.x = (scrsize.x / 2 * nx) + (nx + scrsize.x / 2);
	out.y = -(scrsize.y / 2 * ny) + (ny + scrsize.y / 2);
	out.z = nz;
	
	return true;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
ImFont* def_main;
ImFont* med_main;
ImFont* big_main;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	def_main = io.Fonts->AddFontFromMemoryTTF(myfont, sizeof(myfont),15.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
	med_main = io.Fonts->AddFontFromMemoryTTF(myfont, sizeof(myfont), 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
	big_main = io.Fonts->AddFontFromMemoryTTF(myfont, sizeof(myfont), 30.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
	ImGui::GetIO().Fonts->Build();
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	io.IniFilename = NULL;
	SetupImGuiStyle();
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}


void draw3dbox(Matrix3x3 rotation, Vector3 bbmin, Vector3 bbmax, Vector3 position, float Invulnerable)
{
	Vector3 ax[6];
	ax[0] = Vector3{ rotation[0][0], rotation[0][1], rotation[0][2] }.Scale(bbmin.x);
	ax[1] = Vector3{ rotation[1][0], rotation[1][1], rotation[1][2] }.Scale(bbmin.y);
	ax[2] = Vector3{ rotation[2][0], rotation[2][1], rotation[2][2] }.Scale(bbmin.z);
	ax[3] = Vector3{ rotation[0][0], rotation[0][1], rotation[0][2] }.Scale(bbmax.x);
	ax[4] = Vector3{ rotation[1][0], rotation[1][1], rotation[1][2] }.Scale(bbmax.y);
	ax[5] = Vector3{ rotation[2][0], rotation[2][1], rotation[2][2] }.Scale(bbmax.z);

	Vector3 temp[6];
	temp[0] = position + ax[2];
	temp[1] = position + ax[5];
	temp[2] = temp[0] + ax[3];
	temp[3] = temp[1] + ax[3];
	temp[4] = temp[0] + ax[0];
	temp[5] = temp[1] + ax[0];

	Vector3 v[8];
	v[0] = temp[2] + ax[1];
	v[1] = temp[2] + ax[4];
	v[2] = temp[3] + ax[4];
	v[3] = temp[3] + ax[1];
	v[4] = temp[4] + ax[1];
	v[5] = temp[4] + ax[4];
	v[6] = temp[5] + ax[4];
	v[7] = temp[5] + ax[1];

	const auto draw = ImGui::GetBackgroundDrawList();


	ImColor color1 = ImColor(225, 0, 0, 200);
	ImColor color2 = ImColor(255, 153, 51, 200);

	if (Invulnerable > 0.f)
	{
		color1 = ImColor(0, 255, 0, 200);
		color2 = ImColor(0, 0, 255, 200);
	}

	Vector3 p1, p2;
	for (int i = 0; i < 4; i++)
	{

		if (WorldToScreen(v[i], p1) && WorldToScreen(v[(i + 1) & 3], p2))
			draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, color1, 2.f);

		if (WorldToScreen(v[4 + i], p1) && WorldToScreen(v[4 + ((i + 1) & 3)], p2))
			draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, color2, 2.f);

		if (WorldToScreen(v[i], p1) && WorldToScreen(v[4 + i], p2))
			draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, color2, 2.f);
	}

}

void drawOffscreenCentered(Vector3 origin, float distance)
{
	ImRect screen_rect = { 0.0f, 0.0f, scrsize.x, scrsize.y };
	auto angle = atan2((scrsize.y /  2) - origin.y, (scrsize.x / 2) - origin.x);
	angle += origin.z > 0 ? M_PI : 0.0f;

	ImVec2 arrow_center{
		(scrsize.x / 2) + off_radius * cosf(angle),
		(scrsize.y / 2) + off_radius * sinf(angle)
	};
	std::array<ImVec2, 4> points{
		ImVec2(-22.0f, -8.6f),
		ImVec2(0.0f, 0.0f),
		ImVec2(-22.0f, 8.6f),
		ImVec2(-18.0f, 0.0f)
	};
	for (auto& point : points)
	{
		auto x = point.x * off_arrow_size;
		auto y = point.y * off_arrow_size;

		point.x = arrow_center.x + x * cosf(angle) - y * sinf(angle);
		point.y = arrow_center.y + x * sinf(angle) + y * cosf(angle);
	}
	auto draw = ImGui::GetBackgroundDrawList();
	float alpha = 1.0f;
	if (origin.z > 0)
	{
		constexpr float nearThreshold = 200.0f * 200.0f;
		ImVec2 screen_outer_diff =
		{
			origin.x < 0 ? abs(origin.x) : (origin.x > screen_rect.Max.x ? origin.x - screen_rect.Max.x : 0.0f),
			origin.y < 0 ? abs(origin.y) : (origin.y > screen_rect.Max.y ? origin.y - screen_rect.Max.y : 0.0f),
		};
		float distance = static_cast<float>(std::pow(screen_outer_diff.x, 2) + std::pow(screen_outer_diff.y, 2));
		alpha = origin.z < 0 ? 1.0f : (distance / nearThreshold);
	}
	auto arrowColor = ImColor((int)(off_color[0] * 255.f), (int)(off_color[1] * 255.f), (int)(off_color[2] * 255.f));
	auto textColor = ImColor(0, 0, 0);
	auto bgcolor = ImColor(255, 255, 255);
	arrowColor.Value.w = (std::min)(alpha, 1.0f);
	textColor.Value.w = (std::min)(alpha, 1.0f);
	bgcolor.Value.w = (std::min)(alpha, 1.0f);
	auto text = std::format("{:.{}f} km", distance, 1);
	auto text_size = ImGui::CalcTextSize(text.c_str());
	auto text_pos = ImVec2(arrow_center.x + (origin.z > 0 ? -text_size.x : text_size.x), arrow_center.y + (origin.z > 0 ? -text_size.y : text_size.y));
	draw->AddTriangleFilled(points[0], points[1], points[3], arrowColor);
	draw->AddTriangleFilled(points[2], points[1], points[3], arrowColor);
	draw->AddQuad(points[0], points[1], points[2], points[3], ImColor(0.0f, 0.0f, 0.0f, alpha), 0.6f);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

void ESP()
{
	UnitList list = *(UnitList*)(cGame + 0x390);
	if (!list.unitList)
		return;
	Player* localplayer = *(Player**)(modulebase + off_localplayer);
	bool isScoping = *(bool*)(modulebase + off_isScoping);
	char* curmap = *(char**)(cGame + 0x1d0);
	
	if (localplayer->IsinHangar())
	{
		if (localplayer->ControlledUnit == NULL or localplayer->ControlledUnit->UnitInfo == NULL)
			return;
		auto position = localplayer->ControlledUnit->Position;
		const auto& rotation = localplayer->ControlledUnit->RotationMatrix;
		const auto& bbmin = localplayer->ControlledUnit->BBMin;
		const auto& bbmax = localplayer->ControlledUnit->BBMax;

		Vector3 ax[6];
		ax[0] = Vector3{ rotation[0][0], rotation[0][1], rotation[0][2] }.Scale(bbmin.x);
		ax[1] = Vector3{ rotation[1][0], rotation[1][1], rotation[1][2] }.Scale(bbmin.y);
		ax[2] = Vector3{ rotation[2][0], rotation[2][1], rotation[2][2] }.Scale(bbmin.z);
		ax[3] = Vector3{ rotation[0][0], rotation[0][1], rotation[0][2] }.Scale(bbmax.x);
		ax[4] = Vector3{ rotation[1][0], rotation[1][1], rotation[1][2] }.Scale(bbmax.y);
		ax[5] = Vector3{ rotation[2][0], rotation[2][1], rotation[2][2] }.Scale(bbmax.z);

		Vector3 temp[6];
		temp[0] = position + ax[2];
		temp[1] = position + ax[5];
		temp[2] = temp[0] + ax[3];
		temp[3] = temp[1] + ax[3];
		temp[4] = temp[0] + ax[0];
		temp[5] = temp[1] + ax[0];

		Vector3 v[8];
		v[0] = temp[2] + ax[1];
		v[1] = temp[2] + ax[4];
		v[2] = temp[3] + ax[4];
		v[3] = temp[3] + ax[1];
		v[4] = temp[4] + ax[1];
		v[5] = temp[4] + ax[4];
		v[6] = temp[5] + ax[4];
		v[7] = temp[5] + ax[1];

		const auto draw = ImGui::GetBackgroundDrawList();

		Vector3 p1, p2;
		for (int i = 0; i < 4; i++)
		{

			if (WorldToScreen(v[i], p1) && WorldToScreen(v[(i + 1) & 3], p2))
				draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, ImColor(225, 0, 0, 200), 2.f);

			if (WorldToScreen(v[4 + i], p1) && WorldToScreen(v[4 + ((i + 1) & 3)], p2))
				draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, ImColor(255, 153, 51, 200), 2.f);

			if (WorldToScreen(v[i], p1) && WorldToScreen(v[4 + i], p2))
				draw->AddLine({ p1.x, p1.y }, { p2.x, p2.y }, ImColor(255, 153, 51, 200), 2.f);
		}
		return;
	}
		
	const auto screen_center_x = scrsize.x / 2;
	const auto screen_center_y = scrsize.y / 2;
	
	for (auto i = 0; i < list.unitCount; ++i)
	{
			const auto unit = list.unitList->units[i];
			if (!unit)
				continue;
			const auto player = unit->PlayerInfo;
			
			const auto local = localplayer->ControlledUnit;
			if (!local)
				continue;
			if (unit->TeamNum == local->TeamNum)
				continue;
			if (unit->Position.x == 0)
				continue;
			const auto draw = ImGui::GetBackgroundDrawList();
			const auto vehicleType = unit->UnitInfo->unitType;
			if (strcmp(vehicleType, "exp_bomber") == 0 or strcmp(vehicleType, "exp_assault") == 0 or strcmp(vehicleType, "exp_fighter") == 0)
			{
				if (!show_planes)
				{
					continue;
				}
				
			}
				
			
			
			auto position = unit->Position;
			auto distance = Distance(position, localplayer->ControlledUnit->Position);
			auto name = u8"";
			name = (char8_t*)(unit->UnitInfo->ShortName);
			auto text = std::format("{}  | {:.{}f} km", (char*)(name), distance, 2);
			auto size = ImGui::CalcTextSize(text.c_str());
			
			int count = (16 - (unit->ReloadTimer));
			constexpr float stat = (10.f / 16);
			float progress = ((stat * count) * 0.1f);
			
			if (player)
			{
				if (!unit->UnitState == 0 or !player->IsAlive())
					continue;
				const auto& rotation = unit->RotationMatrix;
				const auto& bbmin = unit->BBMin;
				const auto& bbmax = unit->BBMax;

				draw3dbox(rotation, bbmin, bbmax, position, unit->Invulnerable);
				
				Vector3 origin = { };
				if (WorldToScreen(position, origin))
				{
					if (origin.x < 0 || origin.x > scrsize.x || origin.y < 0 || origin.y > scrsize.y)
					{
						if (show_offscreen)
						{
							if (!isScoping)
							{
								drawOffscreenCentered(origin, distance);
							}
							continue;
						}
						
						continue;
					}

					draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 5 },
						{ origin.x + (size.x * 0.5f) + 5, origin.y + 10 + (size.y * 0.5f) + 5 },
						ImColor(0, 0, 0, 150));

					draw->AddText({ origin.x - (size.x * 0.5f), origin.y + (size.y * 0.5f) },
						ImColor(255, 255, 255),
						text.c_str());

					if (show_reload)
					{
						draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
							{ origin.x + (size.x * 0.5f) + 5, origin.y + 10 + (size.y * 0.3f) + 10 },
							ImColor(0, 0, 0, 150));
						if (progress == 1)
						{
							draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
								{ origin.x - (size.x * 0.5f) + (progress * size.x) + 5, origin.y + 10 + (size.y * 0.5f) + 10 },
								ImColor(0, 255, 0, 200));
						}
						else
						{
							draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
								{ origin.x - (size.x * 0.5f) + (progress * size.x) + 5, origin.y + 10 + (size.y * 0.5f) + 10 },
								ImColor(255, 0, 0, 200));
						}
					}

				}
			}
			if (show_bots)
			{
				if (strcmp(curmap, "levels/firing_range.bin") != 0)
					continue;
				
				if (!unit->UnitState == 0 )
					continue;
				
				if (!show_planes)
				{
					if (strcmp(vehicleType, "exp_bomber") == 0 or strcmp(vehicleType, "exp_assault") == 0 or strcmp(vehicleType, "exp_fighter") == 0)
						continue;
				}
				if (strcmp(vehicleType, "exp_fortification") == 0 or strcmp(vehicleType, "exp_structure") == 0 or strcmp(vehicleType, "exp_aaa") == 0 or strcmp(vehicleType, "dummy_plane") == 0)
					continue;
	
				const auto& rotation = unit->RotationMatrix;
				const auto& bbmin = unit->BBMin;
				const auto& bbmax = unit->BBMax;

				draw3dbox(rotation, bbmin, bbmax, position, unit->Invulnerable);
				
				Vector3 origin = { };
				if (WorldToScreen(position, origin))
				{
					if (origin.x < 0 || origin.x > scrsize.x || origin.y < 0 || origin.y > scrsize.y)
					{
						if (show_offscreen)
						{
							
							if (!isScoping)
							{
								drawOffscreenCentered(origin, distance);
							}
							continue;
						}
						continue;
					}
					

					draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 5 },
						{ origin.x + (size.x * 0.5f) + 5, origin.y + 10 + (size.y * 0.5f) + 5 },
						ImColor(0, 0, 0, 150));

					draw->AddText({ origin.x - (size.x * 0.5f), origin.y + (size.y * 0.5f) },
						ImColor(255, 255, 255),
						text.c_str());

					if (show_reload)
					{
						draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
							{ origin.x + (size.x * 0.5f) + 5, origin.y + 10 + (size.y * 0.3f) + 10 },
							ImColor(0, 0, 0, 150));
						if (progress == 1)
						{
							draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
								{ origin.x - (size.x * 0.5f) + (progress * size.x) + 5, origin.y + 10 + (size.y * 0.5f) + 10 },
								ImColor(0, 255, 0, 200));
						}
						else
						{
							draw->AddRectFilled({ origin.x - (size.x * 0.5f) - 5, origin.y + 10 + (size.y * 0.5f) + 5 },
								{ origin.x - (size.x * 0.5f) + (progress * size.x) + 5, origin.y + 10 + (size.y * 0.5f) + 10 },
								ImColor(255, 0, 0, 200));
						}
					}

				}
	
			}
			
	}
	
}

void ZoomMod()
{
	UnitList list = *(UnitList*)(cGame + 0x390);
	if (!list.unitList)
		return;
	Player* localplayer = *(Player**)(modulebase + off_localplayer);
	if (localplayer->IsinHangar())
		return;
	if (localplayer->ControlledUnit == NULL or localplayer->ControlledUnit->UnitInfo == NULL)
		return;

	if (zoom_mod)
	{
		localplayer->ControlledUnit->UnitInfo->ZoomMulti = zoom_mult;
		localplayer->ControlledUnit->UnitInfo->AlternateMulti = alt_mult;
		localplayer->ControlledUnit->UnitInfo->ShadowMulti = shadow_mult;
	}
	else
	{
		localplayer->ControlledUnit->UnitInfo->ZoomMulti = 5.f;
		localplayer->ControlledUnit->UnitInfo->AlternateMulti = 15.f;
		localplayer->ControlledUnit->UnitInfo->ShadowMulti = 20.f;
	}
	return;
}

void showWarningwindow()
{
	
	
	auto text1 = "THIS SOFTWARE DISTRIBUTED FOR FREE.";
	auto text2 = "IF YOU PAID FOR THIS SOFTWARE - YOU GOT SCAMMED.";
	ImGui::SetNextWindowSize({ scrsize.x, scrsize.y });
	ImGui::SetNextWindowPos({ 0, 0 });
	auto flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
	ImGui::Begin("WARNING",nullptr,flags);
	ImGui::PushFont(big_main);
	auto textWidth1 = ImGui::CalcTextSize(text1).x;
	ImGui::SetCursorPos(ImVec2((scrsize.x  -  textWidth1)* 0.5f,100));
	ImGui::Text(text1);
	auto textWidth2 = ImGui::CalcTextSize(text2).x;
	ImGui::SetCursorPosX((scrsize.x - textWidth2) * 0.5f);
	ImGui::Text(text2);
	ImGui::SetCursorPosX((scrsize.x - 225) * 0.5f);
	ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
	ImGui::Checkbox("I understood that", &agree);
	ImGui::PopStyleVar();
	ImGui::PopFont();
	ImGui::End();
}
bool init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}



	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	ImGui::NewFrame();
	auto draw = ImGui::GetBackgroundDrawList();
	auto sizeScr = ImGui::GetIO().DisplaySize;

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		open = !open;
	}
	

	if (!agree)
		showWarningwindow();

	ImGui::GetIO().MouseDrawCursor = open;
	
	if (agree)
	{
		if (open)
		{
			ImGui::PushFont(med_main);
			ImGui::SetNextWindowSize({ 550,350 });
			ImGui::SetNextWindowPos({ (sizeScr.x - 550) * 0.5f, (sizeScr.y - 350) * 0.5f },ImGuiCond_FirstUseEver);
			ImGui::Begin("WarHook", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

			ImGui::BeginTabBar("main");
			ImGui::SetNextItemWidth(180.f);
			if (ImGui::BeginTabItem("				ESP", &tab_esp, ImGuiTabItemFlags_NoCloseButton))
			{

				ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4,5 });
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Enabled", &esp_status);
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Show reload bar", &show_reload);
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Show bots", &show_bots);
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Show planes", &show_planes);
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Show offscreen arrows", &show_offscreen);
				ImGui::PopStyleVar();
				ImGui::PopStyleVar();
				if (show_offscreen)
				{

					ImGui::SameLine();
					ImGui::ColorEdit3("Arrow color", off_color, ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
					ImGui::Indent();
					ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
					ImGui::SliderFloat("Arrow size", &off_arrow_size, 0.0f, 3.f);
					ImGui::SliderFloat("Radius", &off_radius, 0.0f, 1000.0f);
					ImGui::PopStyleVar();
				}
				ImGui::EndTabItem();
			}
			ImGui::SetNextItemWidth(180.f);
			if (ImGui::BeginTabItem("			  AimBot", &tab_aimbot, ImGuiTabItemFlags_NoCloseButton))
			{
				ImGui::Text("Soon");
				ImGui::EndTabItem();
			}

			ImGui::SetNextItemWidth(180.f);
			if (ImGui::BeginTabItem("				Misc", &tab_misc, ImGuiTabItemFlags_NoCloseButton))
			{
				ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4,5 });
				ImGui::SetCursorPosX(5.f);
				ImGui::Checkbox("Zoom modification", &zoom_mod);
				ImGui::SetCursorPosX(5.f);
				ImGui::Text("Zoom multiplayer");
				ImGui::SetCursorPosX(5.f);
				ImGui::SliderFloat("##zoom", &zoom_mult, 1.0f, 100.0f);
				ImGui::SetCursorPosX(5.f);
				ImGui::Text("Alternate multiplayer");
				ImGui::SetCursorPosX(5.f);
				ImGui::SliderFloat("##alt", &alt_mult, 1.0f, 100.0f);
				ImGui::SetCursorPosX(5.f);
				ImGui::Text("Shadow zoom multiplayer");
				ImGui::SetCursorPosX(5.f);
				ImGui::SliderFloat("##shadow", &shadow_mult, 20.0f, 250.0f);
				ImGui::PopStyleVar();
				ImGui::PopStyleVar();
				ImGui::EndTabItem();
		
				
			}
			ImGui::EndTabBar();
			if (!tab_esp && !tab_misc && !tab_aimbot)
			{
				if (def_tab)
				{
					auto text1 = "This mod is made by m0nkrel ";
					auto text2 = "with love <3";
					auto text3 = "If you wanna support developer - DM me in ";
					auto text4 = "Discord: m0nkrel#0001";
					auto windowWidth = ImGui::GetWindowSize().x;
					auto textWidth = ImGui::CalcTextSize(text1).x;

					ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
					ImGui::Text(text1);

					textWidth = ImGui::CalcTextSize(text2).x;
					ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
					ImGui::Text(text2);

					textWidth = ImGui::CalcTextSize(text3).x;
					ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
					ImGui::SetCursorPos({ (windowWidth - textWidth) * 0.5f, 250 });
					ImGui::Text(text3);

					textWidth = ImGui::CalcTextSize(text4).x;
					ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
					ImGui::Text(text4);

					ImGui::SetCursorPos({ (windowWidth - 100) * 0.5f ,150 });
					ImGui::Button("Start", { 100,30 });


					if (ImGui::IsItemClicked())
					{
						tab_esp = true;
						tab_aimbot = true;
						tab_misc = true;
						def_tab = false;
					}
				}
			}
			ImGui::PopFont();

			ImGui::End();
		}

	}
	if (esp_status)
		ESP();
	ZoomMod();
	ImGui::Render();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}