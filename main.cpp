#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "camera.hpp"
#include "filesystem.hpp"
#include "renderer.hpp"
#include "shader.hpp"
#include "sphere.hpp"

#include <iostream>

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* initialize_window();
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void move_camera();
void process_input(GLFWwindow* window);


constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr double ASPECT_RATIO = SCREEN_WIDTH / static_cast<float>(SCREEN_HEIGHT);

bool mouse_button_pressed = false;
double lastX = SCREEN_WIDTH / 2.0;
double lastY = SCREEN_HEIGHT / 2.0;
glm::vec2 cursor_delta(0.0f);

Camera camera(
    glm::vec3(0.0f, 0.0f, -1.0f),
    glm::vec3(0.0f, 1.0f, 0.0f),
    glm::radians(90.0f),
    Transform(glm::vec3(0.0f, 0.0f, 3.0f))
);
constexpr float CAMERA_MOVEMENT_VELOCITY = 3.0f;
constexpr float CAMERA_ROTATION_VELOCITY = 100.0f;

bool wireframe = false;
bool move_forward = false;
bool move_back = false;
bool move_left = false;
bool move_right = false;

float delta_time = 0.0f;
float last_frame_time = 0.0f;
float current_frame_time = 0.0f;

int main() {
    GLFWwindow* window = initialize_window();
    Renderer::initialize();

    Shader default_shader(
        FileSystem::get_path("/default.vert"),
        FileSystem::get_path("/default.frag"));

    BRDFMaterial red_material(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f), 0.0f);
    GL_Sphere sphere(
        glm::vec3(0.0f),
        1.0f,
        3,
        red_material
    );

    glm::mat4 view;
    glm::mat4 projection = glm::perspective(static_cast<double>(camera.fov_radians), ASPECT_RATIO, 0.01, 100.0);
    default_shader.set_uniform("projection", projection);
    while (!glfwWindowShouldClose(window)) {
        process_input(window);

        current_frame_time = glfwGetTime();
        delta_time = current_frame_time - last_frame_time;
        last_frame_time = current_frame_time;

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        move_camera();
        view = glm::lookAt(
            camera.transform.position,
            camera.transform.position + camera.front, glm::vec3(0.0f, 1.0f, 0.0f));
        default_shader.set_uniform("view", view);

        Renderer::draw(sphere, default_shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    double x_diff = (xpos - lastX) / SCREEN_HEIGHT;
    double y_diff = (ypos - lastY) / SCREEN_WIDTH;
    x_diff = (fabs(x_diff) > 0.01f) ? x_diff : 0.0f;
    y_diff = (fabs(y_diff) > 0.01f) ? y_diff : 0.0f;

    cursor_delta = glm::vec2(x_diff, y_diff);

    lastX = xpos;
    lastY = ypos;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* initialize_window() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raytracer", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);

    return window;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        mouse_button_pressed = true;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        mouse_button_pressed = false;
    }
}

void move_camera() {
    if (mouse_button_pressed) {
        camera.rotate(cursor_delta * CAMERA_ROTATION_VELOCITY * -1.0f * delta_time);
    }
    if (move_forward) {
        camera.transform.position += camera.front * CAMERA_MOVEMENT_VELOCITY * delta_time;
    }
    if (move_back) {
        camera.transform.position -= camera.front * CAMERA_MOVEMENT_VELOCITY * delta_time;
    }
    if (move_left) {
        camera.transform.position -= camera.right * CAMERA_MOVEMENT_VELOCITY * delta_time;
    }
    if (move_right) {
        camera.transform.position += camera.right * CAMERA_MOVEMENT_VELOCITY * delta_time;
    }
}

void process_input(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        if (!wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            wireframe = true;
        }
        else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            wireframe = false;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        move_forward = true;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE) {
        move_forward = false;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        move_back = true;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE) {
        move_back = false;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        move_left = true;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE) {
        move_left = false;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        move_right = true;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE) {
        move_right = false;
    }
}