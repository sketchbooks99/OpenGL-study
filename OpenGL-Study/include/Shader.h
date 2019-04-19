#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

class Shader {
public:
	void LoadShader(const char* _vert_path, const char* _frag_path);

private:
	int shaderID_;
};

int LoadShader(const char* _vert_path, const char* _frag_path);