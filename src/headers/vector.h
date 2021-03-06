#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "mathhelpers.h"

typedef struct Vector2 {

	float x;
	float y;

	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(float a, float b) {
		x = a;
		y = b;
	}

} Vector2;

typedef struct Vector3 {

	float x;
	float y;
	float z;

	Vector3() {
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}

} Vector3;

typedef struct Vector4 {

	float x;
	float y;
	float z;
	float w;

	Vector4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	Vector4(float a, float b, float c, float d) {
		x = a;
		y = b;
		z = c;
		w = d;
	}

} Vector4;

Vector2 operator +(const Vector2& a, const Vector2& b);
Vector3 operator +(const Vector3& a, const Vector3& b);
Vector4 operator +(const Vector4& a, const Vector4& b);

Vector2 operator +(const Vector2& v, float s);
Vector3 operator +(const Vector3& v, float s);
Vector4 operator +(const Vector4& v, float s);

Vector2 operator -(const Vector2& a, const Vector2& b);
Vector3 operator -(const Vector3& a, const Vector3& b);
Vector4 operator -(const Vector4& a, const Vector4& b);

Vector2 operator -(const Vector2& v, float s);
Vector3 operator -(const Vector3& v, float s);
Vector4 operator -(const Vector4& v, float s);

Vector2 operator -(const Vector2& v);
Vector3 operator -(const Vector3& v);
Vector4 operator -(const Vector4& v);

Vector2 operator *(const Vector2& a, const Vector2& b);
Vector3 operator *(const Vector3& a, const Vector3& b);
Vector4 operator *(const Vector4& a, const Vector4& b);

Vector2 operator *(const Vector2& v, float s);
Vector3 operator *(const Vector3& v, float s);
Vector4 operator *(const Vector4& v, float s);

Vector2 operator /(const Vector2& a, const Vector2& b);
Vector3 operator /(const Vector3& a, const Vector3& b);
Vector4 operator /(const Vector4& a, const Vector4& b);

Vector2 operator /(const Vector2& v, float s);
Vector3 operator /(const Vector3& v, float s);
Vector4 operator /(const Vector4& v, float s);

bool operator ==(const Vector2& a, const Vector2& b);
bool operator ==(const Vector3& a, const Vector3& b);
bool operator ==(const Vector4& a, const Vector4& b);

bool operator !=(const Vector2& a, const Vector2& b);
bool operator !=(const Vector3& a, const Vector3& b);
bool operator !=(const Vector4& a, const Vector4& b);

Vector2 normalized_vector(const Vector2& v);
Vector3 normalized_vector(const Vector3& v);
Vector4 normalized_vector(const Vector4& v);

float magnitude(const Vector2& v);
float magnitude(const Vector3& v);
float magnitude(const Vector4& v);

float dot_product(const Vector2& a, const Vector2& b);
float dot_product(const Vector3& a, const Vector3& b);
float dot_product(const Vector4& a, const Vector4& b);

Vector3 cross_product(const Vector3& a, const Vector3& b);

Vector2 projection(const Vector2& a, const Vector2& b);
Vector3 projection(const Vector3& a, const Vector3& b);
Vector4 projection(const Vector4& a, const Vector4& b);

Vector2 rejection(const Vector2& a, const Vector2& b);
Vector3 rejection(const Vector3& a, const Vector3& b);
Vector4 rejection(const Vector4& a, const Vector4& b);

Vector2 reflection(const Vector2& a, const Vector2& b);
Vector3 reflection(const Vector3& a, const Vector3& b);
Vector4 reflection(const Vector4& a, const Vector4& b);

float angle(const Vector2& a, const Vector2& b);
float angle(const Vector3& a, const Vector3& b);
float angle(const Vector4& a, const Vector4& b);

float distance(const Vector2& a, const Vector2& b);
float distance(const Vector3& a, const Vector3& b);
float distance(const Vector4& a, const Vector4& b);

#endif
