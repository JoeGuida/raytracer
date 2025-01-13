#ifndef RAYTRACER_RNG_HPP
#define RAYTRACER_RNG_HPP

#include <random>

class Random {
public:
	template <typename T>
	static T get_random_number(T low, T high) {
		std::random_device device;
		std::mt19937_64 rng(device());
		if constexpr (std::is_integral_v<T>) {
			std::uniform_int_distribution<T> dist(low, high);
			return dist(rng);
		}
		if constexpr (std::is_floating_point_v<T>) {
			std::uniform_real_distribution<T> dist(low, high);
			return dist(rng);
		}
	}
};

#endif