#include "scene.hpp"

enum class SceneTag {
	WIDTH,
	HEIGHT,
	BACKGROUND,
	BOX,
	CYLINDER,
	SPHERE,
	CAMERA,
	AMBIENT_LIGHT,
	DIRECTIONAL_LIGHT,
	POINT_LIGHT,
	MESH,
	NULL_SCENE_TAG
};

const std::unordered_map<std::string, SceneTag> scene_tags{
	{"w", SceneTag::WIDTH},
	{"h", SceneTag::HEIGHT},
	{"bg", SceneTag::BACKGROUND},
	{"box", SceneTag::BOX},
	{"cylinder", SceneTag::CYLINDER},
	{"sphere", SceneTag::SPHERE},
	{"camera", SceneTag::CAMERA},
	{"ambient", SceneTag::AMBIENT_LIGHT},
	{"directional", SceneTag::DIRECTIONAL_LIGHT},
	{"point", SceneTag::POINT_LIGHT},
	{"mesh", SceneTag::MESH}
};

void exectue_command(const SceneTag& tag, const std::vector<std::string>& args, Scene& scene) {
	std::vector<float> floats;
	std::vector<int> ints;

	for (int i = 1; i < args.size(); i++) {
		try {
			float item = std::stof(args[i]);
			floats.push_back(item);
		}
		catch (std::invalid_argument e) {
			;
		}

		try {
			int item = std::stoi(args[i]);
			ints.push_back(item);
		}
		catch (std::invalid_argument e) {
			;
		}
	}

	switch (tag) {
	case SceneTag::WIDTH: {
		assert(args.size() == 1 + 1);
		scene.width = ints[0];
		break;
	}
	case SceneTag::HEIGHT: {
		assert(args.size() == 1 + 1);
		scene.height = ints[0];
		break;
	}
	case SceneTag::BACKGROUND: {
		assert(args.size() == 3 + 1);
		scene.background_color = glm::vec3(floats[0], floats[1], floats[2]);
		break;
	}
	case SceneTag::BOX: {
		assert(args.size() == 9 + 1);
		glm::vec3 min(floats[0], floats[1], floats[2]);
		glm::vec3 max(floats[3], floats[4], floats[5]);
		glm::vec3 diffuse(floats[6], floats[7], floats[8]);
		Box* box = new Box(min, max, Material(diffuse, 32));
		scene.add(box);
		break;
	}
	case SceneTag::CAMERA: {
		assert(args.size() == 8 + 1);
		glm::vec3 pos(floats[0], floats[1], floats[2]);
		float ry = floats[3];
		glm::quat rotation(floats[4], floats[5], floats[6], floats[7]);
		Camera camera = Camera(pos, ry, rotation);
		scene.add(camera);
		break;
	}
	case SceneTag::SPHERE: {
		assert(args.size() == 7 + 1);
		glm::vec3 center(floats[0], floats[1], floats[2]);
		float radius = floats[3];
		glm::vec3 diffuse(floats[4], floats[5], floats[6]);
		Sphere* sphere = new Sphere(center, radius, Material(diffuse, 32));
		scene.add(sphere);
		break;
	}
	case SceneTag::CYLINDER: {
		/*assert(args.size() == 10 + 1);
		glm::vec3 base(floats[0], floats[1], floats[2]);
		glm::vec3 axis(floats[3], floats[4], floats[5]);
		float radius = floats[6];
		glm::vec3 diffuse(floats[7], floats[8], floats[9]);
		Cylinder* cylinder = new Cylinder(base, axis, radius, Material(diffuse, 32));
		scene.add(cylinder);*/
		break;
	}
	case SceneTag::AMBIENT_LIGHT: {
		assert(args.size() == 1 + 1);
		scene.ambient = floats[0];
		break;
	}
	case SceneTag::DIRECTIONAL_LIGHT: {
		assert(args.size() == 4 + 1);
		glm::vec3 direction(floats[0], floats[1], floats[2]);
		float intensity = floats[3];
		DirectionalLight* directional_light = new DirectionalLight(direction, intensity);
		scene.add(directional_light);
		break;
	}
	case SceneTag::POINT_LIGHT: {
		assert(args.size() == 4 + 1);
		glm::vec3 position(std::stof(args[1]), std::stof(args[2]), std::stof(args[3]));
		float intensity = std::stof(args[4]);
		PointLight* point_light = new PointLight(position, intensity);
		scene.add(point_light);
		break;
	}
	case SceneTag::MESH: {
		assert(args.size() == 15 + 1);
		std::string filepath = FileSystem::get_path("/scenes/" + args[1]);
		glm::vec3 position(floats[0], floats[1], floats[2]);
		glm::vec3 scale(floats[3], floats[3], floats[3]);
		glm::quat rotation(floats[7], floats[8], floats[9], floats[10]);
		glm::vec3 axis_rotation(floats[4], floats[5], floats[6]);
		glm::vec3 diffuse(floats[11], floats[12], floats[13]);
		Mesh mesh(position, scale, rotation, axis_rotation, Material(diffuse, 32));
		mesh.load_from_file(filepath);
		scene.add(mesh);
		break;
	}
	default:
		break;
	}
}

SceneTag get_command(const std::string& value) {
	auto it = scene_tags.find(value);
	if (it != scene_tags.end()) {
		return it->second;
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

void Scene::load_from_file(const std::string& filepath, Scene& scene) {
	std::ifstream file(filepath);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::vector<std::string> values = split(line, ' ');
			if (values.size() < 1 || values[0][0] == '#') { continue; }
			SceneTag tag = get_command(values[0]);

			if (tag == SceneTag::NULL_SCENE_TAG) {
				std::cout << "ERROR::Scene::load_from_file::ERROR_READING_FILE::INVALID_TAG: " << filepath << std::endl;
			}

			exectue_command(tag, values, scene);
		}
	}
}