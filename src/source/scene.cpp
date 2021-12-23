#include "../headers/scene.h"
#include <iostream>

float Scene::get_closest_intersection(const Ray& ray, Hit& hit, float tmin, float tmax) {
	float closest_t = INFINITY;
	float sphere_t = INFINITY;
	float plane_t = INFINITY;
	Sphere* closest_sphere = nullptr;
	Plane* closest_plane = nullptr;

	// Determine if the ray intersects a sphere and get the closest t value if it does
	for (Sphere& sphere : spheres) {
		float t1, t2 = 0;
		sphere.intersects(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closest_t) {
			closest_t = t1;
			sphere_t = t1;
			closest_sphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closest_t) {
			closest_t = t2;
			sphere_t = t2;
			closest_sphere = &sphere;
		}
	}

	// Determine if the ray intersects a plane and get the t value if it does
	for (Plane& plane : planes) {
		float t = plane.raycast(ray);
		if (t > tmin && t < tmax && t < closest_t) {
			closest_t = t;
			plane_t = t;
			closest_plane = &plane;
		}
	}

	if (closest_sphere == nullptr && closest_plane == nullptr)
		return -1;

	// Determine which object is closest and set the hit properties
	hit.point = ray.origin + ray.direction * closest_t;
	if (closest_plane != nullptr) {
		hit.normal = closest_plane->get_normal(hit.point);
		hit.material = closest_plane->material;
	}
	if (closest_sphere != nullptr) {
		hit.normal = closest_sphere->get_normal(hit.point);
		hit.material = closest_sphere->material;
	}

	return closest_t;
}

Color Scene::trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth) {
	float t = get_closest_intersection(ray, hit, tmin, tmax);

	if (hit.is_null()) {
		return BACKGROUND_COLOR;
	}

	Color color = float_to_rgb_color(compute_lighting(hit, ray, depth));

	float reflectivity = hit.material.reflectivity;
	if (depth <= 0 || reflectivity <= 0)
		return color;

	Ray reflection_ray(ray.direction, hit.normal);
	Color reflected_color = trace_ray(reflection_ray, hit, tmin, tmax, --depth);
	return float_to_rgb_color(color * (1 - reflectivity) + reflected_color * reflectivity);
}

Color Scene::compute_lighting(Hit& hit, const Ray& ray, int depth) {
	float i = 0;
	float tmax = 0;
	Vector3 light_direction;
	Color color = hit.material.color;

	// Compute diffuse & specular lighting for point
	for (const Light& light : lights) {
		if (light.type == AMBIENT)
			i += light.intensity;
		else if (light.type == DIRECTIONAL) {
			light_direction = normalized_vector(light.direction);
			tmax = INFINITY;
		}
		else if (light.type == POINT) {
			light_direction = normalized_vector(light.position - hit.point);
			tmax = 1;
		}

		// Compute lighting if point is not in shadow
		Ray shadow_ray(hit.point, -light_direction);
		Hit shadow_hit;
		if (get_closest_intersection(shadow_ray, shadow_hit, bias, tmax) == -1) {
			i += compute_diffuse_lighting(light, hit);
			i += compute_specular_lighting(light, hit, ray.direction);
		}
	}

	return  color * std::min(i, 1.0f);
}

float Scene::compute_diffuse_lighting(const Light& light, const Hit& hit) {
	float diffuse = 0;
	Vector3 l;

	if (light.type == DIRECTIONAL) 
		l = normalized_vector(light.direction);
	else if (light.type == POINT) 
		l = normalized_vector(light.position - hit.point);

	// Diffuse is determined by the angle between the hit normal and the light direction
	if(dot_product(hit.normal, l) > 0)
		diffuse = light.intensity * std::max(0.0f, cos(angle(hit.normal, l)));

	return diffuse;
}

float Scene::compute_specular_lighting(const Light& light, const Hit& hit, const Vector3& v) {
	float specular = 0;
	Vector3 l;
	
	if (light.type == DIRECTIONAL)
		l = normalized_vector(light.direction);
	else if (light.type == POINT)
		l = normalized_vector(light.position - hit.point);

	Vector3 r = -l + hit.normal * 2 * dot_product(l, hit.normal);
	Vector3 highlight = (v + l) / (magnitude(v + l));
	if(dot_product(r, -v) > 0)
		specular = pow(std::max(0.0f, cos(angle(hit.normal, highlight))), hit.material.specularity);

	return std::max(0.0f, specular);
}

