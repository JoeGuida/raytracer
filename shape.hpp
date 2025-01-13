#ifndef RAYTRACER_SHAPE_HPP
#define RAYTRACER_SHAPE_HPP

#include "hit.hpp"
#include "material.hpp"
#include "ray.hpp"

struct Shape {
	virtual bool intersects(const Ray& ray, Hit& hit) const = 0;
	virtual const BRDFMaterial* get_material() const = 0;
};

#endif