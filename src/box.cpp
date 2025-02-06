#include "box.hpp"

bool Box::intersects(const Ray& ray, Hit& hit) const {
	Interval interval;

	for (const Slab& slab : slabs) {
		Interval i = slab.intersection(ray);

		if (i.t0 > interval.t0) {
			interval.t0 = i.t0;
			interval.n0 = i.n0;
		}

		if (i.t1 < interval.t1) {
			interval.t1 = i.t1;
			interval.n1 = i.n1;
		}
	}

	if (interval.t0 > interval.t1) {
		return false;
	}

	hit.material = &material;
	hit.normal = interval.n0;
	hit.point = ray.origin + ray.direction * interval.t0;
	hit.t = interval.t0;
	return true;
}