#ifndef _VECTOR_H_
#define _VECTOR_H_

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

Vector2 operator +(const Vector2& a, const Vector2& b);
Vector2 operator +(const Vector2& v, float s);
Vector2 operator -(const Vector2& a, const Vector2& b);
Vector2 operator -(const Vector2& v, float s);
Vector2 operator *(const Vector2& a, const Vector2& b);
Vector2 operator *(const Vector2& v, float s);
Vector2 operator /(const Vector2& a, const Vector2& b);
Vector2 operator /(const Vector2& v, float s);

Vector2 Normalized(const Vector2& v);
float Magnitude(const Vector2& v);
float Dot(const Vector2& a, const Vector2& b);
Vector2 Project(const Vector2& a, const Vector2& b);
Vector2 Reject(const Vector2& a, const Vector2& b);
float Angle(const Vector2& a, const Vector2& b);

Vector3 operator +(const Vector3& a, const Vector3& b);
Vector3 operator +(const Vector3& v, float s);
Vector3 operator -(const Vector3& a, const Vector3& b);
Vector3 operator -(const Vector3& v, float s);
Vector3 operator *(const Vector3& a, const Vector3& b);
Vector3 operator *(const Vector3& v, float s);
Vector3 operator /(const Vector3& a, const Vector3& b);
Vector3 operator /(const Vector3& v, float s);

Vector3 Normalized(const Vector3& v);
float Magnitude(const Vector3& v);
float Dot(const Vector3& a, const Vector3& b);
Vector3 Cross(const Vector3& a, const Vector3& b);
Vector3 Project(const Vector3& a, const Vector3& b);
Vector3 Reject(const Vector3& a, const Vector3& b);
float Angle(const Vector3& a, const Vector3& b);

#endif