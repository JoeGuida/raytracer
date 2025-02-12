#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/stopwatch.h"

#include "filesystem.hpp"
#include "renderer.hpp"
#include "scene.hpp"

int main() {
	try {
		auto logger = spdlog::basic_logger_mt("logger", "logs/log.txt");
		spdlog::set_default_logger(logger);
	}
	catch (spdlog::spdlog_ex& ex) {
		std::cout << "Logger initialization failed: " << ex.what() << std::endl;
	}
	spdlog::set_level(spdlog::level::debug);

	Scene scene;
	Scene::load_from_file(FileSystem::get_path("/scenes/test.scene"), scene);
	Renderer::initialize(scene.width, scene.height, scene.background_color, RenderMode::BASE_COLOR);
	std::ofstream file(FileSystem::get_path("/img/image.ppm"));
	spdlog::stopwatch stopwatch;
	Renderer::raytrace_image(file, scene);
	spdlog::debug("Elapsed Time: {}", stopwatch);
	
	return 0;
}
