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

	inline Vector2 operator +(const Vector2& v) const;
	inline Vector2 operator +(float s) const;
	inline Vector2 operator -(const Vector2& v) const;
	inline Vector2 operator -(float s) const;
	inline Vector2 operator *(const Vector2& v) const;
	inline Vector2 operator *(float s) const;
	inline Vector2 operator /(const Vector2& v) const;
	inline Vector2 operator /(float s) const;

	inline void operator +=(const Vector2& v);
	inline void operator +=(float s);
	inline void operator -=(const Vector2& v);
	inline void operator -=(float s);
	inline void operator *=(const Vector2& v);
	inline void operator *=(float s);
	inline void operator /=(const Vector2& v);
	inline void operator /=(float s);

	inline void Normalize();
	inline float Magnitude();

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

	inline Vector3 operator +(const Vector3& v) const;
	inline Vector3 operator +(float s) const;
	inline Vector3 operator -(const Vector3& v) const;
	inline Vector3 operator -(float s) const;
	inline Vector3 operator *(const Vector3& v) const;
	inline Vector3 operator *(float s) const;
	inline Vector3 operator /(const Vector3& v) const;
	inline Vector3 operator /(float s) const;

	inline void operator +=(const Vector3& v);
	inline void operator +=(float s);
	inline void operator -=(const Vector3& v);
	inline void operator -=(float s);
	inline void operator *=(const Vector3& v);
	inline void operator *=(float s);
	inline void operator /=(const Vector3& v);
	inline void operator /=(float s);

	inline void Normalize();
	inline float Magnitude() const;

} Vector3;

inline Vector2 Normalized(const Vector2& v);
inline Vector3 Normalized(const Vector3& v);
inline float Magnitude(const Vector2& v);
inline float Magnitude(const Vector3& v);
inline float Dot(const Vector2& a, const Vector2& b);
inline float Dot(const Vector3& a, const Vector3& b);
inline Vector3 Cross(const Vector3& a, const Vector3& b);
inline Vector2 Project(const Vector2& a, const Vector2& b);
inline Vector3 Project(const Vector3& a, const Vector3& b);
inline Vector2 Reject(const Vector2& a, const Vector2& b);
inline Vector3 Reject(const Vector3& a, const Vector3& b);

#endif