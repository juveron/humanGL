#version 410 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aTexCoord;

uniform mat4 matrix;
uniform mat4 viewMat;
uniform mat4 projMat;

out vec2 TexCoord;

void main()
{
	gl_Position = projMat * viewMat * matrix * vec4(aPos, 1.0);
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}
