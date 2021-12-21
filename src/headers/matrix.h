#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "vector.h"

typedef struct Matrix2D {

	float n[2][2];

	Matrix2D() {
		n[0][0] = 0; n[0][1] = 0;
		n[1][0] = 0; n[1][1] = 0;
	}

	Matrix2D(float n00, float n01, 
			float n10, float n11) {
		n[0][0] = n00; n[0][1] = n01;
		n[1][0] = n10; n[1][1] = n11;
	}

	Matrix2D(const Vector2& a, const Vector2& b) {
		n[0][0] = a.x; n[0][1] = a.y;
		n[1][0] = b.x; n[1][1] = b.y;
	}

	float& operator ()(int i, int j) {
		return n[j][i];
	}

	Vector2& operator [](int i) {
		return *reinterpret_cast<Vector2*>(n[i]);
	}

} Matrix2D;

typedef struct Matrix3D {

	float n[3][3];

	Matrix3D() {
		n[0][0] = 0; n[0][1] = 0; n[0][2] = 0;
		n[1][0] = 0; n[1][1] = 0; n[1][2] = 0;
		n[2][0] = 0; n[2][1] = 0; n[2][2] = 0;
	}

	Matrix3D(float n00, float n01, float n02, 
			float n10, float n11, float n12,
			float n20, float n21, float n22) {
		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
	}

	Matrix3D(const Vector3& a, const Vector3& b, const Vector3& c) {
		n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
		n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
		n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
	}

	float& operator ()(int i, int j) {
		return n[i][j];
	}

	Vector3& operator [](int i) {
		return *reinterpret_cast<Vector3*>(n[i]);
	}

} Matrix3D;

Vector3 operator *(const Matrix3D& m, const Vector3& v);

#endif