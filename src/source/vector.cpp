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

Vector2 normalized_vector(const Vector2& v)
{
	float m = magnitude(v);
	return Vector2(v.x / m, v.y / m);
}

float magnitude(const Vector2& v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

float dot_product(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}

Vector2 projection(const Vector2& a, const Vector2& b) {
	float bMagSquared = magnitude(b) * magnitude(b);
	return b * (dot_product(a, b) / bMagSquared);
}

Vector2 rejection(const Vector2& a, const Vector2& b) {
	return a - projection(a, b);
}

Vector2 reflection(const Vector2& a, const Vector2& b) {
	return a - projection(a, b) * 2;
}

float angle(const Vector2& a, const Vector2& b) {
	float numerator = dot_product(a, b);
	float denominator = magnitude(a) * magnitude(b);
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

Vector3 normalized_vector(const Vector3& v)
{
	float m = magnitude(v);
	return Vector3(v.x / m, v.y / m, v.z / m);
}

float magnitude(const Vector3& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

float dot_product(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 cross_product(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.z * b.z,
		a.x * b.y - a.y * b.x);
}

Vector3 projection(const Vector3& a, const Vector3& b) {
	float bMagSquared = magnitude(b) * magnitude(b);
	return b * (dot_product(a, b) / bMagSquared);
}

Vector3 rejection(const Vector3& a, const Vector3& b) {
	return a - projection(a, b);
}

Vector3 reflection(const Vector3& a, const Vector3& b) {
	return a - projection(a, b) * 2;
}

float angle(const Vector3& a, const Vector3& b) {
	float numerator = dot_product(a, b);
	float denominator = magnitude(a) * magnitude(b);
	return acos(numerator / denominator);
}
