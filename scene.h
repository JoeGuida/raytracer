#ifndef _SCENE_H_
#define _SCENE_H_

#include <list>
#include <fstream>
#include "object.h"
#include "camera.h"
#include "vector.h"

class Scene {
private: 
	std::list<Object> objects;
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

	void Add(const Object& shape) {
		objects.emplace_back(shape);
	}

	void Trace(int i, int j);
};

#endif