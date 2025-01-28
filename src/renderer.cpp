#include "renderer.hpp"

int Renderer::screen_width = 0;
int Renderer::screen_height = 0;
float Renderer::aspect_ratio = 0.0f;
float Renderer::max_distance = 0.0f;
glm::vec3 Renderer::background_color = glm::vec3(0.1f, 0.1f, 0.1f);
RenderMode Renderer::render_mode = RenderMode::BASE_COLOR;

void Renderer::initialize(int width, int height, const glm::vec3 background_color, const RenderMode& mode) {
	screen_width = width;
	screen_height = height;
	aspect_ratio = static_cast<float>(screen_width) / static_cast<float>(screen_height);
	render_mode = mode;
}

float get_max_distance(const glm::vec3 point, const Scene& scene) {
	std::vector<const Shape*> objects = scene.get_objects();
	float max_distance = 0.0f;
	for (int i = 0; i < objects.size(); i++) {
		float distance = fabsf(glm::length(objects[i]->get_pos() - point));
		if (distance > max_distance) {
			max_distance = distance;
		}
	}

	return max_distance;
}

glm::vec3 Renderer::trace_ray(const Ray& ray, const Scene& scene) {
	std::vector<const Shape*> objects = scene.get_objects();
	for (int i = 0; i < objects.size(); i++) {
		Hit hit;
		if (objects[i]->intersects(ray, hit)) {
			switch (render_mode) {
			case RenderMode::BASE_COLOR: {
				return hit.material.color;
				break;
			};
			case RenderMode::DEPTH: {
				return glm::vec3(hit.t / max_distance, hit.t / max_distance, hit.t / max_distance);
				break;
			};
			case RenderMode::NORMAL: {
				return glm::vec3(fabsf(hit.normal.x), fabsf(hit.normal.y), fabsf(hit.normal.z));
				break;
			};
			case RenderMode::BOUNDING_BOX: {
				return hit.material.color;
				break;
			};
			}
		}
	}

	return background_color;
}

void Renderer::raytrace_image(std::ofstream& file, const Scene& scene) {
	if (render_mode == RenderMode::DEPTH) {
		max_distance = get_max_distance(scene.camera.position, scene);
	}

	float pixel_width = 1.0f * aspect_ratio / static_cast<float>(screen_width);
	float pixel_height = 1.0f / screen_height;

	if (file.is_open()) {
		file << "P3\n" << screen_width << ' ' << screen_height << "\n255\n";
		for (int y = 0; y < screen_height; y++) {
			for (int x = 0; x < screen_width; x++) {
				glm::vec3 offset(pixel_width * x, pixel_height * y, 0.0f);
				Ray ray(scene.camera.position, (scene.camera.front + offset) * 2.0f - 1.0f);
				glm::vec3 color = Renderer::trace_ray(ray, scene);
				file << static_cast<int>(color.r * RGB_MAX) << ' ' << static_cast<int>(color.g * RGB_MAX) << ' ' << static_cast<int>(color.b * RGB_MAX) << '\n';
			}
		}
	}
	file.close();
}


