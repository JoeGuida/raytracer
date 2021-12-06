#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "color.h"
#include "vector.h"

enum LightTypes {
	AMBIENT,
	DIRECTIONAL,
	POINT
};

typedef struct Light {

	Colorf color;
	Vector3 direction;
	Point position;
	float intensity;
	int type;

	// Ambient Light
	Light(float i, Colorf c) {
		type = AMBIENT;
		intensity = i;
		color = c;
	}

	// Directional Light 
	Light(float i, Colorf c, Vector3 d) {
		type = DIRECTIONAL;
		intensity = i;
		color = c;
		direction = d;
	}

	// Point Light
	Light(Point p, float i, Colorf c) {
		type = POINT;
		intensity = i;
		color = c;
		position = p;
	}

} Light;

#endif