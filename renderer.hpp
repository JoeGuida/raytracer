#ifndef RAYTRACER_RENDERER_HPP
#define RAYTRACER_RENDERER_HPP

#include <array>

#include <glad/glad.h>
#include <glm/vec3.hpp>

#include "cylinder.hpp"
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
    static void draw(const GL_Cylinder& cylinder, Shader& shader);
    static void draw(const GL_Rectangle& rectangle, Shader& shader);
    static void draw(const GL_Triangle& triangle, Shader& shader);
    static void draw(const GL_Sphere& sphere, Shader& shader);
};

#endif