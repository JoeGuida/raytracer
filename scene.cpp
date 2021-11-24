#include "scene.h"
#include <iostream>

Color Scene::TraceRay(const Ray& ray, Hit& hit, float tmin, float tmax) {
	float closest_t = INFINITY;
	Sphere* closestSphere = NULL;
	Color result = Color();
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

	// Point = RayOrigin + RayDirection * ClosestT
	// Normal = HitPoint - Sphere Center
	hit.point = ray.origin + ray.direction * closest_t;
	hit.normal = Normalized(hit.point - closestSphere->center);
	result = closestSphere->color;
	result = result * ComputeLighting(hit.point, hit.normal);

	return Color(int(result.r), int(result.g), int(result.b));
}

float Scene::ComputeLighting(const Point& point, const Vector3& normal) {
	float i = 0;

	for (const Light& light : lights) {
		if (light.type == AMBIENT) {
			i += light.intensity;
		}
		else {
			Vector3 L;
			if (light.type == DIRECTIONAL) {
				L = Normalized(light.direction);
			}
			else if (light.type == POINT) {
				L = Normalized(light.position - point);
			}

			float nDotl = Dot(normal, L);
			if (nDotl > 0) {
				i += light.intensity * nDotl / (Magnitude(normal) * Magnitude(L));
			}
		}
	}

	return std::min(i, 1.0f);
}


