#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>

class Mesh
{
	unsigned int VBO;
	unsigned int EBO;
public:
	Mesh(){}
	void loadBasicBuffersFromFile(std::string vertexPath, std::string indexPath);
};

