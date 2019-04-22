#pragma once

#include "Util.h"
#include <iostream>
#include <SOIL2/SOIL2.h>

class Texture {
public:
	void draw();
	void load(const char* _tex_path);
	void resize(int _width, int _height);
	GLuint getTextureID();

private:
	GLuint texID_;
	float* vertices_;
	int width_;
	int height_;

	const GLchar* vert_source = "#version 450\
		layout(location = 0) in vec3 position;\
		layout(location = 1) in vec2 texcoord;\
		\
		out vec2 vTexCoord;\
		void main() {\
			gl_Position = vec4(position, 1.0);\
			vTexCoord = texcoord;\
		}";

	const GLchar* frag_source = "#version 450\
		precision mediump float;\
		uniform sampler2D tex;\
		\
		in vec2 vTexCoord;\
		\
		out vec4 fragColor;\
		void main() {\
			fragColor = texture(tex, vTexCoord);\
		}";

};
