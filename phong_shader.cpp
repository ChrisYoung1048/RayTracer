#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include <algorithm>

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
	vec3 color_amb, color_diff, color_spec;
	//AMBIENT COLOR
	color_amb = world.ambient_color * world.ambient_intensity * color_ambient;

	for (unsigned i = 0; i < world.lights.size(); i++) {
		Light* current_light = world.lights[i];

		if (!world.enable_shadows) {
			vec3 light_color = current_light->Emitted_Light(ray.direction);
			vec3 intersection_to_light = current_light->position - intersection_point;

			vec3 R_diffuse = color_diffuse;
			vec3 L_diffuse = light_color / intersection_to_light.magnitude_squared();

			intersection_to_light = intersection_to_light.normalized();

			double NL_dot = std::max(0.0, dot(normal, intersection_to_light));


			//DIFFUSE COLOR
			color_diff += R_diffuse * L_diffuse * NL_dot;
			//SPECULAR COLOR

			vec3 R_specular = color_specular;
			vec3 reflection_vector = (2 * dot(normal, intersection_to_light) * normal) - intersection_to_light;
			reflection_vector = reflection_vector.normalized();

			double RC_dot = std::max(0.0, dot(reflection_vector, -ray.direction.normalized()));
			RC_dot = std::pow(RC_dot, specular_power);

			color_spec += R_specular * L_diffuse * RC_dot;
		}
		else {
			vec3 shadow_direction = (current_light->position - intersection_point).normalized();
			Ray shadow_ray(intersection_point, shadow_direction);

			Hit shadow_hit = world.Closest_Intersection(shadow_ray);

			if (shadow_hit.object == NULL || shadow_hit.dist > (current_light->position - intersection_point).magnitude()) {

				vec3 light_color = current_light->Emitted_Light(ray.direction);
				vec3 intersection_to_light = current_light->position - intersection_point;

				vec3 R_diffuse = color_diffuse;
				vec3 L_diffuse = light_color / intersection_to_light.magnitude_squared();

				intersection_to_light = intersection_to_light.normalized();

				double NL_dot = std::max(0.0, dot(normal, intersection_to_light));


				//DIFFUSE COLOR
				color_diff += R_diffuse * L_diffuse * NL_dot;
				//SPECULAR COLOR

				vec3 R_specular = color_specular;
				vec3 reflection_vector = (2 * dot(normal, intersection_to_light) * normal) - intersection_to_light;
				reflection_vector = reflection_vector.normalized();

				double RC_dot = std::max(0.0, dot(reflection_vector, -ray.direction.normalized()));
				RC_dot = std::pow(RC_dot, specular_power);

				color_spec += R_specular * L_diffuse * RC_dot;

			}
		}
	}
	
	if (debug_pixel) {
		std::cout << "ambient: " << color_amb << std::endl;
		std::cout << "diffuse: " << color_diff << std::endl;
		std::cout << "specular: " << color_spec << std::endl;
	}

	color = color_amb + color_diff + color_spec;
    return color;
}
