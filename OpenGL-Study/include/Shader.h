#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>

using namespace std;

class Shader {
public:
	void LoadShader(const char* _vert_path, const char* _frag_path);
	void LoadShaderFromSource(const char* _vertSource, const char* _fragSource);
	// use method
	void useShader();
	// set Uniform Bool
	void setUniformBool(const std::string& _name, bool _bool);
	// set Uniform Values
	void setUniformInt(const std::string &_name, int _value);
	void setUniformFloat(const std::string& _name, float _value);

	// set Uniform Vector
	void setUniformVec2(const std::string& _name, const glm::vec2& _vec);
	void setUniformVec3(const std::string& _name, const glm::vec3& _vec);
	void setUniformVec4(const std::string& _name, const glm::vec4& _vec);
	// set Uniform Vector Array
	void setUniformVec2v(const std::string& _name, const glm::vec2& _vec, int _num);
	void setUniformVec3v(const std::string& _name, const glm::vec3& _vec, int _num);
	void setUniformVec4v(const std::string& _name, const glm::vec4& _vec, int _num);

	// set Uniform Matrix
	void setUniformMat2(const std::string& _name, const glm::mat2& _mat);
	void setUniformMat3(const std::string& _name, const glm::mat3& _mat);
	void setUniformMat4(const std::string& _name, const glm::mat4& _mat);
	// set Uniform Matrix Array
	void setUniformMat2v(const std::string& _name, const glm::mat2& _mat, int _num);
	void setUniformMat3v(const std::string& _name, const glm::mat3& _mat, int _num);
	void setUniformMat4v(const std::string& _name, const glm::mat4& _mat, int _num);
	

private:
	int shaderID_;
	const char* fragSource_;
	const char* vertSource_;
};