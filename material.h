#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "color.h"

typedef struct Material {

	Color color;
	float specular;

	Material() {
		color = Color(255, 255, 255);
		specular = 10;
	}

	Material(Color c, float s) {
		color = c;
		specular = s;
	}

} Material;

#endif