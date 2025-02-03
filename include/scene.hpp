#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "box.hpp"
#include "camera.hpp"
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

public:
	Camera camera;
	int width;
	int height;
	glm::vec3 background_color;

	Scene() {}
	Scene(const Scene&) = default;
	Scene(Scene&&) = default;
	virtual ~Scene() = default;

	void add(const Shape* shape) { 
		objects.push_back(shape); 
	}

	const std::vector<const Shape*> get_objects() const { 
		return objects; 
	}

	static Scene load_from_file(const std::string& filepath, bool flip_y_and_z_axis = false, bool invert_z_axis = false);
};

#endif