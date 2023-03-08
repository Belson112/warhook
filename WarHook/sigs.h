#pragma once
#include "includes.h"


namespace sigs
{
	constexpr auto Game = "48 8B 05 ? ? ? ? F2 0F 10 4F 08";
	constexpr auto LocalPlayer = "48 8b 2d ? ? ? ? 48 85 ed 74 ? f6 85 ? ? ? ? ? 74";
	constexpr auto HudInfo = "48 8b 0d ? ? ? ? 80 b9 ? ? ? ? ? 0f 84 ? ? ? ? 80 bf";
	constexpr auto ScreenWidth = "89 05 ? ? ? ? 8b 0d ? ? ? ? 89 0d ? ? ? ? 8b 15 ? ? ? ? f3 0f 2a c2 f3 0f 11 05 ? ? ? ? 8b 35";
	constexpr auto IsScoping = "80 3d ? ? ? ? ? 75 ? 40 84 f6";
	constexpr auto ViewMatrix = "0F 28 05 ?? ?? ?? ?? 0F 28 0D ?? ?? ?? ?? 0F 28 D8";
};

struct sig {
	const char* signature;
	uintptr_t offset;
	sig(const char* signature, uintptr_t offset) : signature(signature), offset(offset) {}
};

std::vector<sig> signatures = { sig(sigs::Game,0x3), sig(sigs::LocalPlayer,0x3), sig(sigs::HudInfo,0x3), sig(sigs::ScreenWidth,0x2),
								sig(sigs::IsScoping,0x2), sig(sigs::ViewMatrix,0x3) };
