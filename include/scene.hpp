#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include "camera.hpp"
#include "shape.hpp"

#include <vector>

class Scene {
private:
	std::vector<const Shape*> objects;

public:
	Camera camera;

	Scene(const Camera& camera) : camera(camera) {}

	void add(const Shape* shape) { 
		objects.push_back(shape); 
	}

	const std::vector<const Shape*> get_objects() const { 
		return objects; 
	}
};

#endif