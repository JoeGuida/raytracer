#ifndef RAYTRACER_RECTANGLE_HPP
#define RAYTRACER_RECTANGLE_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

#include "interval.hpp"
#include "material.hpp"
#include "plane.hpp"
#include "shape.hpp"

struct Rectangle : Shape {
	glm::vec3 position;
	glm::vec3 size;
	Material material;

	Rectangle(const glm::vec3& position, const glm::vec3& size, const Material& material) : 
		position(position), size(size), material(material) {}

	virtual bool intersects(const Ray& ray, Hit& hit) const;
	virtual Material get_material() const override { return material; }
	virtual glm::vec3 get_pos() const override { return position; }
};

#endif