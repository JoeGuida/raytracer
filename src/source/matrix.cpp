#include "../headers/matrix.h"
#include <iostream>

Matrix2D operator *(const Matrix2D& a, Matrix2D& b) {
	Matrix2D matrix;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			float sum = 0;
			for (int k = 0; k < 2; k++)
				sum += a(i, k) * b(k, j);

			matrix.n[i][j] = sum;
		}
	}

	return matrix;
}

Matrix3D operator *(const Matrix3D& a, Matrix3D& b) {
	Matrix3D matrix;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float sum = 0;
			for (int k = 0; k < 3; k++) 
				sum += a(i, k) * b(k, j);

			matrix.n[i][j] = sum;
		}
	}

	return matrix;
}

Matrix4D operator *(const Matrix4D& a, Matrix4D& b) {
	Matrix4D matrix;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float sum = 0;
			for (int k = 0; k < 4; k++)
				sum += a(i, k) * b(k, j);

			matrix.n[i][j] = sum;
		}
	}

	return matrix;
}

Matrix2D transpose(const Matrix2D& matrix) {
	Matrix2D m;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			m.n[i][j] = matrix(j, i);

	return m;
}

Matrix3D transpose(const Matrix3D& matrix) {
	Matrix3D m;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			m.n[i][j] = matrix(j, i);

	return m;
}

Matrix4D transpose(const Matrix4D& matrix) {
	Matrix4D m;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m.n[i][j] = matrix(j, i);

	return m;
}

float determinant(const Matrix2D& m) {
	return 0;
}

float determinant(const Matrix3D& m) {
	return 0;
}

float determinant(const Matrix4D& m) {
	return 0;
}

Matrix2D cut(const Matrix2D& matrix, int row, int col) {
	return Matrix2D();
}

Matrix2D minor(const Matrix2D& matrix) {
	return Matrix2D();
}

Matrix3D minor(const Matrix3D& matrix) {
	return Matrix3D();
}

Matrix4D minor(const Matrix4D& matrix) {
	return Matrix4D();
}

void cofactor(float* out, const float* minor, int rows, int cols) {
	
}

Matrix2D cofactor(const Matrix2D& matrix) {
	return Matrix2D();
}

Matrix3D cofactor(const Matrix3D& matrix) {
	return Matrix3D();
}

Matrix4D cofactor(const Matrix4D& matrix) {
	return Matrix4D();
}

Matrix2D adjugate(const Matrix2D& matrix) {
	return Matrix2D();
}

Matrix3D adjugate(const Matrix3D& matrix) {
	return Matrix3D();
}

Matrix4D adjugate(const Matrix4D& matrix) {
	return Matrix4D();
}

Matrix2D inverse(const Matrix2D& matrix) {
	return Matrix2D();
}

Matrix3D inverse(const Matrix3D& matrix) {
	return Matrix3D();
}

Matrix4D inverse(const Matrix4D& matrix) {
	return Matrix4D();
}

Vector3 operator *(const Vector3& v, const Matrix3D& m) {
	float x = m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z;
	float y = m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z;
	float z = m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z;
	return Vector3(x, y, z);
}