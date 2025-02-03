#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"

struct Camera {
	float fov;
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 euler_rotation;

	Camera() : fov(0.0f), position(glm::vec3(0.0f)), front(glm::vec3(0.0f)), euler_rotation(glm::vec3(0.0f)) {}
	Camera(float fov, const glm::vec3& position, const glm::vec3& front, const glm::vec3& euler_rotation) : 
		fov(fov), position(position), front(glm::normalize(front)), euler_rotation(euler_rotation) {}
	Camera(const Camera&) = default;
	Camera(Camera&&) = default;
	virtual ~Camera() = default;

	Camera& operator=(const Camera& camera) {
		fov = camera.fov;
		position = camera.position;
		front = camera.front;
		euler_rotation = camera.euler_rotation;
		return *this;
	}
};

#endif