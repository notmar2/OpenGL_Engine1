#pragma once
#include "DeviceAccessPoint.h"
class Camera
{
	glm::vec3 camup;
	glm::vec3 front;

	//const float camSpeed = 0.05f;

	DeviceAccessPoint* device;
public:
	Camera() {
		device = DeviceAccessPoint::getInstance();
		camup = glm::vec3(0.0f, 1.0f, 0.0f);
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		front = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	glm::vec3 position;
	void _update();
	void setProjection(float fov, float width, float height);
};

