#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texcoord;

out vec2 vTexCoord;
out vec3 vColor;

void main() {
	gl_Position = vec4(position, 1.0);
	vColor = color;
	vTexCoord = texcoord;
}