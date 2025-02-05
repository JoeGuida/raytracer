#ifndef RAYTRACER_BOX_HPP
#define RAYTRACER_BOX_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

#include "interval.hpp"
#include "material.hpp"
#include "slab.hpp"
#include "shape.hpp"

class Box : public Shape {
private:
	std::array<Slab, 3> slabs;

public:
	glm::vec3 min;
	glm::vec3 max;
	Material material;

	Box(const glm::vec3& min, const glm::vec3& max, const Material& material) : min(min), max(max), material(material)
	{
		slabs = {
			Slab(glm::vec3(1.0f, 0.0f, 0.0f), -min.x, -max.x),
			Slab(glm::vec3(0.0f, 1.0f, 0.0f), -min.y, -max.y),
			Slab(glm::vec3(0.0f, 0.0f, 1.0f), -min.z, -max.z)
		};
	}

	Box(const Box&) = default;
	Box(Box&&) = default;
	virtual ~Box() = default;

	bool intersects(const Ray& ray, Hit& hit) const;
	Material get_material() const override { return material; }
	glm::vec3 get_pos() const override { return max; }
};

#endif