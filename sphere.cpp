#include "sphere.h"

bool Sphere::intersects(const Ray& ray) const {
	// first we need a vector from the ray to the center of the circle
	// in the direction of the ray, first get the vector from the ray 
	// origin to the circle, e
	Vector3 e = ray.origin - center;

	// If magnitude of e is less than spheres radius, ray origin is inside sphere
	if (Magnitude(e) < radius)
		return false;

	// project e onto the ray's direction to get the vector in the ray's direction
	Vector3 a = Project(e, ray.direction);

	// using a, get the reject of eProja, b
	Vector3 b = Reject(e, a);

	// now use pythagorean theorem to get the vector f, where a +- f is the possible values of t
	// the radius of the sphere is the hypotenuse in this equation
	float f = sqrtf((radius * radius) - (Magnitude(b) * Magnitude(b)));

	// finally, get the value of t
	float t = Magnitude(a) - f;

	// Possible cases for t
	// t > 0, 2 intersections (a - f, a + f)
	// t == 0, 1 intersection, hit point is tangent to the sphere
	// t < 0, no intersection
	if (t < 0)
		return false;
	else
		return true;
}