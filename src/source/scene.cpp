#include "../headers/scene.h"
#include <iostream>

bool Scene::get_closest_intersection(const Ray& ray, Hit& hit, float tmin, float tmax) {
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
		return false;

	hit.point = ray.origin + ray.direction * closest_t;
	hit.normal = normalized_vector(hit.point - closest_sphere->center);
	hit.material = closest_sphere->material;

	return true;
}

// Determines if the ray hits any object in the scene
// gets the point of the closest object hit
// computes the lighting at the point and returns the color
// depth determines how many times the light can bounce to calculate reflections/shadows
Color Scene::trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth) {
	Color color;

	if (!get_closest_intersection(ray, hit, tmin, tmax))
		return BACKGROUND_COLOR;

	// Compute the lighting and return the color as int
	float lighting_value = compute_lighting(hit, ray);
	color = hit.material.color * lighting_value;

	if (depth <= 0 || hit.material.reflectivity <= 0)
		return Color(int(color.r), int(color.g), int(color.b));
	else
		return Color(int(color.r), int(color.g), int(color.b));
}

float Scene::compute_lighting(const Hit& hit, const Ray& ray) {
	float i = 0;
	float diffuse = 0;
	float specular = 0;
	float tmax = 0;
	Vector3 l;

	// Compute diffuse & specular lighting for point
	for (const Light& light : lights) {
		if (light.type == AMBIENT) {
			i += light.intensity;
		}
		else if (light.type == DIRECTIONAL) {
			l = normalized_vector(-light.direction);
			tmax = INFINITY;
		}
		else if (light.type == POINT) {
			l = normalized_vector(hit.point - light.position);
			tmax = 1;
		}

		// Shadow check
		Hit h;
		Ray shadow_ray(hit.point, l);
		bool in_shadow = get_closest_intersection(shadow_ray, h, 0.001f, tmax);
		if (!in_shadow) {
			i += compute_diffuse_lighting(light, hit);
			i += compute_specular_lighting(light, hit, -ray.direction, hit.material.specularity);
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
	float dot_n_l = dot_product(hit.normal, -l);
	if (dot_n_l > 0)
		diffuse = light.intensity * angle(hit.normal, -l);

	return diffuse;
}

float Scene::compute_specular_lighting(const Light& light, const Hit& hit, const Vector3& v, float s) {
	float specular = 0;
	Vector3 l;
	
	if (light.type == DIRECTIONAL)
		l = normalized_vector(light.direction);
	else if (light.type == POINT)
		l = normalized_vector(light.position - hit.point);

	Vector3 r = reflection(l, hit.normal);
	float dot_r_v = dot_product(r, v);
	if(dot_r_v > 0)
		specular = powf(cos(angle(r, v)), s);
	
	return specular;
}