#include "../headers/vector.h"
#include <cmath>

Vector2 operator +(const Vector2& a, const Vector2& b) {
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator +(const Vector2& v, float s) {
	return Vector2(v.x + s, v.x + s);
}

Vector2 operator -(const Vector2& a, const Vector2& b) {
	return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator -(const Vector2& v, float s) {
	return Vector2(v.x - s, v.y - s);
}

Vector2 operator -(const Vector2& v) {
	return v * -1;
}

Vector2 operator *(const Vector2& a, const Vector2& b) {
	return Vector2(a.x * b.x, a.y * b.y);
}

Vector2 operator *(const Vector2& v, float s) {
	return Vector2(v.x * s, v.y * s);
}

Vector2 operator /(const Vector2& a, const Vector2& b) {
	return Vector2(a.x * (1.f / b.x), a.y * (1.f / b.y));
}

Vector2 operator /(const Vector2& v, float s) {
	s = 1.f / s;
	return Vector2(v.x * s, v.y * s);
}

Vector2 Normalized(const Vector2& v)
{
	float m = Magnitude(v);
	return Vector2(v.x / m, v.y / m);
}

float Magnitude(const Vector2& v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

float Dot(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}

Vector2 Project(const Vector2& a, const Vector2& b) {
	float bMagSquared = Magnitude(b) * Magnitude(b);
	return b * (Dot(a, b) / bMagSquared);
}

Vector2 Reject(const Vector2& a, const Vector2& b) {
	return a - Project(a, b);
}

Vector2 Reflect(const Vector2& a, const Vector2& b) {
	return a - Project(a, b) * 2;
}

float Angle(const Vector2& a, const Vector2& b) {
	float numerator = Dot(a, b);
	float denominator = Magnitude(a) * Magnitude(b);
	return acos(numerator / denominator);
}

Vector3 operator +(const Vector3& a, const Vector3& b) {
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 operator +(const Vector3& v, float s) {
	return Vector3(v.x + s, v.y + s, v.z + s);
}

Vector3 operator -(const Vector3& a, const Vector3& b) {
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3 operator -(const Vector3& v, float s) {
	return Vector3(v.x - s, v.y - s, v.z - s);
}

Vector3 operator -(const Vector3& v) {
	return v * -1;
}

Vector3 operator *(const Vector3& a, const Vector3& b) {
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3 operator *(const Vector3& v, float s) {
	return Vector3(v.x * s, v.y * s, v.z * s);
}

Vector3 operator /(const Vector3& a, const Vector3& b) {
	return Vector3(a.x * (1.f / b.x), a.y * (1.f / b.y), a.z * (1.f / b.z));
}

Vector3 operator /(const Vector3& v, float s) {
	s = 1.f / s;
	return Vector3(v.x * s, v.y * s, v.z * s);
}

Vector3 Normalized(const Vector3& v)
{
	float m = Magnitude(v);
	return Vector3(v.x / m, v.y / m, v.z / m);
}

float Magnitude(const Vector3& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float Dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Cross(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.z * b.z,
		a.x * b.y - a.y * b.x);
}

Vector3 Project(const Vector3& a, const Vector3& b) {
	float bMagSquared = Magnitude(b) * Magnitude(b);
	return b * (Dot(a, b) / bMagSquared);
}

Vector3 Reject(const Vector3& a, const Vector3& b) {
	return a - Project(a, b);
}

Vector3 Reflect(const Vector3& a, const Vector3& b) {
	return a - Project(a, b) * 2;
}

float Angle(const Vector3& a, const Vector3& b) {
	float numerator = Dot(a, b);
	float denominator = Magnitude(a) * Magnitude(b);
	return acos(numerator / denominator);
}
