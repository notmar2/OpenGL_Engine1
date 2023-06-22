#include "Camera.h"

void Camera::_update() {
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::lookAt(position, front, camup);
	device->useShaderProgram("ShaderProgramCube");
	int viewloc = glGetUniformLocation(device->getShaderProgramID("ShaderProgramCube"), "view");
	glUniformMatrix4fv(viewloc, 1, GL_FALSE, glm::value_ptr(view));
	device->useShaderProgram("ShaderLightCube");
	int viewloc2 = glGetUniformLocation(device->getShaderProgramID("ShaderLightCube"), "view");
	glUniformMatrix4fv(viewloc2, 1, GL_FALSE, glm::value_ptr(view));

}

void Camera::setProjection(float fov, float width, float height) {
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(fov), width / height, 0.1f, 100.0f);

	device->useShaderProgram("ShaderProgramCube");
	int projectionloc = glGetUniformLocation(device->getShaderProgramID("ShaderProgramCube"), "projection");
	glUniformMatrix4fv(projectionloc, 1, GL_FALSE, glm::value_ptr(projection));
	device->useShaderProgram("ShaderLightCube");
	int projectionloc2 = glGetUniformLocation(device->getShaderProgramID("ShaderLightCube"), "projection");
	glUniformMatrix4fv(projectionloc2, 1, GL_FALSE, glm::value_ptr(projection));
}