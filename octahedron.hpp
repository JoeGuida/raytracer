#ifndef RAYTRACER_OCTAHEDRON_HPP
#define RAYTRACER_OCTAHEDRON_HPP

#include "glm/vec3.hpp"

#include "sphere.hpp"
#include "triangle.hpp"

#include <array>
#include <vector>

struct Octahedron {
public:
    std::vector<GL_Triangle> triangles;

    Octahedron(const GL_Sphere& sphere) {
        float r = sphere.radius;
        float r2 = sphere.radius * 0.7f;
        std::array<glm::vec3, 6> vertices{
            glm::vec3(0.0f, r2, -r2),
            glm::vec3(0.0f, r2, r2),
            glm::vec3(0.0f, -r2, r2),
            glm::vec3(0.0f, -r2, -r2),
            glm::vec3(-r, 0.0f, 0.0f),
            glm::vec3(r, 0.0f, 0.0f)
        };

        triangles = {
            GL_Triangle(sphere.position, vertices[0], vertices[1], vertices[4], sphere.material),
            GL_Triangle(sphere.position, vertices[1], vertices[2], vertices[4], sphere.material),
            GL_Triangle(sphere.position, vertices[2], vertices[3], vertices[4], sphere.material),
            GL_Triangle(sphere.position, vertices[0], vertices[3], vertices[4], sphere.material),
            GL_Triangle(sphere.position, vertices[0], vertices[1], vertices[5], sphere.material),
            GL_Triangle(sphere.position, vertices[1], vertices[2], vertices[5], sphere.material),
            GL_Triangle(sphere.position, vertices[2], vertices[3], vertices[5], sphere.material),
            GL_Triangle(sphere.position, vertices[0], vertices[3], vertices[5], sphere.material),
        };
    }
};

#endif