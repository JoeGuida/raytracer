#include "../headers/material.h"

bool operator ==(const Material& l, const Material& r) {
	return l.color == r.color && l.specularity == r.specularity && l.reflectivity == r.reflectivity;
}

bool operator !=(const Material& l, const Material& r) {
	return !(l == r);
}