#include "refractive_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Refractive_Shader::
Shade_Surface(const Ray& ray, const vec3& intersection_point,
	const vec3& norm, int recursion_depth) const
{
	
	vec3 color;
	vec3 normal = norm;
	vec3 view_ray = -ray.direction;
	double n1 = 1.00; //assuming Air is the default medium 
	double n_dot_v = -dot(normal, view_ray);
	double ref_ratio = n1 / refractivity;

	double sqrt_term = 1 - (ref_ratio * ref_ratio) * (1 -(n_dot_v * n_dot_v));  
  
	if (sqrt_term >= 0) {
	
		vec3 refracted_vector = ref_ratio * (-view_ray + normal * (n_dot_v)) - (normal * sqrt(sqrt_term));
		
		Ray refracted_ray;
		refracted_ray.endpoint = intersection_point;
		refracted_ray.direction = refracted_vector.normalized();
		
		vec3 refracted_color = world.Cast_Ray(refracted_ray, recursion_depth + 1);

		color = refracted_color;
	}

	return color;

}
