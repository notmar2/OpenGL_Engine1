#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <glad/glad.h>
#include <glfw3.h>
enum ShaderType{VERTEX_SHADER, FRAGMENT_SHADER};
class Shader
{
	char* shaderString;
	unsigned int shaderID;
public:
	Shader();
	Shader(std::string path, ShaderType type);
	~Shader();

	const char* getShaderString() { return shaderString; }
	void readString() { std::cout << shaderString << std::endl; }
	void loadShaderFromFile(std::string path, ShaderType type);
	unsigned int getID() { return shaderID; }
};

