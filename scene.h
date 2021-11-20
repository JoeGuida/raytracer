#ifndef _SCENE_H_
#define _SCENE_H_

#include <list>
#include <fstream>
#include "sphere.h"
#include "camera.h"

class Scene {
private: 
	std::list<Sphere> spheres;
	Camera camera;

public:
	Vector2 windowSize;

	Scene() {
		windowSize = Vector2(256, 256);
	}

	Scene(Vector2 size) {
		windowSize = size;
	}

	Scene(Vector2 size, Camera c) {
		windowSize = size;
		camera = c;
	}

	void Add(const Sphere& sphere) {
		spheres.emplace_back(sphere);
	}

	void RayTrace();
	Color Trace(int i, int j);
};

#endif