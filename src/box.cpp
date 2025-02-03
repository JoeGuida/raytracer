#include "box.hpp"

bool Box::intersects(const Ray& ray, Hit& hit) const {
	Interval interval;
	for (int i = 0; i < planes.size(); i += 2) {
		float t0 = 0.0f;
		float t1 = INFINITY;
		glm::vec3 n0 = planes[i].normal;
		glm::vec3 n1 = planes[i + 1].normal; 

		if (glm::dot(planes[i].normal, ray.direction) == 0.0f) {
			float s0 = planes[i].distance + glm::dot(planes[i].normal, ray.origin);
			float s1 = planes[i + 1].distance + glm::dot(planes[i + 1].normal, ray.origin);

			if ((s0 < 0.0f && s1 > 0.0f) || (s0 > 0.0f && s1 < 0.0f)) {
				t0 = 0.0f;
				t1 = INFINITY;
			}
			else {
				t0 = 1.0f;
				t0 = 0.0f;
			}
		}
		else {
			t0 = -(planes[i].distance + glm::dot(planes[i].normal, ray.origin)) / glm::dot(planes[i].normal, ray.direction);
			t1 = -(planes[i + 1].distance + glm::dot(planes[i + 1].normal, ray.origin)) / glm::dot(planes[i + 1].normal, ray.direction);
			interval.n1 *= -1.0f;

			if (t0 > t1) {
				float temp = t0;
				t0 = t1;
				t1 = t0;
			}
		}  
		
		if (t0 > interval.t0) {
			interval.t0 = t0;
			interval.n0 = n0;
		}
		if (t1 < interval.t1) {
			interval.t1 = t1;
			interval.n1 = n1;
		}
	}

	if ((interval.t0 > interval.t1) || interval.t0 < 0.0f || interval.t1 < 0.0f) {
		return false;
	}

	hit.material = material;
	hit.normal = interval.n0;
	hit.point = ray.origin + ray.direction * interval.t0;
	hit.t = interval.t0;

	return true;
}