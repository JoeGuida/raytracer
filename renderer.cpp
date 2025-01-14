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