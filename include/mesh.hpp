#ifndef RAYTRACER_MESH_HPP
#define RAYTRACER_MESH_HPP

#define GLM_ENABLE_EXPERIMENTAL

#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/vec3.hpp"

#include "material.hpp"
#include "shape.hpp"
#include "triangle.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

enum class ObjTag {
	VERTEX,
	FACE,
	GROUP_NAME,
	OBJECT_NAME,
	USEMTL,
	MTLLIB,
	NORMAL,
	TEXTURE_COORDINATE,
	SMOOTHING_GROUP,
	NULL_OBJ_TAG
};

const std::unordered_map<std::string, ObjTag> obj_tags{
	{"v", ObjTag::VERTEX},
	{"f", ObjTag::FACE},
	{"g", ObjTag::GROUP_NAME},
	{"o", ObjTag::OBJECT_NAME},
	{"usemtl", ObjTag::USEMTL},
	{"mtllib", ObjTag::MTLLIB},
	{"vn", ObjTag::NORMAL},
	{"vt", ObjTag::TEXTURE_COORDINATE},
	{"s", ObjTag::SMOOTHING_GROUP}
};

class Mesh : public Shape {
private:
	std::vector<glm::vec3> vertices;

public:
	std::vector<Shape*> triangles;
	glm::vec3 position;
	glm::vec3 scale;
	glm::quat rotation;
	Material material;
	BoundingBox* bounding_box;

	Mesh(const glm::vec3& position, const glm::vec3& scale, const glm::quat& rotation, const Material& material) :
		position(position), scale(scale), rotation(rotation), material(material) {}

	Mesh(const Mesh&) = default;
	Mesh(Mesh&&) = default;
	virtual ~Mesh() = default;

	void exectue_command(const ObjTag& tag, const std::vector<std::string>& args);
	void load_from_file(const std::string& filepath);

	bool intersects(const Ray& ray, Hit& hit) const override;
	Material get_material() const override { return material; };
	glm::vec3 get_pos() const override { return position; };
	BoundingBox* aabb() const { return bounding_box; }
};

#endif