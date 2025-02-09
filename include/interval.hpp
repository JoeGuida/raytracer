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
	Interval(float t0, float t1, const glm::vec3& n0, const glm::vec3& n1) : t0(t0), t1(t1), n0(n0), n1(n1) {}
	Interval(const Interval&) = default;
	Interval(Interval&&) = default;
	virtual ~Interval() = default;

	Interval& operator=(const Interval& interval) {
		t0 = interval.t0;
		t1 = interval.t1;
		n0 = interval.n0;
		n1 = interval.n1;
		return *this;
	}

	void calculate(const Interval& a, const Interval& b) {
		if (a.t0 > b.t0) {
			t0 = a.t0;
			n0 = a.n0;
		}
		else {
			t0 = b.t0;
			n0 = b.n0;
		}

		if (a.t1 < b.t1) {
			t1 = a.t1;
			n1 = a.n1;
		}
		else {
			t1 = b.t1;
			n1 = b.n1;
		}
	}

	void swap() {
		float temp = t0;
		t0 = t1;
		t1 = temp;

		glm::vec3 temp_n = n0;
		n0 = n1;
		n1 = temp_n;
	}
};

#endif