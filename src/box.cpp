#include "box.hpp"

bool Box::intersects(const Ray& ray, Hit& hit) const {
	Interval interval;

	for (const Slab& slab : slabs) {
		Interval i = slab.intersection(ray);
		interval.calculate(interval, i);
	}

	if (interval.t0 > interval.t1) {
		return false;
	}

	if (interval.t0 < 0.0f && interval.t1 < 0.0f) {
		return false;
	}

	hit.material = &material;
	hit.normal = interval.n0;
	hit.point = ray.origin + ray.direction * interval.t0;
	hit.t = interval.t0;
	return true;
}