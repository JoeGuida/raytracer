#include "rectangle.hpp"

bool Rectangle::intersects(const Ray& ray, Interval& interval) const {
	Plane x0(glm::vec3(-1.0f, 0.0f, 0.0f), -size.x / 2.0f);
	Plane x1(glm::vec3(-1.0f, 0.0f, 0.0f),  size.x / 2.0f);
	Plane y0(glm::vec3(0.0f,  1.0f, 0.0f), -size.y / 2.0f);
	Plane y1(glm::vec3(0.0f,  1.0f, 0.0f),  size.y / 2.0f);
	Plane z0(glm::vec3(0.0f,  0.0f, 0.0f), -size.z / 2.0f);
	Plane z1(glm::vec3(0.0f,  0.0f, 0.0f),  size.z / 2.0f);
	
	std::array<Plane, 6> planes{ x0, x1, y0, y1, z0, z1 };
	Interval in(0.0f, INFINITY);

	for (int i = 0; i < planes.size(); i += 2) {
		if (glm::dot(planes[i].normal, ray.direction) == 0) {
			continue;
		}

		float t0 = -(planes[i].distance + glm::dot(planes[i].normal, ray.origin)) / glm::dot(planes[i].normal, ray.direction);
		float t1 = -(planes[i + 1].distance + glm::dot(planes[i + 1].normal, ray.origin)) / glm::dot(planes[i + 1].normal, ray.direction);
		in.t0 = t0;
		in.t1 = t1;

		if (t0 > t1) {
			float temp = t0;
			t0 = t1;
			t1 = t0;
		}

		float s0 = planes[i].distance + glm::dot(planes[i].normal, ray.origin);
		float s1 = planes[i + 1].distance + glm::dot(planes[i + 1].normal, ray.origin);

		if ((s0 < 0.0f && s1 > 0.0f) || (s0 > 0.0f && s1 < 0.0f)) {
			in.t0 = 0.0f;
			in.t1 = INFINITY;
		}
		else {
			in.t0 = 1.0f;
			in.t0 = 0.0f;
		}
		
		if (in.t0 > interval.t0) {
			interval.t0 = in.t0;
		}
		if (in.t1 < interval.t1) {
			interval.t1 = in.t1;
		}
	}

	if ((interval.t0 > interval.t1) || interval.t0 < 0.0f || interval.t1 < 0.0f) {
		return false;
	}

	return true;
}

bool Rectangle::intersects(const Ray& ray, Hit& hit) const {
	return false;
}