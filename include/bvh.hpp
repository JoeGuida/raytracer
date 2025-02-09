#ifndef RAYTRACER_BVH_HPP
#define RAYTRACER_BVH_HPP

#include "bvh/v2/bvh.h"
#include "bvh/v2/default_builder.h"
#include "bvh/v2/vec.h"
#include "bvh/v2/ray.h"
#include "bvh/v2/node.h"
#include "bvh/v2/tri.h"
#include "bvh/v2/thread_pool.h"
#include "bvh/v2/executor.h"
#include "bvh/v2/stack.h"

#include <vector>

using Scalar = float;
using Tri = bvh::v2::Tri<Scalar, 3>;

class BVH {
public:
	std::vector<Tri> tris;

	BVH() {}
};

#endif