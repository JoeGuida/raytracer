#ifndef RAYTRACER_CYLINDER_HPP
#define RAYTRACER_CYLINDER_HPP
#define GLM_ENABLE_EXPERIMENTAL

#define PI 3.14159265358979323846

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
	std::vector<float> vertices;
	std::vector<uint32_t> indices;

	GL_Cylinder(const glm::vec3& position, float radius, float height, int segments, const BRDFMaterial& material) : 
		position(position), radius(radius), height(height), segments(segments), material(material) 
	{
		glm::vec3 bottom_center = position - glm::vec3(0.0f, (height / 2.0f), 0.0f);
		glm::vec3 top_center = position + glm::vec3(0.0f, (height / 2.0f), 0.0f);
		float angle = static_cast<float>(2 * PI / segments);

		for (int i = 0; i < segments + 1; i++) {
			glm::vec3 v = glm::rotate(bottom_center + glm::vec3(radius, 0.0f, 0.0f), angle * i, glm::vec3(0.0, 1.0f, 0.0f));
			vertices.push_back(v.x);
			vertices.push_back(v.y);
			vertices.push_back(v.z);
		}

		for (int i = 1; i < vertices.size() / 3 - 1; i++) {
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
	}

};

#endif