#define GLM_ENABLE_EXPERIMENTAL

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "glm/gtx/projection.hpp"

#include "camera.hpp"
#include "cylinder.hpp"
#include "rectangle.hpp"
#include "renderer.hpp"
#include "scene.hpp"
#include "sphere.hpp"

#include <fstream>
#include <iostream>
#include <vector>

constexpr int SCREEN_WIDTH = 400;
constexpr int SCREEN_HEIGHT = 400;
constexpr glm::vec3 BACKGROUND_COLOR(0.1f);

int main() {
	Renderer::initialize(SCREEN_WIDTH, SCREEN_HEIGHT, BACKGROUND_COLOR, RenderMode::NORMAL);
	Camera camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	Scene scene(camera);

	Cylinder cylinder(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f, 1.0f, Material(glm::vec3(1.0f, 0.0f, 0.0f)));

	std::ofstream file("image.ppm");
	Renderer::raytrace_image(file, scene);

	return 0;
}