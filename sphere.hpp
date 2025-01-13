#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "glm/vec3.hpp"

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Sphere : Shape {
	glm::vec3 position;
	float radius;
	BRDFMaterial material;

	Sphere(const glm::vec3& position, float radius, const BRDFMaterial& material) : position(position), radius(radius), material(material) {}
	bool intersects(const Ray& ray, Hit& hit) const override;
};

#endif