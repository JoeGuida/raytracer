#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "box.hpp"
#include "camera.hpp"
#include "cylinder.hpp"
#include "light.hpp"
#include "rendermode.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Scene {
private:
	std::vector<const Shape*> objects;
	std::vector<const Light*> lights;

public:
	int width;
	int height;
	float ambient;
	glm::vec3 background_color;
	Camera camera;

	Scene() {}
	Scene(int width, int height, float ambient, const glm::vec3& background_color, const Camera& camera) : 
		width(width), height(height), ambient(ambient), background_color(background_color), camera(camera) {}
	Scene(const Scene&) = default;
	Scene(Scene&&) = default;
	virtual ~Scene() = default;

	void add(const Camera& cam)   { camera = cam; }
	void add(const Camera&& cam)  { camera = cam; }
	void add(const Shape* shape)  { objects.push_back(shape); }
	void add(const Light* light)  { lights.push_back(light); }

	const std::vector<const Shape*> get_objects() const { return objects; }
	const std::vector<const Light*> get_lights()  const { return lights; }

	static void load_from_file(const std::string& filepath, Scene& scene);
};

#endif