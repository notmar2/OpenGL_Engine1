#include "Cube.h"

void Cube::_init() {

}

void Cube::_update() {
	
}

void Cube::_draw() {
	device->useShaderProgram("ShaderProgramCube");
	transform->transformUpdate(device->getShaderProgramID("ShaderProgramCube"));
	device->useVAO("VAOCube");
	device->draw(false, 36);
}

void Cube::changeColor(float _color[3]) {
	glm::vec3 color(_color[1], _color[2], _color[3]);
	device->updateShaderProgramv3("ShaderProgramCube", "objectColor", glm::normalize(color));
}