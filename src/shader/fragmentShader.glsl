#version 410 core

in vec2 TexCoord;

out vec4 FragColor;

uniform vec3 color;
uniform sampler2D ourTexture;

void main()
{
	FragColor = texture(ourTexture, TexCoord) * vec4(color, 1.0f);
}
