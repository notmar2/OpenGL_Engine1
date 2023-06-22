#include "Transform.h"

void Transform::transformUpdate(unsigned int shaderID) {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, rotationAngle, rotationAxis) * glm::translate(model,position);
	int modelloc = glGetUniformLocation(shaderID, "model");
	glUniformMatrix4fv(modelloc, 1, GL_FALSE, glm::value_ptr(model));
}