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
	result.object = NULL;

	vec3 ray_pnt = ray.endpoint;;
	vec3 ray_dir = ray.direction;
	vec3 plane_pnt = this->x1;
	vec3 plane_norm = this->normal;

	if (dot(ray_dir,plane_norm) != 0) {
		float t = dot(plane_pnt - ray_pnt, plane_norm) / dot(ray_dir, plane_norm);
   
		if (t > small_t) {
			result.object = this;
			result.dist = t;
		}

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
