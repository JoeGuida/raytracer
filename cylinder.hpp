#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP

#define GLM_ENABLE_EXPERIMENTAL
#define E_PI 3.1415926f

#include "glm/vec3.hpp"
#include "glm/gtx/rotate_vector.hpp"

#include "hit.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Cylinder : Shape {
	glm::vec3 position;
	float radius;
	float height;
	BRDFMaterial material;

	Cylinder(const glm::vec3& position, float radius, float height, const BRDFMaterial& material) : position(position), radius(radius), height(height), material(material) {}
	bool intersects(const Ray& ray, Hit& hit) const override;
};

struct GL_Cylinder {
	glm::vec3 position;
	float radius;
	float height;
	int segments;
	BRDFMaterial material;
	std::vector<glm::vec3> vertices;
	std::vector<uint32_t> indices;

	GL_Cylinder(const glm::vec3& position, float radius, float height, int segments, const BRDFMaterial& material) : 
		position(position), radius(radius), height(height), segments(segments), material(material) 
	{
		glm::vec3 bottom_center = position - glm::vec3(0.0f, (height / 2.0f), 0.0f);
		vertices.push_back(bottom_center);
		indices.push_back(0);

		glm::vec3 a = bottom_center + glm::vec3(radius, 0.0f, 0.0f);
		for (int i = 0; i < segments; i++) {
			vertices.push_back(a);
			a = glm::rotate(a, 15.0f, glm::vec3(0.0f, 1.0f, 0.0f));
			indices.push_back(i + 1);
		}

		glm::vec3 top_center = position + glm::vec3(0.0f, (height / 2.0f), 0.0f);

	}

};

#endif