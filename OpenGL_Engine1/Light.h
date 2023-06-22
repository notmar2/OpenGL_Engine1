#pragma once
#include "Object.h"
#include "DeviceAccessPoint.h"
class Light : public Object
{
	DeviceAccessPoint* device;
	unsigned int lightCubeVAO;
	unsigned int ShaderProgramCube;
public:
	Light() {
		device = DeviceAccessPoint::getInstance();
		lightCubeVAO = device->createVAO("lightCubeVAO");

		ShaderProgramCube = device->makeShaderProgram("ShaderLightCube", "./ShaderVerLightCube.glsl", "./ShaderFragLightCube.glsl");
		device->useShaderProgram("ShaderLightCube");
		mesh = new Mesh;
		mesh->loadBasicBuffersFromFile("./lightCube.vbuf", "./cubeIB.ibuf");

		device->createAttribPointer(0, 3, 3 * sizeof(float), 0);
		transform = new Transform;
	}

	void _init() override;
	void _draw() override;
	void _update() override;
};

