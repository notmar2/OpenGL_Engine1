#include "DeviceAccessPoint.h"

DeviceAccessPoint* DeviceAccessPoint::device = nullptr;

DeviceAccessPoint* DeviceAccessPoint::getInstance() {
	if (device == nullptr) {
		device = new DeviceAccessPoint();
	}
	return device;
}

unsigned int DeviceAccessPoint::makeShaderProgram(std::string name, std::string shaderpath1, std::string shaderpath2) {
	Shader vs;
	Shader fs;
	
	vs.loadShaderFromFile(shaderpath1, VERTEX_SHADER);
	fs.loadShaderFromFile(shaderpath2, FRAGMENT_SHADER);

	unsigned int shaderID1 = vs.getID();
	unsigned int shaderID2 = fs.getID();

	unsigned int ID; 

	int success;
	char infoLog[512];
	ID = glCreateProgram();
	glAttachShader(ID, shaderID1);
	glAttachShader(ID, shaderID2);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::LINK::PROGRAM::FAILED\n" << infoLog << std::endl;
	} // debug

	shaderProgramIDs[name] = ID;

	glDeleteShader(shaderID1);
	glDeleteShader(shaderID2);
	return ID;
}

void DeviceAccessPoint::useShaderProgram(std::string name) {
	glUseProgram(shaderProgramIDs[name]);
}

void DeviceAccessPoint::updateShaderProgramv3(std::string shaderName, std::string propertyName, glm::vec3 updateValue) {
	int feature = glGetUniformLocation(shaderProgramIDs[shaderName], &propertyName[0]);
	glUniform3fv(feature, 1, glm::value_ptr(updateValue));
}

void DeviceAccessPoint::updateShaderProgramI(std::string shaderName, std::string propertyName, int updateValue) {
	int feature = glGetUniformLocation(shaderProgramIDs[shaderName], &propertyName[0]);
	glUniform1i(feature, updateValue);
}

unsigned int DeviceAccessPoint::createVAO(std::string name) {
	unsigned int ID;
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
	VAOIDs[name] = ID;
	return ID;
}

void DeviceAccessPoint::useVAO(std::string name) {
	glBindVertexArray(VAOIDs[name]);
}

void DeviceAccessPoint::createAttribPointer(int attribute, unsigned long long size, unsigned long long stride, unsigned long long bufferOffset) {
	
	glVertexAttribPointer(attribute, size, GL_FLOAT, GL_FALSE, stride, (void*)bufferOffset);
	glEnableVertexAttribArray(attribute);
}

void DeviceAccessPoint::clearscreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DeviceAccessPoint::draw(bool usesIB, int vertexCount) {
	if (usesIB) glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
	else glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}