#include "../headers/matrix.h"

Matrix2 Matrix2::operator +(float s) const {
	return Matrix2(n[0][0] + s, n[0][1] + s,
		n[1][0] + s, n[1][1] + s);
}

Matrix2 Matrix2::operator +(const Matrix2& m) const {
	return Matrix2(n[0][0] + m.n[0][0], n[0][1] + m.n[0][1],
		n[1][0] + m.n[1][0], n[1][1] + m.n[1][1]);
}

Matrix2 Matrix2::operator -(float s) const {
	return Matrix2(n[0][0] - s, n[0][1] - s,
		n[1][0] - s, n[1][1] - s);
}

Matrix2 Matrix2::operator -(const Matrix2& m) const {
	return Matrix2(n[0][0] - m.n[0][0], n[0][1] - m.n[0][1],
		n[1][0] - m.n[1][0], n[1][1] - m.n[1][1]);
}

Matrix2 Matrix2::operator *(float s) const {
	return Matrix2(n[0][0] * s, n[0][1] * s,
		n[1][0] * s, n[1][1] * s);
}

Matrix2 Matrix2::operator *(const Matrix2& m) const {
	return Matrix2();
}

Matrix2 Matrix2::operator /(float s) const {
	s = s / 1.0f;
	return Matrix2(n[0][0] * s, n[0][1] * s,
		n[1][0] * s, n[1][1] * s);
}

Matrix2 Matrix2::operator /(const Matrix2& m) const {
	return Matrix2();
}