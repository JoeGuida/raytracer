#ifndef RAYTRACER_TRIANGLE_HPP
#define RAYTRACER_TRIANGLE_HPP

#include "glm/vec3.hpp"

#include "shape.hpp"

struct Triangle : public Shape {
	glm::vec3 v0;
	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 position;
	Material material;

	Triangle(const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& position, const Material& material) : 
		v0(v0), v1(v1), v2(v2), position(position), material(material) {}
	Triangle(const Triangle&) = default;
	Triangle(Triangle&&) = default;
	virtual ~Triangle() = default;

	bool intersects(const Ray& ray, Hit& hit) const override;
	Material get_material() const override { return material; };
	glm::vec3 get_pos() const override { return position; };
};

#endif