#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "color.h"

typedef struct Material {

	Color color;

	Material() {
		color = Color(128, 128, 128);
	}

	Material(Color c) {
		color = c;
	}

} Material;

#endif