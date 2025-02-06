#include "mesh.hpp"

void Mesh::exectue_command(const ObjTag& tag, const std::vector<std::string>& args) {
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
	case ObjTag::VERTEX: {
		assert(floats.size() == 3);
		glm::vec3 v = glm::vec3(floats[0], floats[1], floats[2]);
		v = glm::rotateX(v, glm::radians(axis_rotation.x));
		v = glm::rotateY(v, glm::radians(axis_rotation.y));
		v = glm::rotateZ(v, glm::radians(axis_rotation.z));
		v = v * scale + position;
		vertices.push_back(v);
		break;
	}
	case ObjTag::FACE: {
		assert(ints.size() >= 3);
		if (ints.size() == 3) {
			glm::vec3 a = vertices[ints[0] - 1];
			glm::vec3 b = vertices[ints[1] - 1];
			glm::vec3 c = vertices[ints[2] - 1];
			Triangle* triangle = new Triangle(a, b, c, position, material);
			triangles.push_back(triangle);
		}
		if (ints.size() == 4) {
			glm::vec3 v0 = vertices[ints[0] - 1];
			glm::vec3 v1 = vertices[ints[1] - 1];
			glm::vec3 v2 = vertices[ints[2] - 1];
			glm::vec3 v3 = vertices[ints[3] - 1];
			Material m = material;
			Triangle* triangle0 = new Triangle(v0, v1, v2, position, material);
			Triangle* triangle1 = new Triangle(v1, v2, v3, position, material);
			triangles.push_back(triangle0);
			triangles.push_back(triangle1);
		}
		break;
	}
	default:
		break;
	}
}

static ObjTag get_command(const std::string& value) {
	auto it = obj_tags.find(value);
	if (it != obj_tags.end()) {
		return it->second;
	}

	return ObjTag::NULL_OBJ_TAG;
}

static std::vector<std::string> split(const std::string& s, char delimiter) {
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

void Mesh::load_from_file(const std::string& filepath) {
	std::ifstream file(filepath);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::vector<std::string> values = split(line, ' ');
			if (values.size() < 1 || values[0][0] == '#') { continue; }
			ObjTag tag = get_command(values[0]);

			if (tag == ObjTag::NULL_OBJ_TAG) {
				std::cout << "ERROR::Mesh::load_from_file::ERROR_READING_FILE::INVALID_TAG: " << filepath << std::endl;
				std::cout << line << std::endl;
			}

			exectue_command(tag, values);
		}
	}
}