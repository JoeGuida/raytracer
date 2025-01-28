#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"

struct Camera {
	glm::vec3 position;
	glm::vec3 front;

	Camera(const glm::vec3& position, const glm::vec3& front) : position(position), front(glm::normalize(front)) {}


};

#endif