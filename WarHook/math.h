#pragma once
#include <cmath>
#include <limits>
#include "includes.h"

constexpr auto M_PI = 3.14159265358979323846f;
constexpr auto M_RADPI = 57.295779513082f;
#define M_PI_F		((float)(M_PI))	// Shouldn't collide with anything.
#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / M_PI_F) )
#define DEG2RAD( x )  ( (float)(x) * (float)(M_PI_F / 180.f) )
struct Matrix3x3
{
	constexpr float* operator[](int index) noexcept
	{
		return data[index];
	}

	constexpr const float* operator[](int index) const noexcept
	{
		return data[index];
	}

	float data[3][3] = { };
};

struct ViewMatrix
{
	constexpr float* operator[](int index) noexcept
	{
		return data[index];
	}

	constexpr const float* operator[](int index) const noexcept
	{
		return data[index];
	}

	float data[4][4] = { };
};

struct Vector3
{
	constexpr Vector3(const float x = 0.f, const float y = 0.f, const float z = 0.f) noexcept :
		x(x), y(y), z(z) { }


	constexpr Vector3 operator+(const Vector3& other) const noexcept
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	constexpr Vector3 operator-(const Vector3& other) const noexcept
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	constexpr Vector3 operator*(const Vector3& other) const noexcept
	{
		return Vector3(x * other.x, y * other.y, z * other.z);
	}

	constexpr Vector3 operator*(const float scale) const noexcept
	{
		return Vector3(x * scale, y * scale, z * scale);
	}
	constexpr Vector3 operator/(const float scale) const noexcept
	{
		return Vector3(x / scale, y / scale, z / scale);
	}

	float LengthTo(const Vector3& other) const noexcept
	{
		return std::sqrtf((x - other.x) * (x - other.x) +
			(y - other.y) * (y - other.y) +
			(z - other.z) * (z - other.z));
	}

	bool IsEqual(const Vector3& other, const float margin = std::numeric_limits<float>::epsilon()) const noexcept
	{
		return (std::fabsf(x - other.x) < margin &&
			std::fabsf(y - other.y) < margin &&
			std::fabsf(z - other.z) < margin);
	}

	constexpr Vector3 Scale(const float scale) const noexcept
	{
		return Vector3{ x * scale, y * scale, z * scale };
	}

	float Length() const noexcept
	{
		return std::sqrtf(x * x + y * y + z * z) ;
	}
	float x, y, z;

};
#pragma once
struct Vector2
{
public:
	float x, y;

	Vector2() { x = y = 0; }
	Vector2(const float x, const float y) : x(x), y(y) {}
	Vector2 operator + (const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
	Vector2 operator - (const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
	Vector2 operator * (const float& rhs) const { return Vector2(x * rhs, y * rhs); }
	Vector2 operator / (const float& rhs) const { return Vector2(x / rhs, y / rhs); }
	Vector2& operator += (const Vector2& rhs) { return *this = *this + rhs; }
	Vector2& operator -= (const Vector2& rhs) { return *this = *this - rhs; }
	Vector2& operator *= (const float& rhs) { return *this = *this * rhs; }
	Vector2& operator /= (const float& rhs) { return *this = *this / rhs; }
	float operator[](int i) const {
		return ((float*)this)[i];
	}

	float& operator[](int i);
	float dot() const { return x * x + y * y; }
	float Length() const { return sqrtf(dot()); }
};
void VectorAnglesRadar(Vector3& forward, Vector3& angles)
{
	if (forward.x == 0.f && forward.y == 0.f)
	{
		angles.x = forward.z > 0.f ? -90.f : 90.f;
		angles.y = 0.f;
	}
	else
	{
		angles.x = RAD2DEG(atan2(-forward.z, forward.Length()));
		angles.y = RAD2DEG(atan2(forward.y, forward.x));
	}
	angles.z = 0.f;
}
void RotateTriangle(std::array<Vector3, 3>& points, float rotation)
{
	const auto points_center = (points[0] + points[1] + points[2]) / 3.f;
	for (auto& point : points)
	{
		point = point - points_center;

		const auto temp_x = point.x;
		const auto temp_y = point.y;

		const auto theta = DEG2RAD(rotation);
		const auto c = cosf(theta);
		const auto s = sinf(theta);

		point.x = temp_x * c - temp_y * s;
		point.y = temp_x * s + temp_y * c;

		point = point + points_center;
	}
}
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float thickness, ImColor color) {
	ImGui::GetWindowDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), color, thickness);
	ImGui::GetWindowDrawList()->AddLine(ImVec2(x2, y2), ImVec2(x3, y3), color, thickness);
	ImGui::GetWindowDrawList()->AddLine(ImVec2(x3, y3), ImVec2(x1, y1), color, thickness);
}