#include "../headers/matrix.h"

Vector3 operator *(const Vector3& v, const Matrix3D& m) {
	float x = m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z;
	float y = m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z;
	float z = m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z;
	return Vector3(x, y, z);
}