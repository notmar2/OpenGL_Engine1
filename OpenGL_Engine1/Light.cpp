#include "Light.h"

void Light::_init() {

}

void Light::_update() {

}

void Light::_draw() {
	device->useShaderProgram("ShaderLightCube");
	transform->transformUpdate(device->getShaderProgramID("ShaderLightCube"));
	device->useVAO("lightCubeVAO");
	device->draw(false, 36);
}

