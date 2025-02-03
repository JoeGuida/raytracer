#ifndef RAYTRACER_INTERVAL_HPP
#define RAYTRACER_INTERVAL_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

#include <array>

struct Interval {
	float t0;
	float t1;
	glm::vec3 n0;
	glm::vec3 n1;

	Interval() : t0(0.0f), t1(INFINITY), n0(glm::vec3(0.0f)), n1(glm::vec3(0.0f)) {}
	Interval(const Interval&) = default;
	Interval(Interval&&) = default;
	virtual ~Interval() = default;
	Interval& operator=(const Interval& other) {
		t0 = other.t0;
		t1 = other.t1;
	}

	void swap() {
		float temp = t0;
		t0 = t1;
		t1 = temp;

		glm::vec3 temp_n = n0;
		n0 = n1;
		n1 = n0;
	}
};

#endif