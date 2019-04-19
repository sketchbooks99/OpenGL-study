#version 450 core
precision mediump float;

in vec2 vTexCoord;
in vec3 vColor;

uniform sampler2D texture1;

out vec4 fragColor;

void main() {
	fragColor = texture(texture1, vTexCoord) * vec4(vColor, 1.0);
}