#ifndef RAYTRACER_TRIANGLE_HPP
#define RAYTRACER_TRIANGLE_HPP

#include "glm/vec3.hpp"

#include "bounding_box.hpp"
#include "shape.hpp"

struct Triangle : public Shape {
	glm::vec3 v0;
	glm::vec3 v1;
	glm::vec3 v2;
	glm::vec3 position;
	Material material;
	BoundingBox* bounding_box;

	Triangle(const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& position, const Material& material) : 
		v0(v0), v1(v1), v2(v2), position(position), material(material) 
	{
		float min_x = std::min(std::min(v0.x, v1.x), v2.x);
		float min_y = std::min(std::min(v0.y, v1.y), v2.y);
		float min_z = std::min(std::min(v0.z, v1.z), v2.z);
		float max_x = std::max(std::max(v0.x, v1.x), v2.x);
		float max_y = std::max(std::max(v0.y, v1.y), v2.y);
		float max_z = std::max(std::max(v0.z, v1.z), v2.z);
		bounding_box = new BoundingBox(
			glm::vec3(min_x, min_y, max_z), 
			glm::vec3(max_x, max_y, min_z));
	}
	Triangle(const Triangle&) = default;
	Triangle(Triangle&&) = default;
	virtual ~Triangle() = default;

	bool intersects(const Ray& ray, Hit& hit) const override;
	Material get_material() const override { return material; };
	glm::vec3 get_pos() const override { return position; };
	BoundingBox* aabb() const override { return bounding_box; }
};

#endif