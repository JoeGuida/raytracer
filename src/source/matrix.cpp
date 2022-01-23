#include "../headers/matrix.h"

Matrix2D operator *(const Matrix2D& m, float s) {
	Matrix2D result;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			result.n[i][j] = m(i,j) * s;

	return result;
}

Matrix3D operator *(const Matrix3D& m, float s) {
	Matrix3D result;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.n[i][j] = m(i, j) * s;

	return result;
}

Matrix4D operator *(const Matrix4D& m, float s) {
	Matrix4D result;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			result.n[i][j] = m(i, j) * s;

	return result;
}

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
	return m.n[0][0] * m.n[1][1] - m.n[0][1] * m.n[1][0];
}

float determinant(const Matrix3D& m) {
	float result = 0;
	Matrix3D cofactor_matrix = cofactor(minor(m));

	for(int i = 1; i < 3; i++)
		result += cofactor_matrix(1, i) * m(1, i);

	return result;
}

float determinant(const Matrix4D& m) {
	float result = 0;
	Matrix4D cofactor_matrix = cofactor(minor(m));

	for (int i = 1; i < 3; i++)
		result += cofactor_matrix(1, i) * m(1, i);

	return result;
}

Matrix2D cut(const Matrix3D& matrix, int row, int col) {
	Matrix2D result;
	int result_row = 0;
	int result_col = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == row || j == col)
				continue;

			result.n[result_row][result_col] = matrix.n[i][j];

			if (result_col == 1) {
				result_col = 0;
				result_row++;
			}
			else
				result_col++;
		}
	}

	return result;
}

Matrix3D cut(const Matrix4D& matrix, int row, int col) {
	Matrix3D result;
	int result_row = 0;
	int result_col = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == row || j == col)
				continue;

			result.n[result_row][result_col] = matrix.n[i][j];

			if (result_col == 2) {
				result_col = 0;
				result_row++;
			}
			else
				result_col++;
		}
	}

	return result;
}

Matrix3D minor(const Matrix3D& matrix) {
	Matrix3D result;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			result.n[i][j] = determinant(cut(matrix, i, j));

	return result;
}

Matrix4D minor(const Matrix4D& matrix) {
	Matrix4D result;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			result.n[i][j] = determinant(cut(matrix, i, j));

	return result;
}

Matrix2D cofactor(const Matrix2D& minor_matrix) {
	Matrix2D result;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			float sign = powf(-1.0f, i + j);
			result.n[i][j] = minor_matrix.n[i][j] * sign;
		}
	}

	return result;
}

Matrix3D cofactor(const Matrix3D& minor_matrix) {
	Matrix3D result;

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) {
			float sign = powf(-1.0f, i + j);
			result.n[i][j] = minor_matrix.n[i][j] * sign;
		}

	return result;
}

Matrix4D cofactor(const Matrix4D& minor_matrix) {
	Matrix4D result;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			float sign = powf(-1.0f, i + j);
			result.n[i][j] = minor_matrix.n[i][j] * sign;
		}

	return result;
}

Matrix2D adjugate(const Matrix2D& matrix) {
	return transpose(cofactor(matrix));
}

Matrix3D adjugate(const Matrix3D& matrix) {
	return transpose(cofactor(matrix));
}

Matrix4D adjugate(const Matrix4D& matrix) {
	return transpose(cofactor(matrix));
}

Matrix2D inverse(const Matrix2D& matrix) {
	float inverse_determinant = 1 / determinant(matrix);

	if (cmp_float(inverse_determinant, 0))
		return Matrix2D();
	
	Matrix2D result;
	Matrix2D adjugate_matrix = adjugate(matrix);
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			result.n[i][j] = adjugate_matrix.n[i][j] * inverse_determinant;

	return result;
}

Matrix3D inverse(const Matrix3D& matrix) {
	float inverse_determinant = 1 / determinant(matrix);

	if (cmp_float(inverse_determinant, 0))
		return Matrix3D();

	Matrix3D result;
	Matrix3D adjugate_matrix = adjugate(matrix);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			result.n[i][j] = adjugate_matrix.n[i][j] * inverse_determinant;

	return result;
}

Matrix4D inverse(const Matrix4D& matrix) {
	float inverse_determinant = 1 / determinant(matrix);

	if (cmp_float(inverse_determinant, 0))
		return Matrix4D();

	Matrix4D result;
	Matrix4D adjugate_matrix = adjugate(matrix);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			result.n[i][j] = adjugate_matrix.n[i][j] * inverse_determinant;

	return result;
}

Vector3 operator *(const Vector3& v, const Matrix3D& m) {
	float x = m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z;
	float y = m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z;
	float z = m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z;
	return Vector3(x, y, z);
}

Matrix4D translation(float x, float y, float z) {
	return Matrix4D{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		x, y, z, 1.0f
	};
}

Matrix4D translation(const Vector3& pos) {
	return Matrix4D{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		pos.x, pos.y, pos.z, 1.0f
	};
}

Vector3 get_translation(const Matrix4D& matrix) {
	return Vector3(matrix(3, 0), matrix(3, 1), matrix(3, 2));
}

Matrix4D scale(float x, float y, float z) {
	return Matrix4D{
		x, 0.0f, 0.0f, 0.0f,
		0.0f, y, 0.0f, 0.0f,
		0.0f, 0.0f, z, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	};
}

Matrix4D scale(const Vector3& v) {
	return Matrix4D{
		v.x, 0.0f, 0.0f, 0.0f,
		0.0f, v.y, 0.0f, 0.0f,
		0.0f, 0.0f, v.z, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	};
}

