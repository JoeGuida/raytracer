#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "glm/gtc/quaternion.hpp"
#include "glm/vec3.hpp"

constexpr glm::vec3 X_AXIS(1.0f, 0.0f, 0.0f);
constexpr glm::vec3 Y_AXIS(0.0f, 1.0f, 0.0f);
constexpr glm::vec3 Z_AXIS(0.0f, 0.0f, 1.0f);

struct Camera {
	glm::vec3 position;
	glm::quat rotation;
	float ry;

	Camera() : position(glm::vec3(0.0f)), ry(0.0f), rotation(glm::quat(0.0f, 0.0f, 0.0f, 0.0f)) {}
	Camera(const glm::vec3& position, float ry, const glm::quat& rotation) : position(position), ry(ry), rotation(rotation) {}
	Camera(const Camera&) = default;
	Camera(Camera&&) = default;
	virtual ~Camera() = default;

	Camera& operator=(const Camera& camera) {
		position = camera.position;
		ry = camera.ry;
		rotation = camera.rotation;
		return *this;
	}
};

#endif