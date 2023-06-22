#include "Shader.h"

Shader::Shader() {
	shaderString = nullptr;
}

Shader::Shader(std::string path, ShaderType type) {
	shaderString = nullptr;
	loadShaderFromFile(path, type);
}

Shader::~Shader() {
	delete[] shaderString;
}

void Shader::loadShaderFromFile(std::string path, ShaderType type) {
	std::string lines, line;
	std::ifstream file(path);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			lines += line + "\n";
		}
		file.close();
	}
	else {
		std::cout << "SHADER::LOAD::EXCEPTION file can't open";
	}

	const char* shader = &lines[0];
	delete[] shaderString;
	shaderString = new char[strlen(shader) + 1];
	strcpy_s(shaderString, strlen(shader) + 1 , shader);

	int success;
	char infoLog[512];

	switch (type) {
	case VERTEX_SHADER:
		shaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(shaderID, 1, &shaderString, NULL);
		glCompileShader(shaderID);

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		} // debug
		break;
	case FRAGMENT_SHADER:
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(shaderID, 1, &shaderString, NULL);
		glCompileShader(shaderID);

		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		} // debug
		break;
	default:
		std::cout << "ERROR::SHADER_COMPILE::INVALID_TYPE" << std::endl;
	}	
}