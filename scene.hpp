#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "camera.hpp"
#include "hit.hpp"
#include "ray.hpp"
#include "shape.hpp"

#include <vector>

class Scene {
	float width;
	float height;
	Camera camera;
	std::vector<const Shape*> objects;
	std::vector<const Shape*> light_emitting_objects;

	Scene(float width, float height, const Camera& camera) : width(width), height(height), camera(camera) {}
	void add(const Shape& shape);
	Hit trace_ray(const Ray& ray);
};

#endif