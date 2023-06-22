#include "Features.h"

void Features::engineUpdate() {
	// Updates
	gui->createFrame();
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	cube->transform->rotationAngle = (float)glfwGetTime() * glm::radians(50.0f);
	cube->transform->rotationAxis = glm::vec3(0.5f, 1.0f, 0.0f);
	cube->transform->position = glm::vec3(0.0f, 0.0f, 0.0f);

	//model stuff
	/*
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
	device->useShaderProgram("BackpackShader");
	int modelloc = glGetUniformLocation(device->getShaderProgramID("BackpackShader"), "model");
	glUniformMatrix4fv(modelloc, 1, GL_FALSE, glm::value_ptr(model));
	backpack->Draw("BackpackShader");
	*/

	cam->position = glm::vec3(0.0f, 0.0f, 3.0f);
	cam->setProjection(45.0f, 800.0f, 600.0f);

	cam->_update();

	// Render
	if (render) this->engineRender();
	else device->clearscreen();

	gui->begin();

	gui->checkbox(&render);
	gui->colorEdit(cubeColor);
	cube->changeColor(cubeColor);

	gui->render();
}

void Features::engineRender() {
	device->clearscreen();

	light->_draw();
	cube->_draw();
	
}