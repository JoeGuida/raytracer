#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.h"

class Camera {
public:
	Vector3 position;
	Vector3 direction;

	Camera() {
		position = Vector3();
		direction = Vector3();
	}

	Camera(Vector3 p, Vector3 d) {
		position = p;
		direction = d;
	}

};

#endif