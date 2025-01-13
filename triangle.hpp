#ifndef RAYTRACER_TRIANGLE_HPP
#define RAYTRACER_TRIANGLE_HPP

#include "glm/vec3.hpp"

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Triangle : Shape {
	glm::vec3 position;
	glm::vec3 a;
	glm::vec3 b;
	glm::vec3 c;
	BRDFMaterial material;

	Triangle(const glm::vec3& position, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const BRDFMaterial& material) : position(position), a(a), b(b), c(c), material(material) {}
	bool intersects(const Ray& ray, Hit& hit) const override;
	const BRDFMaterial* get_material() const override { return &material; }
};

#endif