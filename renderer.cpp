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
    auto vertices = rectangle.get_vertices();
    auto indices = rectangle.get_indices();

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