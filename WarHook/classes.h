#pragma once
#include "includes.h"

class Player
{
	enum GuiState : std::uint8_t
	{
		NONE = 0,
		MENU = 1,
		ALIVE = 2,
		DEAD = 3,
		SPEC = 6,
		LIMBO = 8,
		LOADING = 10
	};
public:
	bool IsAlive() const noexcept
	{
		return GuiState == GuiState::ALIVE;
	}

	bool IsinHangar() const noexcept
	{
		return GuiState == GuiState::MENU;
	}
public:
	char pad_0000[96]; //0x0000
	char* FullName; //0x0060
	char pad_0068[72]; //0x0068
	char Name[32]; //0x00B0
	char pad_00D0[1048]; //0x00D0
	uint8_t GuiState; //0x04E8
	char pad_04E9[551]; //0x04E9
	class Unit* ControlledUnit; //0x0710


}; //Size: 0x0718


class Unit
{
public:
	char pad_0000[512]; //0x0000
	Vector3 BBMin; //0x0200
	Vector3 BBMax; //0x020C
	char pad_0218[1440]; //0x0218
	uint8_t ReloadTimer; //0x07B8
	char pad_07B9[699]; //0x07B9
	Matrix3x3 RotationMatrix; //0x0A74
	Vector3 Position; //0x0A98
	char pad_0AA4[1688]; //0x0AA4
	float Invulnerable; //0x113C
	char pad_1140[256]; //0x1140
	uint8_t UnitState; //0x1240
	char pad_1241[15]; //0x1241
	class Player* PlayerInfo; //0x1250
	char pad_1258[64]; //0x1258
	uint8_t TeamNum; //0x1298
	char pad_1299[15]; //0x1299
	class Info* UnitInfo; //0x12A8
	char pad_12B0[168]; //0x12B0
	class UnitWeapons* UnitWeapons; //0x1358
	char pad_1360[3056]; //0x1360
	class Moving* Velocity1; //0x1F50
};



class UnitWeapons
{
public:
	char pad_0000[856]; //0x0000
	class WeaponArray* WeaponArray; //0x0358
	int64_t WeaponCount; //0x0360
}; //Size: 0x0368
static_assert(sizeof(UnitWeapons) == 0x368);

class WeaponArray
{
public:
	class Weapon* Weapon; //0x0000
	char pad_0008[16]; //0x0008
}; //Size: 0x0018
static_assert(sizeof(WeaponArray) == 0x18);

//class Weapon
//{
//public:
//	char pad_0000[124]; //0x0000
//	Vector3 weaponBBMin; //0x007C
//	char pad_0088[36]; //0x0088
//	Vector3 weaponBBMax; //0x00AC
//	Matrix3x3 Turret_X_Rotation; //0x00B8
//	char pad_00DC[12]; //0x00DC
//	Matrix3x3 Turret_Y_Rotation; //0x00E8
//	char pad_010C[364]; //0x010C
//	class WeaponInfo* WeaponInfo; //0x0278
//	char pad_0280[604]; //0x0280
//	uint8_t CurrentSlot; //0x04DC
//	char pad_04DD[67]; //0x04DD
//	Vector3 Position; //0x0520
//}; //Size: 0x052C
//class Weapon
//{
//public:
//	char pad_0000[124]; //0x0000
//	Vector3 BBMin; //0x007C
//	char pad_0088[36]; //0x0088
//	Vector3 BBMax; //0x00AC
//	char pad_00B8[4]; //0x00B8
//	Matrix3x3 RotMatixY; //0x00BC
//	char pad_00E0[12]; //0x00E0
//	Matrix3x3 RotMatixX; //0x00EC
//	char pad_0110[12]; //0x0110
//	Matrix3x3 RotMatrixZ; //0x011C
//	char pad_0140[312]; //0x0140
//	class WeaponInfo* WeaponInfo; //0x0278
//	char pad_0280[604]; //0x0280
//	uint8_t CurrentSlot; //0x04DC
//	char pad_04DD[31]; //0x04DD
//	Matrix3x3 Rotationmatrix; //0x04FC
//	Vector3 Position; //0x0520
//}; //Size: 0x052C
class Weapon
{
public:
	char pad_0000[128]; //0x0000
	Vector3 BBMin; //0x0080
	char pad_008C[36]; //0x008C
	Vector3 BBMax; //0x00B0
	Matrix3x3 RotMatixY; //0x00BC
	char pad_00E0[12]; //0x00E0
	Matrix3x3 RotMatixX; //0x00EC
	char pad_0110[12]; //0x0110
	Matrix3x3 RotMatrixZ; //0x011C
	char pad_0140[312]; //0x0140
	class WeaponInfo* WeaponInfo; //0x0278
	char pad_0280[604]; //0x0280
	uint8_t CurrentSlot; //0x04DC
	char pad_04DD[67]; //0x04DD
	Vector3 Position; //0x0520
};


class WeaponInfo
{
public:
	char pad_0000[168]; //0x0000 
	class AmmoInfo* AmmoInfo; //0x00A8 (A8 + d8)
	char pad_00B0[336]; //0x00B0
}; //Size: 0x0200
static_assert(sizeof(WeaponInfo) == 0x200);

class AmmoInfo
{
public:
	char pad_0000[12]; //0x0000
	float mass; //0x000C
	float Caliber; //0x0010
	float Lenght; //0x0014
	float Distance; //0x0018
	char pad_001C[28]; //0x001C
	float Speed; //0x0038
	char pad_003C[140]; //0x003C
}; //Size: 0x00C8
static_assert(sizeof(AmmoInfo) == 0xC8);




class Moving
{
public:
	char pad_0000[84]; //0x0000
	Vector3 Velocity; //0x0054
	char pad_0060[48]; //0x0060
}; //Size: 0x0090




class Info
{
public:
	char* unitName; //0x0000
	char* modelName; //0x0008
	char* modelPath; //0x0010
	char* FullName; //0x0018
	char* ShortName; //0x0020
	char pad_0028[8]; //0x0028
	char* unitType; //0x0030
	char pad_0038[428]; //0x0038
	float ZoomMulti; //0x01E4
	float AlternateMulti; //0x01E8
	char pad_01EC[16]; //0x01EC
	float ShadowMulti; //0x01FC


	bool isPlane() const noexcept
	{
		return unitType == "exp_fighter" or "exp_bomber" or "exp_assault";
	}
};

class EntList {
public:
	Player* players[64];
};

class Units
{
public:
	std::array<Unit*, 500U> units;
};

class UnitList
{
public:
	Units* unitList;
	std::uint16_t unitCount;
};