#ifndef RAYTRACER_SHAPE_HPP
#define RAYTRACER_SHAPE_HPP

#include "hit.hpp"
#include "material.hpp"
#include "ray.hpp"

class Shape {
public:
	virtual bool intersects(const Ray& ray, Hit& hit) const = 0;
	virtual Material get_material() const = 0;
	virtual glm::vec3 get_pos() const = 0;
};

#endif