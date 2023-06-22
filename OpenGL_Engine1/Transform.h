#pragma once
#include "DeviceAccessPoint.h"
class Transform
{
	DeviceAccessPoint* device;
public:
	Transform() {
		device = DeviceAccessPoint::getInstance();
		rotationAngle = 0.0f;
		rotationAxis = glm::vec3(1.0f,1.0f,1.0f);
		position = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	float rotationAngle;
	glm::vec3 rotationAxis;
	glm::vec3 position;
	void transformUpdate(unsigned int shaderID);
};