Vector3 get_scale(const Matrix4D& matrix) {
	return Vector3(matrix(0, 0), matrix(1, 1), matrix(2, 2));
}

Matrix4D rotation(float pitch, float yaw, float roll) {
	return z_rotation(roll) * x_rotation(pitch) * y_rotation(yaw);
}

Matrix3D rotation_3D(float pitch, float yaw, float roll) {
	return z_rotation_3D(roll) * x_rotation_3D(pitch) * y_rotation_3D(yaw);
}

Matrix4D x_rotation(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix4D{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, c, s, 0.0f,
		0.0f, -s, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

Matrix4D y_rotation(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix4D{
		c, 0.0f, -s, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		s, 0.0f, c, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
} 

Matrix4D z_rotation(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix4D{
		c, s, 0.0f, 0.0f,
		-s, c, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

Matrix3D x_rotation_3D(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix3D{
		1.0f, 0.0f, 0.0f,
		0.0f, c, s,
		0.0f, -s, c,
	};
}

Matrix3D y_rotation_3D(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix3D{
		c, 0.0f, -s,
		0.0f, 1.0f, 0.0f,
		s, 0.0f, c,
	};
}

Matrix3D z_rotation_3D(float theta) {
	theta = degrees_to_radians(theta);
	float c = cosf(theta);
	float s = sinf(theta);

	return Matrix3D{
		c, s, 0,
		-s, c, 0,
		0, 0, 1
	};
}

Matrix4D axis_angle(const Vector3& axis, float angle) {
	angle = degrees_to_radians(angle);
	float c = cosf(angle);
	float s = sinf(angle);
	float t = 1 - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	if (!cmp_float(magnitude(axis) * magnitude(axis), 1.0f)) {
		float inv_len = 1.0f / magnitude(axis);
		x *= inv_len;
		y *= inv_len;
		z *= inv_len;
	}

	float txsq = t * powf(x, 2) + c;
	float tysq = t * powf(y, 2) + c;
	float tzsq = t * powf(z, 2) + c;

	float txy = t * x * y + s * z;
	float txz = t * x * z + s * y;
	float tyz = t * y * z + s * x;


	return Matrix4D{
		txsq, txy, txz, 0.0f,
		txy, tysq, tyz, 0.0f,
		txz, tyz, tzsq, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

Matrix3D axis_angle_3D(const Vector3& axis, float angle) {
	angle = degrees_to_radians(angle);
	float c = cosf(angle);
	float s = sinf(angle);
	float t = 1 - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	if (!cmp_float(magnitude(axis) * magnitude(axis), 1.0f)) {
		float inv_len = 1.0f / magnitude(axis);
		x *= inv_len;
		y *= inv_len;
		z *= inv_len;
	}

	float txsq = t * powf(x, 2) + c;
	float tysq = t * powf(y, 2) + c;
	float tzsq = t * powf(z, 2) + c;

	float txy = t * x * y + s * z;
	float txz = t * x * z + s * y;
	float tyz = t * y * z + s * x;


	return Matrix3D{
		txsq, txy, txz,
		txy, tysq, tyz,
		txz, tyz, tzsq
	};
}

Matrix4D transform(const Vector3& scale_vector, const Vector3& euler_rotation, const Vector3& translation_vector) {
	return scale(scale_vector) * rotation(euler_rotation.x, euler_rotation.y, euler_rotation.z) * translation(translation_vector);
}

Matrix4D transform(const Vector3& scale_vector, const Vector3& rotation_axis, float rotation_angle, const Vector3& translation_vector) {
	return scale(scale_vector) * axis_angle(rotation_axis, rotation_angle) * translation(translation_vector);
}

Matrix4D look_at(const Vector3& position, const Vector3& target, const Vector3& up) {
	Vector3 forward = normalized_vector(target - position);
	Vector3 right = normalized_vector(cross_product(up, forward));
	Vector3 new_up = normalized_vector(cross_product(forward, right));

	return Matrix4D{
		right.x, new_up.x, forward.x, 0.0f,
		right.y, new_up.y, forward.y, 0.0f,
		right.z, new_up.z, forward.z, 0.0f,
		-dot_product(right, position), -dot_product(new_up, position), -dot_product(forward, position), 1.0f
	};
}

Matrix4D projection(float fov, float aspect_ratio, float near, float far) {
	float tan_half_fov = tanf(degrees_to_radians(fov * 0.5f));
	float fov_y = 1.0f / tan_half_fov;
	float fov_x = fov_y / aspect_ratio;

	Matrix4D result;

	result.n[0][0] = fov_x;
	result.n[1][1] = fov_y;
	result.n[2][2] = far / (far - near);
	result.n[2][3] = 1.0f;
	result.n[3][2] = -near * result.n[2][2];
	result.n[3][3] = 0.0f;

	return result;
}

Matrix4D orthographic(float left, float right, float bottom, float top, float near, float far) {
	float _00 = 2.0f / (right - left);
	float _11 = 2.0f / (top - bottom);
	float _22 = 1.0f / (far - near);
	float _30 = (left + right) / (left - right);
	float _31 = (top + bottom) / (bottom - top);
	float _32 = near / (near - far);

	return Matrix4D{
		_00, 0.0f, 0.0f, 0.0f,
		0.0f, _11, 0.0f, 0.0f,
		0.0f, 0.0f, _22, 0.0f,
		_30, _31, _32, 1.0f
	};
 }