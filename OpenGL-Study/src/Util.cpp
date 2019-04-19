#include "Util.h"

GLFWwindow* createWindow(int _width, int _height, int _major, int _minor) {
	switch (_major) {
	case 2:
		if (_minor != 0 && _minor != 1) {
			std::cout << "this version " << _major << "." << _minor << " is not supported" << std::endl;
			glfwTerminate();
		}
		break;
	case 3:
		if (_minor != 0 && _minor != 1 &&
			_minor != 2 && _minor != 3) {
			std::cout << "this version " << _major << "." << _minor << " is not supported" << std::endl;
			glfwTerminate();
		}
		break;
	case 4:
		if (_minor < 0 || _minor > 6) {
			std::cout << "this version " << _major << "." << _minor << " is not supported" << std::endl;
			glfwTerminate();
		}
		break;
	default:
		std::cout << "this version " << _major << "." << _minor << " is not supported" << std::endl;
		glfwTerminate();
		break;
	}

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(_width, _height, "", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return window;
}

void processInput(GLFWwindow* _window) {
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(_window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* _window, int _width, int _height) {
	glViewport(0, 0, _width, _height);
}