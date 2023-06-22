#include "Window.h"

Window::Window(int _width, int _length) : width(_width), length(_length) {
	msg = 0;
	window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		msg = -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		msg = -1;
	}
	glViewport(0, 0, width, length);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}