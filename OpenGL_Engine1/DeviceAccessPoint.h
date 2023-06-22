#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include <string>
class DeviceAccessPoint
{
	static DeviceAccessPoint* device;
	DeviceAccessPoint() {}
	std::map<std::string, unsigned int> shaderProgramIDs;
	std::map<std::string, unsigned int> VAOIDs;

public:
	static DeviceAccessPoint* getInstance();
	DeviceAccessPoint(DeviceAccessPoint& other) = delete;
	void operator = (const DeviceAccessPoint&) = delete;

	unsigned int makeShaderProgram(std::string name, std::string shaderpath1, std::string shaderpath2);
	void useShaderProgram(std::string name);
	unsigned int getShaderProgramID(std::string name) { return shaderProgramIDs[name]; }
	void updateShaderProgramv3(std::string shaderName, std::string propertyName, glm::vec3 updateValue);
	void updateShaderProgramI(std::string shaderName, std::string propertyName, int updateValue);

	unsigned int createVAO(std::string name);
	void useVAO(std::string name);
	unsigned int getVAOID(std::string name) { return VAOIDs[name]; }

	void createAttribPointer(int attribute, unsigned long long size, unsigned long long stride, unsigned long long bufferOffset);
	void clearscreen();
	void draw(bool usesIB, int vertexCount);
};