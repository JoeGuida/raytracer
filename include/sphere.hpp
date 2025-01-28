#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "glm/vec3.hpp"

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Sphere : public Shape {
	glm::vec3 center;
	float radius;
	Material material;

	Sphere(const glm::vec3& center, float radius, const Material& material) : center(center), radius(radius), material(material) {}
	virtual bool intersects(const Ray& ray, Hit& hit) const override;
	virtual Material get_material() const override { return material; }
	virtual glm::vec3 get_pos() const override { return center; }
};

#endif