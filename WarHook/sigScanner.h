#pragma once
#include "includes.h"
#include "sigs.h"

std::uint8_t* Scan(const char* signature) noexcept
{
	static const auto patternToByte = [](const char* pattern) noexcept -> std::vector<int>
	{
		auto bytes = std::vector<int>{ };
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + std::strlen(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;

				if (*current == '?')
					++current;

				bytes.push_back(-1);
			}
			else
				bytes.push_back(std::strtoul(current, &current, 16));

		}

		return bytes;
	};

	static const auto handle = GetModuleHandle(NULL);

	if (!handle)
		return nullptr;

	auto dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(handle);
	auto ntHeaders =
		reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t*>(handle) + dosHeader->e_lfanew);

	auto size = ntHeaders->OptionalHeader.SizeOfImage;
	auto bytes = patternToByte(signature);
	auto scanBytes = reinterpret_cast<std::uint8_t*>(handle);

	auto s = bytes.size();
	auto d = bytes.data();

	for (auto i = 0ul; i < size - s; ++i)
	{
		bool found = true;

		for (auto j = 0ul; j < s; ++j)
		{
			if (scanBytes[i + j] != d[j] && d[j] != -1)
			{
				found = false;
				break;
			}
		}

		if (found)
			return &scanBytes[i];
	}

	return nullptr;
}

const auto get = [](const char* signature) noexcept -> std::uintptr_t
{
	return reinterpret_cast<std::uintptr_t>(Scan(signature));
};

template<typename T = std::uintptr_t>
constexpr T GetOffset(std::uintptr_t address, int offset)
{
	return (T)(address + (int)((*(int*)(address + offset) + offset) + sizeof(int)));
};


std::vector<uintptr_t> GetOffsets(std::vector<sig> signatures) {
	std::vector<uintptr_t> offsets;
	uintptr_t modulebase = (uintptr_t)GetModuleHandle(NULL);
	for (auto& sig : signatures) {
		uintptr_t address = GetOffset<std::uintptr_t>(get(sig.signature), sig.offset);
		offsets.push_back(address - modulebase);
	}
	return offsets;
}