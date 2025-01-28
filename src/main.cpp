#define GLM_ENABLE_EXPERIMENTAL

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "glm/gtx/projection.hpp"

#include <array>
#include <fstream>
#include <iostream>

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr float ASPECT_RATIO = SCREEN_WIDTH / static_cast<float>(SCREEN_HEIGHT);

struct Hit {
	glm::vec3 point;

	Hit() {}
};

struct Sphere {
	glm::vec3 center;
	float radius;

	Sphere(const glm::vec3& center, float radius) : center(center), radius(radius) {}
};

struct Ray {
	glm::vec3 origin;
	glm::vec3 direction;

	Ray(const glm::vec3& origin, const glm::vec3& direction) : origin(origin), direction(glm::normalize(direction)) {}

	bool intersects(const Sphere& sphere, Hit& hit) {
		glm::vec3 a = sphere.center - origin;
		glm::vec3 b = glm::proj(a, direction);
		glm::vec3 c = a - b;
		float d = sqrtf((sphere.radius * sphere.radius) - glm::dot(c, c));

		if (d < 0) {
			return false;
		}

		return false;
	}
};

struct Camera {
	glm::vec3 position;
	glm::vec3 front;
	int width;
	int height;
	float aspect;

	Camera(const glm::vec3& position, const glm::vec3& front, int width, int height, float aspect) : position(position), front(glm::normalize(front)), width(width), height(height), aspect(aspect) {}

	glm::vec3 trace_ray(int x, int y, const std::array<Sphere, 1>& spheres) {
		float pixel_width = 1.0f * ASPECT_RATIO / width;
		float pixel_height = 1.0f / height;
		glm::vec3 offset(pixel_width * x, pixel_height * y, 0.0f);
		Ray ray(position, front + offset);

		for (int i = 0; i < spheres.size(); i++) {
			Hit hit;
			if (ray.intersects(spheres[i], hit)) {

			}
		}

		return glm::vec3(0.0f);
	}
};

int main() {
	Camera camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f), SCREEN_WIDTH, SCREEN_HEIGHT, ASPECT_RATIO);
	std::array<Sphere, 1> spheres{
		Sphere(glm::vec3(0.0f), 0.25f)
	};
	std::ifstream file("image.ppm");
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			glm::vec3 color = camera.trace_ray(x, y, spheres);
		}
	}

	return 0;
}