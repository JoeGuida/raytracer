#include "vector.h"
#include <cmath>

/* 
* Vector2 
*/

inline Vector2 Vector2::operator +(const Vector2& v) const {
	return Vector2(x + v.x, y + v.y);
}

inline Vector2 Vector2::operator +(float s) const {
	return Vector2(x + s, y + s);
}

inline Vector2 Vector2::operator -(const Vector2& v) const {
	return Vector2(x - v.x, y - v.y);
}

inline Vector2 Vector2::operator -(float s) const {
	return Vector2(x - s, y - s);
}

inline Vector2 Vector2::operator *(const Vector2& v) const {
	return Vector2(x * v.x, y * v.y);
}

inline Vector2 Vector2::operator *(float s) const {
	return Vector2(x * s, y * s);
}

inline Vector2 Vector2::operator /(const Vector2& v) const {
	return Vector2(x * (1.0f / v.x), y * (1.0f / v.y));
}

inline Vector2 Vector2::operator /(float s) const {
	s = 1.0f / s;
	return Vector2(x * s, y * s);
}

inline void Vector2::operator +=(const Vector2& v) {
	x += v.x;
	y += v.y;
}

inline void Vector2::operator +=(float s) {
	x += s;
	y += s;
}

inline void Vector2::operator -=(const Vector2& v) {
	x -= v.x;
	y -= v.y;
}

inline void Vector2::operator -=(float s) {
	x -= s;
	y -= s;
}

inline void Vector2::operator *=(const Vector2& v) {
	x *= v.x;
	y *= v.y;
}

inline void Vector2::operator *=(float s) {
	x *= s;
	y *= s;
}

inline void Vector2::operator /=(const Vector2& v) {
	x *= (1.0f / v.x);
	y *= (1.0f / v.y);
}

inline void Vector2::operator /=(float s) {
	x *= (1.0f / s);
	y *= (1.0f / s);
}

inline void Vector2::Normalize() {
	float m = Magnitude();
	x /= m;
	y /= m;
}

inline float Vector2::Magnitude() {
	return sqrtf(x * x + y * y);
}

/*
* Vector3 
*/

inline Vector3 Vector3::operator +(const Vector3& v) const {
	return Vector3(x + v.x, y + v.y, z + v.z);
}

inline Vector3 Vector3::operator +(float s) const {
	return Vector3(x + s, y + s, z + s);
}

inline Vector3 Vector3::operator -(const Vector3& v) const {
	return Vector3(x - v.x, y - v.y, z - v.z);
}

inline Vector3 Vector3::operator -(float s) const {
	return Vector3(x - s, y - s, z - s);
}

inline Vector3 Vector3::operator *(const Vector3& v) const {
	return Vector3(x * v.x, y * v.y, z * v.z);
}

inline Vector3 Vector3::operator *(float s) const {
	return Vector3(x * s, y * s, z * s);
}

inline Vector3 Vector3::operator /(const Vector3& v) const {
	return Vector3(x * (1.0f / v.x), y * (1.0f / v.y), z * (1.0f / v.z));
}

inline Vector3 Vector3::operator /(float s) const {
	s = 1.0f / s;
	return Vector3(x * s, y * s, z * s);
}

inline void Vector3::operator +=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

inline void Vector3::operator +=(float s) {
	x += s;
	y += s;
	z += s;
}

inline void Vector3::operator -=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

inline void Vector3::operator -=(float s) {
	x -= s;
	y -= s;
	z -= s;
}

inline void Vector3::operator *=(const Vector3& v) {
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

inline void Vector3::operator *=(float s) {
	x *= s;
	y *= s;
	z *= s;
}

inline void Vector3::operator /=(const Vector3& v) {
	x *= (1.0f / v.x);
	y *= (1.0f / v.y);
	z *= (1.0f / v.z);
}

inline void Vector3::operator /=(float s) {
	s = 1.0f / s;
	x *= s;
	y *= s;
	z *= s;
}

inline void Vector3::Normalize() {
	float m = Magnitude();
	x /= m;
	y /= m;
	z /= m;
}

inline float Vector3::Magnitude() const {
	return sqrtf(x * x + y * y + z * z);
}

inline Vector2 Normalized(const Vector2& v) {
	float m = Magnitude(v);
	return Vector2(v.x / m, v.y / m);
}

/*
* Nonmember Functions
*/

inline Vector3 Normalized(const Vector3& v) {

}

inline float Magnitude(const Vector2& v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}

inline float Magnitude(const Vector3& v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline float Dot(const Vector2& a, const Vector2& b) {
	return a.x * b.x + a.y * b.y;
}

inline float Dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vector3 Cross(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.z * b.z,
		a.x * b.y - a.y * b.x);
}

inline Vector2 Project(const Vector2& a, const Vector2& b) {
	float bMagSquared = Magnitude(b) * Magnitude(b);
	return b * (Dot(a, b) / bMagSquared);
}

inline Vector3 Project(const Vector3& a, const Vector3& b) {
	float bMagSquared = Magnitude(b) * Magnitude(b);
	return b * (Dot(a, b) / bMagSquared);
}

inline Vector2 Reject(const Vector2& a, const Vector2& b) {
	return a - Project(a, b);
}

inline Vector3 Reject(const Vector3& a, const Vector3& b) {
	return a - Project(a, b);
}
