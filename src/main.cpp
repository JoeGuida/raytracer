#define GLM_ENABLE_EXPERIMENTAL

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "glm/gtx/projection.hpp"

#include "camera.hpp"
#include "rectangle.hpp"
#include "renderer.hpp"
#include "scene.hpp"
#include "sphere.hpp"

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

constexpr int SCREEN_WIDTH = 400;
constexpr int SCREEN_HEIGHT = 400;
constexpr glm::vec3 BACKGROUND_COLOR(0.1f);

int main() {
	Renderer::initialize(SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_COLOR, RenderMode::NORMAL);
	Camera camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	Scene scene(camera);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<float> x_dist(-1.0f, 2.0f);
	std::uniform_real_distribution<float> y_dist(-1.0f, 1.0f);
	std::uniform_real_distribution<float> z_dist(-10.0f, -1.0f);
	std::uniform_real_distribution<float> radius_dist(0.0f, 0.2f);
	std::uniform_real_distribution<float> color_dist(0.2f, 1.0f);

	for (int i = 0; i < 125; i++) {
		Sphere* sphere = new Sphere(glm::vec3(x_dist(rng), y_dist(rng), z_dist(rng)), radius_dist(rng), Material(glm::vec3(color_dist(rng), color_dist(rng), color_dist(rng))));
		//scene.add(sphere);
	}

	Rectangle* rectangle = new Rectangle(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.3f), Material(glm::vec3(1.0f, 0.0f, 0.0f)));
	scene.add(rectangle);

	std::ofstream file("image.ppm");
	Renderer::raytrace_image(file, scene);

	return 0;
}