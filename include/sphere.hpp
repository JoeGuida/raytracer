#ifndef RAYTRACER_SPHERE_HPP
#define RAYTRACER_SPHERE_HPP

#include "glm/vec3.hpp"

#include "bounding_box.hpp"
#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

struct Sphere : public Shape {
	glm::vec3 center;
	float radius;
	Material material;
	BoundingBox* bounding_box;

	Sphere(const glm::vec3& center, float radius, const Material& material) : 
		center(center), radius(radius), material(material) 
	{
		bounding_box = new BoundingBox(
			glm::vec3(center.x - radius, center.y - radius, center.z + radius),
			glm::vec3(center.x + radius, center.y + radius, center.z - radius));
	}

	Sphere(const Sphere&) = default;
	Sphere(Sphere&&) = default;
	virtual ~Sphere() = default;
	
	bool intersects(const Ray& ray, Hit& hit) const override;
	Material get_material() const override { return material; }
	glm::vec3 get_pos() const override { return center; }
	BoundingBox* aabb() const override { return bounding_box; }
};

#endif