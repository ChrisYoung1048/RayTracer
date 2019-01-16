#include "sphere.h"
#include "ray.h"
#include "algorithm"


// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
	Hit result;
	vec3 ray_to_sphere = center - ray.endpoint;
	float b = dot(ray.direction, ray_to_sphere);
	float discriminant = pow(b,2) - ray_to_sphere.magnitude_squared() + pow(radius,2);

	if (discriminant >= 0) {
		float t = std::min( b + sqrt(discriminant), b - sqrt(discriminant));
		result.object = this;
		result.dist = t;
	}
	else
	{
		result.object = NULL;
	}

    return result;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    // compute the normal direction
	TODO;
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
