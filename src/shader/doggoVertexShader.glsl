#version 410 core

layout(location = 0) in vec3 aPos;

uniform mat4 matrix;
uniform mat4 viewMat;
uniform mat4 projMat;


void main()
{
	gl_Position = projMat * viewMat * matrix * vec4(aPos, 1.0);
}
