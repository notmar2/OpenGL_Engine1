#include "GUI.h"
#include "Features.h"
#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

using namespace std;

void init_glfw();

int main()
{
	init_glfw();

	// init ventana
	Window window(800, 600);
	Features feat(window.getWindow());
	if (window.getMsg() != 0) {
		return window.getMsg();
	}

	//GUI gui(window.getWindow());

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		// Updates
		//gui.createFrame();
		feat.engineUpdate();
		//gui.begin();
		// Swap
		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
		
	}

	//gui.shutdown();
	glfwTerminate();

	return 0;
}

void init_glfw() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}