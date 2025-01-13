#include "scene.hpp"

void Scene::add(const Shape& shape) {
	objects.push_back(&shape);
	if (shape.get_material()->is_light()) {
		light_emitting_objects.push_back(&shape);
	}
}

Hit Scene::trace_ray(const Ray& ray) {
	float closest_t = INFINITY;
	const Shape* closest_object = nullptr;
	Hit hit;
	for (const Shape* shape : objects) {
		if (shape->intersects(ray, hit)) {
			if (hit.t < closest_t) {
				closest_t = hit.t;
				closest_object = shape;
			}
		}
	}

	return hit;
}