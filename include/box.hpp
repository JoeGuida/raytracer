#ifndef RAYTRACER_BOX_HPP
#define RAYTRACER_BOX_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

#include "interval.hpp"
#include "material.hpp"
#include "plane.hpp"
#include "shape.hpp"

struct Box : Shape {
	glm::vec3 position;
	glm::vec3 size;
	Material material;
	std::array<Plane, 6> planes;

	Box(const glm::vec3& position, const glm::vec3& size, const Material& material) : position(position), size(size), material(material) 
	{
		planes = {
			Plane(glm::vec3(1.0f, 0.0f, 0.0f), -position.x),
			Plane(glm::vec3(1.0f, 0.0f, 0.0f), -position.x - size.x),
			Plane(glm::vec3(0.0f, 1.0f, 0.0f), -position.y),
			Plane(glm::vec3(0.0f, 1.0f, 0.0f), -position.y - size.y),
			Plane(glm::vec3(0.0f, 0.0f, 1.0f), -position.z),
			Plane(glm::vec3(0.0f, 0.0f, 1.0f), -position.z - size.z)
		};
	}

	Box(const Box&) = default;
	Box(Box&&) = default;
	virtual ~Box() = default;

	virtual bool intersects(const Ray& ray, Hit& hit) const;
	virtual Material get_material() const override { return material; }
	virtual glm::vec3 get_pos() const override { return position; }
};

#endif