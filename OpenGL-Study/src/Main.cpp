#include <iostream>

// æ‚Églad‚ğ“Ç‚İ‚Ş•K—v‚ ‚èH
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Texture.h"

GLFWwindow* window;

const unsigned int WIDTH = 1920;
const unsigned int HEIGHT = 1080;

int main() {
	//glfw : initialize GLFW window
	window = createWindow(WIDTH, HEIGHT, 4, 5);
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Render(window);

	return 0;
}