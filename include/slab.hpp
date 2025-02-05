#ifndef RAYTRACER_SLAB_HPP
#define RAYTRACER_SLAB_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

#include "hit.hpp"
#include "interval.hpp"
#include "ray.hpp"

struct Slab {
	glm::vec3 normal;
	float d0;
	float d1;

	Slab() : normal(glm::vec3(0.0f)), d0(0.0f), d1(0.0f) {}
	Slab(const glm::vec3& normal, float d0, float d1) : normal(glm::normalize(normal)), d0(d0), d1(d1) {}
	Slab(const Slab&) = default;
	Slab(Slab&&) = default;
	virtual ~Slab() = default;

	Slab& operator=(const Slab& slab) {
		normal = slab.normal;
		d0 = slab.d0;
		d1 = slab.d1;
		return *this;
	}

	Interval intersection(const Ray& ray) const;
};

#endif