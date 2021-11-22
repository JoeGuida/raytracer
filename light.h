#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "color.h"

typedef struct AmbientLight {
	
	Color color;
	float intensity;

} AmbientLight;

typedef struct DirectionalLight {

	Color color;
	float intensity;

} DirectionalLight;

typedef struct PointLight {

	Color color;
	float intensity;

};

#endif