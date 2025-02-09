#ifndef RAYTRACER_BOUNDING_BOX_HPP
#define RAYTRACER_BOUNDING_BOX_HPP

#include "glm/vec3.hpp"

#include "hit.hpp"
#include "ray.hpp"
#include "slab.hpp"

class BoundingBox {
private:
	std::array<Slab, 3> slabs;

public:
	glm::vec3 min;
	glm::vec3 max;

	BoundingBox(const glm::vec3& min, const glm::vec3& max) : min(min), max(max)
	{
		slabs = {
			Slab(glm::vec3(1.0f, 0.0f, 0.0f), -min.x, -max.x),
			Slab(glm::vec3(0.0f, 1.0f, 0.0f), -min.y, -max.y),
			Slab(glm::vec3(0.0f, 0.0f, 1.0f), -min.z, -max.z)
		};
	}

	BoundingBox(const BoundingBox&) = default;
	BoundingBox(BoundingBox&&) = default;
	virtual ~BoundingBox() = default;

	bool intersects(const Ray& ray, Hit& hit) const;
};

#endif