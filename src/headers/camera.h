#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.h"
#include "matrix.h"

class Camera {

	float fov;
	float aspect;
	float near;
	float far;
	float width;
	float height;

	Matrix4D world_transform;
	Matrix4D projection_matrix;

	int projection_mode; // 0 - Perspective, 1 - Orthographic

public:
	Matrix3D rotation;
	Vector3 position;
};

#endif