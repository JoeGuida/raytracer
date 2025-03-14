#ifndef OPENGL_RENDERER_FILESYSTEM_HPP
#define OPENGL_RENDERER_FILESYSTEM_HPP

#include <cstdlib>
#include <iostream>
#include <string>

struct FileSystem {
    static std::string get_root() {
        const char* env = std::getenv("RAYTRACER_ROOT");
        if (env) {
            return std::string(env);
        }

        std::cout << "ERROR::FILESYSTEM::ERROR_READING_ENVIRONMENT_VARIABLE::RAYTRACER_ROOT" << std::endl;
        return "";
    }

    static std::string get_path(const std::string& path) {
        std::string root = get_root();
        if (!root.empty()) {
            return root + path;
        }

        return "";
    }
};

#endif