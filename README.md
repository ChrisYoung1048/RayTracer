# CS130 UCR RayTracer

## Description

This project demonstrate a raytracing system. The following are implemented in this project:
- ray-circle intersections
- ray-triangle intersections
- Phong shading ( ambient, diffuse, and specular components)
- shadows
- reflection and refraction

## Usage

Compile the project with `scons` and then run each test ( 0 - 31 ) with the following:
`./ray_tracer -i XX.txt`
Where XX is in the range 00-31.

The outputted image will be stored in `output.png`
The reference images can be seen in 00.png - 31.png
The project can be compared to the grading script with `./grading-script.py .`

## Example Outputs
Basic Intersections
![output1](https://github.com/DishonJordan/RayTracer/blob/master/03.png)
Phong Shading Implementation
![output2](https://github.com/DishonJordan/RayTracer/blob/master/12.png)
Specular Highlights - Phong Shading
![output3](https://github.com/DishonJordan/RayTracer/blob/master/18.png)
Shadows
![output3](https://github.com/DishonJordan/RayTracer/blob/master/20.png)
Reflection and Recursion Depth
![output4](https://github.com/DishonJordan/RayTracer/blob/master/25.png)
Triangle Meshes
![output5](https://github.com/DishonJordan/RayTracer/blob/master/27.png)
Refraction Implementation
![output6](https://github.com/DishonJordan/RayTracer/blob/master/31.png)


