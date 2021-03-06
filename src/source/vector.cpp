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

bool operator ==(const Vector2& a, const Vector2& b) {
	return cmp_float(a.x, b.x) && cmp_float(a.y, b.y);
}

bool operator !=(const Vector2& l, const Vector2& r) {
	return !(l == r);
}

Vector2 normalized_vector(const Vector2& v)
{
	float m = magnitude(v);
	if (m < 1.0f)
		return Vector2(v.x / m, v.y / m);
	else
		return v;
}

float magnitude(const Vector2& v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

float dot_product(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}

Vector2 projection(const Vector2& a, const Vector2& b) {
	float b_magnitude_squared = magnitude(b) * magnitude(b);
	return b * (dot_product(a, b) / b_magnitude_squared);
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

float distance(const Vector2& a, const Vector2& b) {
	return magnitude(a - b);
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

bool operator ==(const Vector3& a, const Vector3& b) {
	return cmp_float(a.x, b.x) && cmp_float(a.y, b.y) && cmp_float(a.z, b.z);
}

bool operator !=(const Vector3& l, const Vector3& r) {
	return !(l == r);
}

Vector3 normalized_vector(const Vector3& v)
{
	float m = magnitude(v);
	if (m < 1.0f)
		return Vector3(v.x / m, v.y / m, v.z / m);
	else
		return v;
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
	float b_magnitude_squared = dot_product(b, b);
	return b * (dot_product(a, b) / b_magnitude_squared);
}

Vector3 rejection(const Vector3& a, const Vector3& b) {
	return a - projection(a, b);
}

Vector3 reflection(const Vector3& a, const Vector3& b) {
	return a - projection(a, b) * 2;
}

float angle(const Vector3& a, const Vector3& b) {
	float dot_a_b = dot_product(a, b);
	float magnitude_a_b = magnitude(a) * magnitude(b);
	return acos(dot_a_b / magnitude_a_b);
}

float distance(const Vector3& a, const Vector3& b) {
	return magnitude(a - b);
}

Vector4 operator +(const Vector4& a, const Vector4& b) {
	return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector4 operator +(const Vector4& v, float s) {
	return Vector4(v.x + s, v.y + s, v.z + s, v.w + s);
}

Vector4 operator -(const Vector4& a, const Vector4& b) {
	return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

Vector4 operator -(const Vector4& v, float s) {
	return Vector4(v.x - s, v.y - s, v.z - s, v.w - s);
}

Vector4 operator -(const Vector4& v) {
	return v * -1;
}

Vector4 operator *(const Vector4& a, const Vector4& b) {
	return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

Vector4 operator *(const Vector4& v, float s) {
	return Vector4(v.x * s, v.y * s, v.z * s, v.w * s);
}

Vector4 operator /(const Vector4& a, const Vector4& b) {
	return Vector4(a.x * (1.f / b.x), a.y * (1.f / b.y), a.z * (1.f / b.z), a.w * (1.f / b.w));
}

Vector4 operator /(const Vector4& v, float s) {
	s = 1.f / s;
	return Vector4(v.x * s, v.y * s, v.z * s, v.w * s);
}

bool operator ==(const Vector4& a, const Vector4& b) {
	return cmp_float(a.x, b.x) && cmp_float(a.y, b.y) && cmp_float(a.z, b.z) && cmp_float(a.w, b.w);
}

bool operator !=(const Vector4& l, const Vector4& r) {
	return !(l == r);
}

Vector4 normalized_vector(const Vector4& v)
{
	float m = magnitude(v);
	if (m < 1.0f)
		return Vector4(v.x / m, v.y / m, v.z / m, v.w / m);
	else
		return v;
}

float magnitude(const Vector4& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

float dot_product(const Vector4& a, const Vector4& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vector4 projection(const Vector4& a, const Vector4& b) {
	float b_magnitude_squared = dot_product(b, b);
	return b * (dot_product(a, b) / b_magnitude_squared);
}

Vector4 rejection(const Vector4& a, const Vector4& b) {
	return a - projection(a, b);
}

Vector4 reflection(const Vector4& a, const Vector4& b) {
	return a - projection(a, b) * 2;
}

float angle(const Vector4& a, const Vector4& b) {
	float dot_a_b = dot_product(a, b);
	float magnitude_a_b = magnitude(a) * magnitude(b);
	return acos(dot_a_b / magnitude_a_b);
}

float distance(const Vector4& a, const Vector4& b) {
	return magnitude(a - b);
}
