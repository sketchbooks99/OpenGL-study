#include "Texture.h"
#include "Shader.h"

// =================================================
void Texture::draw() {

}

// =================================================
// ENABLE image format ...
// PNG, JPG, BMP, TGA, DDS, PSD, HDR
void Texture::load(const char* _tex_path) {
	unsigned char* data;
	// generate texture
	glGenTextures(1, &texID_);

	// bind texture
	glBindTexture(GL_TEXTURE_2D, texID_);

	// load image by SOIL
	data = SOIL_load_image(_tex_path, &width_, &height_, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	SOIL_free_image_data(data);

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set texture filtering paramters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

// =================================================
void Texture::resize(int _width, int _height) {

}

// =================================================
GLuint Texture::getTextureID() {
	return texID_;
}

