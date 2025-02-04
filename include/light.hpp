#ifndef RAYTRACER_LIGHT_HPP
#define RAYTRACER_LIGHT_HPP

#include "glm/geometric.hpp"
#include "glm/vec3.hpp"

struct Light {
	virtual glm::vec3 get_direction(const glm::vec3& point) const = 0;
	virtual float get_intensity() const = 0;
};

struct AmbientLight {
	float intensity;

	AmbientLight(float intensity) : intensity(intensity) {}
	AmbientLight(const AmbientLight&) = default;
	AmbientLight(AmbientLight&&) = default;
	virtual ~AmbientLight() = default;
};

struct DirectionalLight : Light {
	glm::vec3 direction;
	float intensity;

	DirectionalLight(const glm::vec3& direction, float intensity) : direction(glm::normalize(direction)), intensity(intensity) {}
	DirectionalLight(const DirectionalLight&) = default;
	DirectionalLight(DirectionalLight&&) = default;
	virtual ~DirectionalLight() = default;

	glm::vec3 get_direction(const glm::vec3& point) const override { return -direction; }
	float get_intensity() const override { return intensity; }
};

struct PointLight : Light {
	glm::vec3 position;
	float intensity;

	PointLight(const glm::vec3& position, float intensity) : position(position), intensity(intensity) {}
	PointLight(const PointLight&) = default;
	PointLight(PointLight&&) = default;
	virtual ~PointLight() = default;

	glm::vec3 get_direction(const glm::vec3& point) const override { return position - point; }
	float get_intensity() const override { return intensity; }
};

#endif