#include "../headers/scene.h"
#include <iostream>

float Scene::get_closest_intersection(const Ray& ray, Hit& hit, float tmin, float tmax) {
	float closest_t = INFINITY;
	Sphere* closest_sphere = NULL;

	// Find the closest sphere that intersects the ray and the t value
	for (Sphere& sphere : spheres) {
		float t1, t2 = 0;
		sphere.intersects(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closest_t) {
			closest_t = t1;
			closest_sphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closest_t) {
			closest_t = t2;
			closest_sphere = &sphere;
		}
	}

	if (closest_sphere == NULL)
		return -1;

	hit.point = ray.origin + ray.direction * closest_t;
	hit.normal = normalized_vector(hit.point - closest_sphere->center);
	hit.material = closest_sphere->material;

	return closest_t;
}

Color Scene::trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth) {
	Color color;

	float t = get_closest_intersection(ray, hit, tmin, tmax);
	if (t == -1)
		return BACKGROUND_COLOR;

	// Compute the lighting and return the color as int
	color = hit.material.color * compute_lighting(hit, ray);
	return Color(int(color.r), int(color.g), int(color.b));
}

float Scene::compute_lighting(Hit& hit, const Ray& ray) {
	float i = 0;
	float tmax = 0;
	Vector3 l;

	// Compute diffuse & specular lighting for point
	for (const Light& light : lights) {
		if (light.type == AMBIENT) {
			i += light.intensity;
		}
		else if (light.type == DIRECTIONAL) {
			l = normalized_vector(light.direction);
			tmax = INFINITY;
		}
		else if (light.type == POINT) {
			l = normalized_vector(light.position - hit.point);
			tmax = 1;
		}

		// Compute lighting if point is not in shadow
		Hit h;
		float t = get_closest_intersection(Ray(hit.point, -l), h, bias, tmax);
		if (t == -1) {
			i += compute_diffuse_lighting(light, hit);
			i += compute_specular_lighting(light, hit, ray.direction);
		}
	}

	i = std::min(i, 1.0f);
	return  i;
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
