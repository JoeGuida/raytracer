#include "../headers/scene.h"
#include <iostream>

long Scene::rays_casted = 0;

Color Scene::trace_ray(const Ray& ray, RaycastHit& hit, float tmin, float tmax, int recursion_depth) {
	rays_casted++;

	const float t = get_closest_intersection(ray, hit, tmin, tmax);
	const float reflectivity = hit.material.reflectivity;

	if (hit.is_null())
		return options.background_color;

	Color color = float_to_rgb_color(hit.material.color * compute_lighting(hit, ray));

	if (recursion_depth <= 0 || reflectivity <= 0)
		return color;

	const Ray reflection_ray(ray.direction, hit.normal);
	const Color reflected_color = trace_ray(reflection_ray, hit, tmin, tmax, --recursion_depth);
	return lerp(color, reflected_color, reflectivity);
}

bool Scene::intersects_object(const Ray& ray, float tmin, float tmax) {
	float t1 = 0, t2 = 0;
	const Sphere* closest_sphere = nullptr;

	// Check last hit shadow sphere first
	if (hit.object != nullptr) {
		hit.object->raycast(ray, &t1, &t2);
		if ((t1 > tmin && t1 < tmax && t1) || (t2 > tmin && t2 < tmax)) {
			return true;
		}
	}

	// Check the other spheres
	for (const Sphere& sphere : spheres) {
		if (&sphere == hit.object)
			continue;

		sphere.raycast(ray, &t1, &t2);
		if (t1 > tmin && t1 < tmax && t1) {
			hit.object = &sphere;
			return true;
		}
		if (t2 > tmin && t2 < tmax && t2) {
			hit.object = &sphere;
			return true;
		}
	}

	hit.object = nullptr;
	return false;
}

float Scene::get_closest_intersection(const Ray& ray, RaycastHit& hit, float tmin, float tmax) const {
	float closest_t = INFINITY;
	float t1 = 0, t2 = 0;
	const Sphere* closest_sphere = nullptr;

	for (const Sphere& sphere : spheres) {
		sphere.raycast(ray, &t1, &t2);

		if (t1 > tmin && t1 < tmax && t1 < closest_t) {
			closest_t = t1;
			closest_sphere = &sphere;
		}
		if (t2 > tmin && t2 < tmax && t2 < closest_t) {
			closest_t = t2;
			closest_sphere = &sphere;
		}
	}

	if (closest_sphere == nullptr)
		return -1;

	hit.point = ray.origin + ray.direction * closest_t;
	hit.normal = closest_sphere->get_normal(hit.point);
	hit.material = closest_sphere->material;

	return closest_t;
}

float Scene::compute_lighting(RaycastHit& hit, const Ray& ray) {
	float lighting_value = 0;
	float tmax = 0;
	Vector3 light_direction;

	for (const Light& light : lights) {
		if (light.type == AMBIENT)
			lighting_value += light.intensity;
		else {
			if (light.type == DIRECTIONAL) {
				light_direction = normalized_vector(light.direction);
				tmax = INFINITY;
			}
			if (light.type == POINT) {
				light_direction = normalized_vector(light.position - hit.point);
				tmax = magnitude(light.position - hit.point);
			}

			// Compute lighting if point is not in shadow
			Ray shadow_ray(hit.point, -light_direction);
			if (!intersects_object(shadow_ray, shadow_bias, tmax)) {
				lighting_value += light.intensity * compute_diffuse_lighting(light_direction, hit);
				lighting_value += light.intensity * compute_specular_lighting(light_direction, ray.direction, hit);
			}
		}
	}

	return  std::min(lighting_value, 1.0f);
}

float Scene::compute_diffuse_lighting(const Vector3& light_direction, const RaycastHit& hit) const {
	float diffuse = 0;

	if(dot_product(hit.normal, light_direction) > 0)
		diffuse = cos(angle(hit.normal, light_direction));

	return std::max(0.0f, diffuse);
}

float Scene::compute_specular_lighting(const Vector3& light_direction, const Vector3& view_direction, const RaycastHit& hit) const {
	float specular = 0;
	const Vector3 r = hit.normal * 2 * dot_product(light_direction, hit.normal) - light_direction;
	
	if(dot_product(r, view_direction) > 0)
		specular = pow(cos(angle(r, view_direction)), hit.material.specularity);

	return std::max(0.0f, specular);
}

void Scene::ray_trace_ppm_image(std::string filename) {
	int subdivisions = options.sampling_amount;
	float quarter_pixel_width = float(viewport.width) / float(canvas.width) / 4;

	image.open(filename + ".ppm");
	image << "P3\n" << canvas.width << ' ' << canvas.height << "\n255\n";
	for (int y = canvas.height / 2; y > -canvas.height / 2; y--) {
		for (int x = -canvas.width / 2; x < canvas.width / 2; x++) {
			Color color;
			RaycastHit hit;
			const Vector3 direction = canvas_to_viewport(canvas, viewport, x, y, 1) * camera.rotation;

			// Default
			if (options.sampling == 0) 
				color = float_to_rgb_color(trace_ray(Ray(camera.position, direction), hit, 0, INFINITY, options.recursion_depth));

			// Subsampling
			if (options.sampling == 1)
				color = float_to_rgb_color(trace_ray(Ray(camera.position, direction), hit, 0, INFINITY, options.recursion_depth));
				
			// Supersampling
			if (options.sampling == 2) {
				std::vector<Vector3> pixels(1, direction);
				color = supersample_pixels(pixels, subdivisions, quarter_pixel_width);
				color = float_to_rgb_color(color / pow(4, subdivisions));
			}

			put_pixel(x, y, color, image);
		}
	}
}

Vector3 compute_transparency_vector(const Ray& view_ray, const RaycastHit& hit, float refraction_index) {
	Vector3 transparency_vector;

	float theta = angle(view_ray.direction, hit.normal);
	Vector3 b = (view_ray.direction + hit.normal * cos(theta)) / sin(theta);

	float transparency = view_ray.refraction_index / hit.material.refraction_index;
}

// Recursively subdivides pixel and traces a ray for each subdivision (rays_casted = subdivisions ^ 4)
Color Scene::supersample_pixels(const std::vector<Vector3>& pixels, int subdivisions, float offset) {
	Color color;

	if (subdivisions <= 0) {
		for (const Vector3& direction : pixels) {
			RaycastHit hit;
			color += trace_ray(Ray(camera.position, direction), hit, 0, INFINITY, options.recursion_depth);
		}
		return color;
	}

	std::vector<Vector3> next_subdivision_pixels;
	for (const Vector3& direction : pixels) {
		next_subdivision_pixels.push_back(Vector3(direction.x - offset, direction.y - offset, direction.z));
		next_subdivision_pixels.push_back(Vector3(direction.x + offset, direction.y - offset, direction.z));
		next_subdivision_pixels.push_back(Vector3(direction.x - offset, direction.y + offset, direction.z));
		next_subdivision_pixels.push_back(Vector3(direction.x + offset, direction.y + offset, direction.z));
	}

	return supersample_pixels(next_subdivision_pixels, --subdivisions, offset / 2);
}