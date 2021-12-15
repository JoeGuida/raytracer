#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "color.h"

typedef struct Material {

	Color color;
	float specularity;
	float reflectivity;

	Material() {
		color = Color(255, 255, 255);
		specularity = 10;
		reflectivity = 1.0f;
	}

	Material(Color c, float s, float r) {
		color = c;
		specularity = s;
		reflectivity = r;
	}

} Material;

#endif