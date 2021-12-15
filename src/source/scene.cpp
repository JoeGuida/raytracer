#include "../headers/scene.h"
#include <iostream>

// Determines if the ray hits any object in the scene
// gets the point of the closest object hit
// computes the lighting at the point and returns the color
// depth determines how many times the light can bounce to calculate reflections/shadows
Color Scene::trace_ray(const Ray& ray, Hit& hit, float tmin, float tmax, int depth) {
	float closestT = INFINITY;
	Sphere* closestSphere = NULL;

	// Find the closest sphere that intersects the ray and the t value
	for (Sphere& sphere : spheres) {
		float t1, t2 = 0;
		sphere.intersects(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closestT) {
			closestT = t1;
			closestSphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closestT) {
			closestT = t2;
			closestSphere = &sphere;
		}
	}

	if (closestSphere == NULL) {
		return BACKGROUND_COLOR;
	}

	hit.point = ray.origin + ray.direction * closestT;
	hit.normal = normalized_vector(hit.point - closestSphere->center);
	hit.material = closestSphere->material;

	Color c = compute_lighting(hit, ray, depth);
	return Color(int(c.r), int(c.g), int(c.b));
}

Color Scene::compute_lighting(const Hit& hit, const Ray& ray, int depth) {
	float i = 0;
	float diffuse = 0;
	float specular = 0;
	Color color;

	// Compute diffuse & specular lighting for point
	for (const Light& light : lights) {
		if (light.type == AMBIENT) {
			i += light.intensity;
		}
		else {
			diffuse = compute_diffuse_lighting(light, hit);
			specular = compute_specular_lighting(light, hit, -ray.direction, hit.material.specularity);
			if (depth > 0)
				;// color = compute_reflection_color(light, hit, depth);
			else
				color = hit.material.color;
		}
		i += (diffuse + specular);
	}

	i = std::min(i, 1.0f);
	return hit.material.color * i;
}

float Scene::compute_diffuse_lighting(const Light& light, const Hit& hit) {
	float diffuse = 0;
	Vector3 l;

	if (light.type == DIRECTIONAL) 
		l = normalized_vector(light.direction);
	else if (light.type == POINT) 
		l = normalized_vector(light.position - hit.point);

	// Diffuse is determined by the angle between the hit normal and the light direction
	float nDotl = dot_product(hit.normal, -l);
	if (nDotl > 0) {
		diffuse += light.intensity * angle(hit.normal, -l);
	}

	return diffuse;
}

float Scene::compute_specular_lighting(const Light& light, const Hit& hit, const Vector3& v, float s) {
	float specular = 0;
	Vector3 l;
	
	if (light.type == DIRECTIONAL)
		l = normalized_vector(light.direction);
	else if (light.type == POINT)
		l = normalized_vector(light.position - hit.point);
	else
		return 0;

	Vector3 r = reflection(l, hit.normal);
	float rDotV = dot_product(r, v);
	if(rDotV > 0)
		specular = powf(cos(angle(r, v)), s);
	
	return specular;
}

Color Scene::compute_reflection_color(const Light& light, const Hit& hit, int depth) {
	return Color();
}