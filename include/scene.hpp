#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "box.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "rendermode.hpp"
#include "shape.hpp"
#include "sphere.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Scene {
private:
	std::vector<const Shape*> objects;
	std::vector<const Light*> lights;

public:
	Camera camera;
	int width;
	int height;
	glm::vec3 background_color;
	float ambient;

	Scene() {}
	Scene(int width, int height, const glm::vec3& background_color, const Camera& camera) : 
		width(width), height(height), background_color(background_color), camera(camera), ambient(0.0f) {}
	Scene(const Scene&) = default;
	Scene(Scene&&) = default;
	virtual ~Scene() = default;

	void add(const Shape* shape) { 
		objects.push_back(shape); 
	}

	void add(const Light* light) {
		lights.push_back(light);
	}

	const std::vector<const Shape*> get_objects() const { 
		return objects; 
	}

	const std::vector<const Light*> get_lights() const {
		return lights;
	}

	static Scene load_from_file(const std::string& filepath, bool flip_y_and_z_axis = false, bool invert_y_axis = false, bool invert_z_axis = false);
};

#endif