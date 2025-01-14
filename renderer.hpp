#ifndef RAYTRACER_RENDERER_HPP
#define RAYTRACER_RENDERER_HPP

#include <glad/glad.h>
#include <glm/vec3.hpp>

#include <array>

#include "octahedron.hpp"
#include "rng.hpp"
#include "rectangle.hpp"
#include "shader.hpp"
#include "sphere.hpp"
#include "transform.hpp"
#include "triangle.hpp"

class Renderer {
private:
    static uint32_t VAO;
    static uint32_t VBO;
    static uint32_t EBO;

public:
    static void initialize();
    static void draw(const GL_Rectangle& rectangle, Shader& shader);
    static void draw(const GL_Triangle& triangle, Shader& shader);
    static void draw(const std::vector<GL_Triangle>& triangles, Shader& shader);
    static void draw(const GL_Sphere& sphere, Shader& shader);
    static void subdivide_triangle(const GL_Triangle& triangle, const BRDFMaterial& material, int depth, std::vector<GL_Triangle>& tris);
};

#endif