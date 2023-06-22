#pragma once
#include "Cube.h"
#include "Camera.h"
#include "Light.h"
#include "Model.h"
#include "GUI.h"
class Features
{
	DeviceAccessPoint* device;
	Cube* cube;
	Camera* cam;
	Light* light;
	Model* backpack;
	GUI* gui;
	float cubeColor[3] = {123.0f, 23.0f, 234.0f};

	bool render;
public:
	Features(GLFWwindow* window) {
		glEnable(GL_DEPTH_TEST);
		device = DeviceAccessPoint::getInstance();

		gui = new GUI(window);
		cam = new Camera;
		cube = new Cube;
		light = new Light;
		std::string modelpath_s = "./res/backpack/backpack.obj";
		char* modelpath = &modelpath_s[0];
		backpack = new Model(modelpath);
		device->makeShaderProgram("BackpackShader", "./modelVS.glsl", "./modelFS.glsl");

		light->transform->position = glm::vec3(1.3f, -0.8f, 0.0f);
		device->useShaderProgram("ShaderProgramCube");
		device->updateShaderProgramv3("ShaderProgramCube", "lightPos", light->transform->position);
		device->updateShaderProgramv3("ShaderProgramCube", "objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
		render = true;
	}
	~Features() {
		gui->shutdown();
	}
	void engineUpdate();
	void engineRender();
};

