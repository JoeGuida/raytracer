#ifndef RAYTRACER_RECTANGLE_HPP
#define RAYTRACER_RECTANGLE_HPP

#include "glm/vec3.hpp"

#include "material.hpp"
#include "shape.hpp"
#include "transform.hpp"

#include <array>

struct Rectangle : Shape {
	glm::vec3 position;
	glm::vec3 size;
	BRDFMaterial material;

	Rectangle(const glm::vec3& position, const glm::vec3& size, const BRDFMaterial& material) : position(position), size(size), material(material) {}
	bool intersects(const Ray& ray, Hit& hit) const override;
};

class GL_Rectangle {
private:
    glm::vec2 size;
    std::array<uint32_t, 6> indices;
    std::array<float, 12> vertices;

public:
    GL_Rectangle(float x,
        float y,
        const BRDFMaterial& material,
        const Transform& transform) :
        size(x, y),
        material(material),
        transform(transform)
    {
        vertices = {
            -size.x / 2.0f,  size.y / 2.0f, 0.0f,
             size.x / 2.0f,  size.y / 2.0f, 0.0f,
            -size.x / 2.0f, -size.y / 2.0f, 0.0f,
             size.x / 2.0f, -size.y / 2.0f, 0.0f
        };

        indices = { 0, 1, 3, 0, 2, 3 };
    }

    GL_Rectangle(float x, const BRDFMaterial& material, const Transform& transform) :
        size(x, x), material(material), transform(transform)
    {
        vertices = {
            -size.x / 2.0f,  size.y / 2.0f, 0.0f,
             size.x / 2.0f,  size.y / 2.0f, 0.0f,
            -size.x / 2.0f, -size.y / 2.0f, 0.0f,
             size.x / 2.0f, -size.y / 2.0f, 0.0f
        };

        indices = { 0, 1, 3, 0, 2, 3 };
    }

    GL_Rectangle(const GL_Rectangle&) = default;
    GL_Rectangle(GL_Rectangle&&) = default;
    virtual ~GL_Rectangle() = default;

    std::array<uint32_t, 6> get_indices() const { return indices; }
    std::array<float, 12> get_vertices() const { return vertices; }

    BRDFMaterial material;
    Transform transform;
};

#endif