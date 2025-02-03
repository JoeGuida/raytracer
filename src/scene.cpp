#include "scene.hpp"

enum class SceneTag {
	WIDTH,
	HEIGHT,
	BACKGROUND,
	BOX,
	SPHERE,
	CAMERA,
	NULL_SCENE_TAG
};

void exectue_command(const SceneTag& tag, const std::vector<std::string>& args, Scene& scene, bool flip_y_and_z_axis, bool invert_z_axis) {
	switch (tag) {
	case SceneTag::WIDTH: {
		assert(args.size() == 1 + 1);
		scene.width = std::stoi(args[1]);
		break;
	}
	case SceneTag::HEIGHT: {
		assert(args.size() == 1 + 1);
		scene.height = std::stoi(args[1]);
		break;
	}
	case SceneTag::BACKGROUND: {
		assert(args.size() == 3 + 1);
		scene.background_color = glm::vec3(
			std::stof(args[1]),
			std::stof(args[2]),
			std::stof(args[3]));
		break;
	}
	case SceneTag::BOX: {
		assert(args.size() == 12 + 1);
		glm::vec3 size(std::stof(args[1]), std::stof(args[2]), std::stof(args[3]));
		glm::vec3 pos(std::stof(args[4]), std::stof(args[5]), std::stof(args[6]));

		if (flip_y_and_z_axis) {
			size = glm::vec3(size.x, size.z, size.y);
			pos = glm::vec3(pos.x, pos.z, pos.y);
		}

		if (invert_z_axis) {
			pos.z *= -1.0f;
		}
		
		glm::vec3 diffuse(std::stof(args[10]), std::stof(args[11]), std::stof(args[12]));
		Box* box = new Box(pos, size, Material(diffuse));
		scene.add(box);
		break;
	}
	case SceneTag::CAMERA: {
		assert(args.size() == 10 + 1);
		float fov = std::stof(args[1]);
		glm::vec3 pos(std::stof(args[2]), std::stof(args[3]), std::stof(args[4]));
		glm::vec3 target(std::stof(args[5]), std::stof(args[6]), std::stof(args[7]));
		glm::vec3 euler_rotation(std::stof(args[8]), std::stof(args[9]), std::stof(args[10]));
		
		if (flip_y_and_z_axis) {
			pos = glm::vec3(pos.x, pos.z, pos.y);
			target = glm::vec3(target.x, target.z, target.y);
			euler_rotation = glm::vec3(euler_rotation.x, euler_rotation.z, euler_rotation.y);
		}

		if (invert_z_axis) {
			pos.z *= -1.0f;
			target.z *= -1.0f;
			euler_rotation.z *= -1.0f;
		}
		
		Camera camera(fov, pos, target - pos, euler_rotation);
		scene.camera = camera;
		break;
	}
	case SceneTag::SPHERE: {
		assert(args.size() == 7 + 1);
		float radius = std::stof(args[1]);
		glm::vec3 center(std::stof(args[2]), std::stof(args[3]), std::stof(args[4]));
		glm::vec3 diffuse(std::stof(args[5]), std::stof(args[6]), std::stof(args[7]));

		if (flip_y_and_z_axis) {
			center = glm::vec3(center.x, center.z, center.y);
		}

		if (invert_z_axis) {
			center.z *= -1.0f;
		}

		Sphere* sphere = new Sphere(center, radius, Material(diffuse));
		scene.add(sphere);
		break;
	}
	default:
		break;
	}
}

SceneTag get_command(const std::string& value) {
	if (value == "w") {
		return SceneTag::WIDTH;
	}
	if (value == "h") {
		return SceneTag::HEIGHT;
	}
	if (value == "bg") {
		return SceneTag::BACKGROUND;
	}
	if (value == "box") {
		return SceneTag::BOX;
	}
	if (value == "sphere") {
		return SceneTag::SPHERE;
	}
	if (value == "camera") {
		return SceneTag::CAMERA;
	}

	return SceneTag::NULL_SCENE_TAG;
}

std::vector<std::string> split(const std::string& s, char delimiter) {
	std::vector<std::string> split_string;
	if (s.empty()) { return split_string; }

	std::string str;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == delimiter) {
			split_string.push_back(str);
			str = "";
		}
		else {
			str += s[i];
		}
	}

	split_string.push_back(str);
	return split_string;
}

Scene Scene::load_from_file(const std::string& filepath, bool flip_y_and_z_axis, bool invert_z_axis) {
	Scene scene;
	std::ifstream file(filepath);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::vector<std::string> values = split(line, ' ');
			if (values.size() < 1) { continue; }

			SceneTag tag = get_command(values[0]);
			if (tag == SceneTag::NULL_SCENE_TAG) {
				std::cout << "ERROR::Scene::load_from_file::ERROR_READING_FILE::INVALID_TAG: " << filepath << std::endl;
			}
			exectue_command(tag, values, scene, flip_y_and_z_axis, invert_z_axis);
		}
	}

	return scene;
}