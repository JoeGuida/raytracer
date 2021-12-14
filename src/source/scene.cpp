#include "../headers/scene.h"
#include <iostream>

// Determines if the ray hits any object in the scene
// gets the point of the closest object hit
// computes the lighting at the point and returns the color
Color Scene::TraceRay(const Ray& ray, Hit& hit, float tmin, float tmax) {
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
	hit.normal = Normalized(hit.point - closestSphere->center);
	hit.material = closestSphere->material;

	Color result = closestSphere->material.color * ComputeLighting(hit, ray);
	return Color(int(result.r), int(result.g), int(result.b));
}

// Computes the lighting at a hit point
// for each type of lighting and returns the value (0-1.0f)
// lighting equation is ambient + sum(diffuse + specular)
float Scene::ComputeLighting(const Hit& hit, const Ray& ray) {
	float i = 0;

	for (const Light& light : lights) {
		if (light.type == AMBIENT)
			i += light.intensity;

		float diffuse = Diffuse(light, hit);
		float specular = Specular(light, hit, -ray.direction, hit.material.specular);
		i += (diffuse + specular);
	}

	return std::min(i, 1.0f);
}

// Computes the diffuse lighting at a hit point for each light in the scene
// for each light type except ambient, light vector (l) is used
// the dot product between l and the hit normal determines if the light ray
// hit the point, if so, add the light intensity * the angle between l and hit normal
float Scene::Diffuse(const Light& light, const Hit& hit) {
	float diffuse = 0;
	Vector3 l;

	if (light.type == DIRECTIONAL) 
		l = Normalized(light.direction);
	else if (light.type == POINT) 
		l = Normalized(light.position - hit.point);

	float nDotl = Dot(hit.normal, -l);
	if (nDotl > 0) {
		diffuse += light.intensity * Angle(hit.normal, -l);
	}

	return diffuse;
}

// Computes the specular lighting at the hit point for each light in the scene
// since ambient lights have no direction, they provide no specular lighting
// light vector is used for other light types, s exponent is used to narrow the calculation
// making the object appear glossier. 

// The diffuse value of the point is multiplied with the reflection vector of the light vector
// to determine the value
float Scene::Specular(const Light& light, const Hit& hit, const Vector3& v, float s) {
	float specular = 0;
	Vector3 l;
	
	if (light.type == DIRECTIONAL)
		l = Normalized(light.direction);
	else if (light.type == POINT)
		l = Normalized(light.position - hit.point);
	else
		return 0;

	Vector3 r = Reflect(l, hit.normal);
	float rDotV = Dot(r, v);
	if(rDotV > 0)
		specular = powf(cos(Angle(r, v)), s);
	
	return specular;
}
