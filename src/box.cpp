#include "box.hpp"

bool Box::intersects(const Ray& ray, Hit& hit) const {
	Interval interval;

	for (const Slab& slab : slabs) {
		Interval slab_interval(0.0f, INFINITY, slab.normal, -slab.normal);
		float NdotD = glm::dot(slab.normal, ray.direction);
		float NdotO = glm::dot(slab.normal, ray.origin);

		if (NdotD == 0.0f) {
			continue;
		}

		float t0 = -(slab.d0 + NdotO) / NdotD;
		float t1 = -(slab.d1 + NdotO) / NdotD;
		slab_interval.t0 = t0;
		slab_interval.t1 = t1;

		if (t0 > t1) {
			slab_interval.swap();
		}

		if (slab_interval.t0 > interval.t0) {
			interval.t0 = slab_interval.t0;
			interval.n0 = slab_interval.n0;
		}

		if (slab_interval.t1 < interval.t1) {
			interval.t1 = slab_interval.t1;
			interval.n1 = slab_interval.n1;
		}
	}

	if (interval.t0 > interval.t1) {
		return false;
	}

	hit.material = material;
	hit.normal = interval.n0;
	hit.point = ray.origin + ray.direction * interval.t0;
	hit.t = interval.t0;
	return true;
}