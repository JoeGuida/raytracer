#ifndef RAYTRACER_RENDERER_HPP
#define RAYTRACER_RENDERER_HPP

#include <glad/glad.h>
#include <glm/vec3.hpp>

#include <array>

#include "rectangle.hpp"
#include "shader.hpp"
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
};

#endif