#include "renderer.hpp"

int Renderer::screen_width = 0;
int Renderer::screen_height = 0;
float Renderer::aspect_ratio = 0.0f;
float Renderer::max_distance = 0.0f;
glm::vec3 Renderer::background_color = glm::vec3(0.1f, 0.1f, 0.1f);
RenderMode Renderer::render_mode = RenderMode::BASE_COLOR;

Hit Renderer::get_closest_object_hit(const std::vector<const Shape*>& objects, const Ray& ray, bool bounding_box) {
	float min_t = INFINITY;
	Hit min_hit;
	for (const Shape* object : objects) {
		Hit hit;
		if (bounding_box) {
			if (object->aabb()->intersects(ray, hit) && hit.t < min_t) {
				min_t = hit.t;
				min_hit = hit;
			}
		}
		else {
			if (object->intersects(ray, hit) && hit.t < min_t) {
				min_t = hit.t;
				min_hit = hit;
			}
		}
	}

	return min_hit;
}

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
	Hit hit = get_closest_object_hit(objects, ray, render_mode == RenderMode::BOUNDING_BOX);

	if(hit.t != INFINITY) {
		switch (render_mode) {
		case RenderMode::BASE_COLOR: {
			return hit.material->color;
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
			return glm::vec3(fabsf(hit.normal.x), fabsf(hit.normal.y), fabsf(hit.normal.z));
			break;
		};
		case RenderMode::BLINN_PHONG: {
			return calculate_blinn_phong(hit, scene) * hit.material->color;
			break;
		}
		}
	}

	return background_color;
}

void Renderer::raytrace_image(std::ofstream& file, const Scene& scene) {
	if (render_mode == RenderMode::DEPTH) {
		max_distance = get_max_distance(scene.camera.position, scene);
	}

	float rx = scene.camera.ry * aspect_ratio;
	glm::vec3 camera_x = rx * (scene.camera.rotation * X_AXIS);
	glm::vec3 camera_y = scene.camera.ry * (scene.camera.rotation * Y_AXIS);
	glm::vec3 camera_z = scene.camera.rotation * Z_AXIS;

	if (file.is_open()) {
		file << "P3\n" << screen_width << ' ' << screen_height << "\n255\n";
		for (int y = screen_height - 1; y >= 0; y--) {
			for (int x = 0; x < screen_width; x++) {
				float dx = 2 * (x + 0.5f) / static_cast<float>(screen_width) - 1;
				float dy = 2 * (y + 0.5f) / static_cast<float>(screen_height) - 1;
				glm::vec3 origin = scene.camera.position;
				glm::vec3 direction = dx * camera_x + dy * camera_y - camera_z;
				Ray ray(origin, direction);
				glm::vec3 color = Renderer::trace_ray(ray, scene);
				file << static_cast<int>(color.r * RGB_MAX) << ' ' << static_cast<int>(color.g * RGB_MAX) << ' ' << static_cast<int>(color.b * RGB_MAX) << '\n';
			}
		}
	}
	file.close();
}

float Renderer::calculate_blinn_phong(Hit& hit, const Scene& scene) {
	float ambient = scene.ambient;
	float diffuse = 0.0f;
	float specular = 0.0f;

	for (const Light* light : scene.get_lights()) {
		diffuse += calculate_diffuse(hit.normal, light->get_direction(hit.point)) * light->get_intensity();
		specular += calculate_specular(light->get_direction(hit.point), scene.camera.position, hit) * light->get_intensity();
	}

	float blinn_phong = ambient + diffuse + specular;
	return std::min(blinn_phong, 1.0f);
}

float Renderer::calculate_diffuse(const glm::vec3& normal, const glm::vec3 light_direction) {
	float diffuse = glm::dot(normal, light_direction);
	return std::max(diffuse, 0.0f);
}

float Renderer::calculate_specular(const glm::vec3& light_direction, const glm::vec3 camera_position, const Hit& hit) {
	glm::vec3 view_direction = camera_position - hit.point;
	glm::vec3 h = glm::normalize(light_direction + view_direction);
	float specular = std::powf(glm::dot(hit.normal, h), static_cast<float>(hit.material->specularity));
	return std::max(specular, 0.0f);
}


