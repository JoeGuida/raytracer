#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#include "glm/mat3x3.hpp"

#include "hit.hpp"
#include "interval.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "slab.hpp"

class Cylinder : public Shape {
private:
	glm::mat3x3 rotation_matrix;
	Slab slab;

public:
	glm::vec3 base;
	glm::vec3 axis;
	float radius;
	Material material;


	Cylinder(const glm::vec3& base, const glm::vec3& axis, float radius, const Material& material) : 
		base(base), axis(axis), radius(radius), material(material) 
	{
		slab = Slab(glm::vec3(0.0f, 0.0f, 1.0f), 0.0f, -glm::length(axis));
		glm::vec3 a = glm::normalize(axis);
		glm::vec3 v(0.0f, 0.0f, 1.0f);

		if (fabsf(glm::length(glm::cross(v, a)) - 0.0f) < FLT_EPSILON) {
			v = glm::vec3(1.0f, 0.0f, 0.0f);
		}

		glm::vec3 b = glm::normalize(glm::cross(v, a));
		glm::vec3 c = glm::cross(a, b);
		glm::mat3x3 Rt = { b, c, a };
		rotation_matrix = glm::transpose(Rt);
	}

	Cylinder(const Cylinder&) = default;
	Cylinder(Cylinder&&) = default;
	virtual ~Cylinder() = default;

	bool intersects(const Ray& ray, Hit& hit) const override;
	Material get_material() const override { return material; }
	glm::vec3 get_pos() const override { return base; }
};

#endif