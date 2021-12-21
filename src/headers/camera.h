#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.h"
#include "matrix.h"

typedef struct Camera {

	Vector3 position;
	Matrix3D rotation;

	Camera() {
		position = Vector3(0, 0, 0);
		rotation = Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	Camera(Vector3 p, Matrix3D r) {
		position = p;
		rotation = r;
	}

} Camera;

#endif