#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "color.h"

// Vacuum: 1
// Air   : 1.000273
// Water : 1.333
// Glass : 1.52

typedef struct Material {

	Color color;
	float specularity;
	float reflectivity;
	float refraction_index;
	float transparency;

	Material() {
		color = Color(255, 255, 255);
		specularity = 10;
		reflectivity = 1.0f;
		refraction_index = 1.000293f;
		transparency = 0.0f;
	}

	Material(Color c, float s, float r) {
		color = c;
		specularity = s;
		reflectivity = r;
		refraction_index = 1.000273;
		transparency = 0.0f;
	}

	Material(Color c, float s, float r, float i, float t) {
		color = c;
		specularity = s;
		reflectivity = r;
		refraction_index = i;
		transparency = t;
	}

} Material;

bool operator ==(const Material& l, const Material& r);
bool operator !=(const Material& l, const Material& r);

#endif