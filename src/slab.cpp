#include "slab.hpp"

Interval Slab::intersection(const Ray& ray) const {
	float NdotD = glm::dot(normal, ray.direction);
	float NdotO = glm::dot(normal, ray.origin);

	if (NdotD == 0.0f) {
		float s0 = NdotO + d0;
		float s1 = NdotO + d1;

		if (std::signbit(s0) != std::signbit(s1)) {
			return Interval(0.0f, INFINITY, normal, -normal);
		}
		else {
			return Interval(1.0f, 0.0f, normal, -normal);
		}
	}

	float t0 = -(d0 + NdotO) / NdotD;
	float t1 = -(d1 + NdotO) / NdotD;
	Interval interval(t0, t1, normal, -normal);

	if (t0 > t1) {
		interval.swap();
	}

	return interval;
}