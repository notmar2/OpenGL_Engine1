#pragma once
#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window
{
	int width;
	int length;
	GLFWwindow* window;
	int msg;
public:
	Window(int _width, int _length);
	GLFWwindow* getWindow() { return window; }
	int getMsg() { return msg; }
};

