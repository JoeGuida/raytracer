#include "../headers/matrix.h"

Vector3 operator *(const Matrix3D& m, const Vector3& v) {
	return Vector3(v.x * m.n[0][0], v.y * m.n[1][1], v.z * m.n[2][2]);
}