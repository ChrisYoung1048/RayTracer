#include "plane.h"
#include "ray.h"
#include <cfloat>
#include <limits>

// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
Hit Plane::Intersection(const Ray& ray, int part) const
{
	Hit result;

	vec3 ray_to_point = x1 - ray.endpoint;
	float ray_normal_dot = dot(ray.direction, normal);

	if (ray_normal_dot != 0) {
		float t = dot(ray_to_point, normal) / ray_normal_dot;
   
		if (t > small_t) {
			result.object = this;
			result.dist = t;
		
		}
		else {
			result.object = NULL;
		
		}

	}
	else {
		result.object = NULL;
	
	}


    return result;
}

vec3 Plane::Normal(const vec3& point, int part) const
{
    return normal;
}

// There is not a good answer for the bounding box of an infinite object.
// The safe thing to do is to return a box that contains everything.
Box Plane::Bounding_Box(int part) const
{
    Box b;
    b.hi.fill(std::numeric_limits<double>::max());
    b.lo=-b.hi;
    return b;
}
