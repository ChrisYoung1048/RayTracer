#ifndef __REFRACTIVE_SHADER_H__
#define __REFRACTIVE_SHADER_H__

#include <algorithm>
#include "shader.h"

class Refractive_Shader : public Shader
{
public:
	Shader* shader;
	double refractivity;

	Refractive_Shader(Render_World& world_input, Shader* shader_input, double refractivity)
		:Shader(world_input), shader(shader_input),
		refractivity(refractivity)
	{}

	virtual vec3 Shade_Surface(const Ray& ray, const vec3& intersection_point,
		const vec3& normal, int recursion_depth) const override;
};
#endif
