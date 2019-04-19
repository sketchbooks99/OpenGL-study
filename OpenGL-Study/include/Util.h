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

#include "Shader.h"

using namespace std;

GLFWwindow* createWindow(int _width, int _height, int _major, int _minor);
void processInput(GLFWwindow* _window);
void framebuffer_size_callback(GLFWwindow* _window, int _width, int _height);