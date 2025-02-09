#include "filesystem.hpp"
#include "renderer.hpp"
#include "scene.hpp"

int main() {
	Scene scene;
	Scene::load_from_file(FileSystem::get_path("/scenes/test.scene"), scene);
	Renderer::initialize(scene.width, scene.height, scene.background_color, RenderMode::NORMAL);
	std::ofstream file(FileSystem::get_path("/img/normal.ppm"));
	Renderer::raytrace_image(file, scene);
	return 0;
}