#include "renderer.hpp"

uint32_t Renderer::VAO;
uint32_t Renderer::VBO;
uint32_t Renderer::EBO;

void Renderer::initialize() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
}

void Renderer::draw(const GL_Rectangle& rectangle, Shader& shader) {
    std::array<float, 12> vertices = rectangle.get_vertices();
    std::array<uint32_t, 6> indices = rectangle.get_indices();

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glm::mat4 model(1.0f);
    const Transform* tf = &rectangle.transform;
    model = glm::translate(model, tf->position);
    model = glm::rotate(model, tf->euler_angles.z, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, tf->scale);
    shader.set_uniform("model", model);
    shader.set_uniform("color", rectangle.material.diffuse);

    glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
}

void Renderer::draw(const GL_Triangle& triangle, Shader& shader) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, triangle.vertices.size() * sizeof(float), triangle.vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, triangle.position);
    shader.set_uniform("model", model);
    shader.set_uniform("color", triangle.material.diffuse);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::draw(const std::vector<GL_Triangle>& triangles, Shader& shader) {
    std::vector<glm::vec3> data;
    for (const GL_Triangle& triangle : triangles) {
        data.push_back(triangle.a);
        data.push_back(triangle.b);
        data.push_back(triangle.c);
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glm::mat4 model(1.0f);
    model = glm::translate(model, triangles[0].position);
    shader.set_uniform("model", model);
    shader.set_uniform("color", triangles[0].material.diffuse);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, triangles.size());
}

void Renderer::draw(const GL_Sphere& sphere, Shader& shader) {
    Octahedron octahedron(sphere);
    std::vector<GL_Triangle> triangles;
    for (const GL_Triangle& triangle : octahedron.triangles) {
        subdivide_triangle(triangle, sphere.material, sphere.depth, triangles);
    }
    
    for (const GL_Triangle& triangle: triangles) {
        draw(triangle, shader);
    }
}

void Renderer::subdivide_triangle(const GL_Triangle& triangle, const BRDFMaterial& material, int depth, std::vector<GL_Triangle>& tris) {
    if (depth == 0) {
        tris.push_back(triangle);
        return;
    }

    glm::vec3 ab = glm::normalize((triangle.a + triangle.b) / 2.0f);
    glm::vec3 bc = glm::normalize((triangle.b + triangle.c) / 2.0f);
    glm::vec3 ac = glm::normalize((triangle.a + triangle.c) / 2.0f);

    std::array<GL_Triangle, 4> triangles{
        GL_Triangle(triangle.position, triangle.b, ab, bc, material),
        GL_Triangle(triangle.position, ab, triangle.a, ac, material),
        GL_Triangle(triangle.position, bc, ac, triangle.c, material),
        GL_Triangle(triangle.position, ab, bc, ac, material)
    };

     for (const GL_Triangle& tri : triangles) {
        subdivide_triangle(tri, material, depth - 1, tris);
    }
}