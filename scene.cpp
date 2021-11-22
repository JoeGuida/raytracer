#include "scene.h"

Color Scene::TraceRay(const Ray& ray, Hit& hit, float tmin, float tmax) {
	float closest_t = INFINITY;
	Sphere* closestSphere = NULL;
	for (Sphere& sphere : spheres) {
		float t1, t2 = 0;
		sphere.intersects(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closest_t) {
			closest_t = t1;
			closestSphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closest_t) {
			closest_t = t2;
			closestSphere = &sphere;
		}
	}
	if (closestSphere == NULL) {
		return Color(255, 255, 255);
	}

	hit.point = ray.origin + ray.direction * closest_t;
	return closestSphere->color;
}