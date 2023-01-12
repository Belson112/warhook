#pragma once
#include "includes.h"


namespace sigs
{
	constexpr auto Game = "48 8B 05 ? ? ? ? F2 0F 10 4F 08";
	constexpr auto LocalPlayer = "48 8B 15 ? ? ? ? 48 85 D2 74 ? 41 BA ? ? ? ? F6 82 ? ? ? ? ? 75";
	constexpr auto HudInfo = "48 8B 0D ? ? ? ? 83 B9 ? ? ? ? ? 7C 4E";
	constexpr auto ScreenWidth = "89 05 ? ? ? ? 8b 0d ? ? ? ? 89 0d ? ? ? ? 8b 15 ? ? ? ? f3 0f 2a c2 f3 0f 11 05 ? ? ? ? 8b 35";
	constexpr auto IsScoping = "88 0d ? ? ? ? 48 8b 05 ? ? ? ? 48 8b 80";
};

struct sig {
	const char* signature;
	uintptr_t offset;
	sig(const char* signature, uintptr_t offset) : signature(signature), offset(offset) {}
};

std::vector<sig> signatures = { sig(sigs::Game,0x3), sig(sigs::LocalPlayer,0x3), sig(sigs::HudInfo,0x3), sig(sigs::ScreenWidth,0x2),
								sig(sigs::IsScoping,0x2) };



