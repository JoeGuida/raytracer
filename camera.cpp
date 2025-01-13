#include "camera.hpp"

void Camera::rotate(const glm::vec2& delta) {
	transform.euler_angles.y += delta.x;
	transform.euler_angles.x += delta.y;
	front = glm::rotate(front, delta.x, glm::vec3(0.0f, 1.0f, 0.0f));
	front = glm::rotate(front, delta.y, glm::vec3(1.0f, 0.0f, 0.0f));
}