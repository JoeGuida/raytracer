#ifndef RAYTRACER_RENDERER_HPP
#define RAYTRACER_RENDERER_HPP

#include "glm/vec3.hpp"

#include "rendermode.hpp"
#include "scene.hpp"

#include <fstream>

constexpr float RGB_MAX = 255.99f;

class Renderer {
private:
	static int screen_width;
	static int screen_height;
	static float aspect_ratio;
	static float max_distance;
	static glm::vec3 background_color;
	static RenderMode render_mode;

public:
	static void initialize(int width, int height, const glm::vec3 background_color, const RenderMode& mode);
	static glm::vec3 trace_ray(const Ray& ray, const Scene& scene);
	static void raytrace_image(std::ofstream& file, const Scene& scene);
	static float calculate_blinn_phong(Hit& hit, const Scene& scene);
	static float calculate_diffuse(const glm::vec3& normal, const glm::vec3 light_direction);
	static float calculate_specular(const glm::vec3& light_direction, const glm::vec3 camera_position, const Hit& hit);
};


#endif