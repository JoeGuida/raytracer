#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "color.h"

typedef struct Material {

	Colorf color;
	float specular;

	Material() {
		color = Colorf(255, 255, 255);
		specular = 10;
	}

	Material(Colorf c, float s) {
		color = c;
		specular = s;
	}

} Material;

#endif