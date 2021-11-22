#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "color.h"
#include "vector.h"

typedef struct AmbientLight {
	
	Color color;
	float intensity;

} AmbientLight;

typedef struct DirectionalLight {

	Vector3 direction;
	Color color;
	float intensity;

} DirectionalLight;

typedef struct PointLight {

	Vector3 position;
	Color color;
	float intensity;

};

#endif