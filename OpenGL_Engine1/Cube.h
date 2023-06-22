#pragma once
#include "Object.h"
class Cube : public Object
{
	unsigned int VAO;
	unsigned int shaderProgram;
public:
	Cube() : Object() {
		device = DeviceAccessPoint::getInstance();
		VAO = device->createVAO("VAOCube");
		shaderProgram = device->makeShaderProgram("ShaderProgramCube", "./VertexShader.glsl", "./FragmentShader.glsl");
		device->useShaderProgram("ShaderProgramCube");
		int lightLoc = glGetUniformLocation(shaderProgram, "lightColor");
		glm::vec3 lightColorValue(0.8f, 0.2f, 1.0f);
		glUniform3fv(lightLoc, 1, glm::value_ptr(lightColorValue));
		mesh = new Mesh;
		mesh->loadBasicBuffersFromFile("./cubeVB.vbuf", "./cubeIB.ibuf");
		device->createAttribPointer(0, 3, 8 * sizeof(float), 0);
		device->createAttribPointer(1, 3, 8 * sizeof(float), (3 * sizeof(float)));
		device->createAttribPointer(2, 3, 8 * sizeof(float), (5 * sizeof(float)));
		texture = new Texture("./container.jpg");
		transform = new Transform();
	}
	void _init() override;
	void _draw() override;
	void _update() override;
	void changeColor(float* _color);
};

