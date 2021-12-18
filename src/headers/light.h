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

	Color color;
	Vector3 direction;
	Point position;
	float intensity;
	int type;

	// Ambient Light
	Light(float i, Color c) {
		type = AMBIENT;
		intensity = i;
		color = c;
	}

	// Directional Light 
	Light(float i, Color c, Vector3 d) {
		type = DIRECTIONAL;
		intensity = i;
		color = c;
		direction = normalized_vector(d);
	}

	// Point Light
	Light(Point p, float i, Color c) {
		type = POINT;
		intensity = i;
		color = c;
		position = p;
	}

} Light;

#endif