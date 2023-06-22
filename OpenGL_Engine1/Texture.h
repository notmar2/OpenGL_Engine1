#pragma once
#include "stb_image.h"
#include <string>
#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
class Texture
{
	unsigned int textureID;
	int width, height, nrChannels;
	unsigned char* data;

public:
	Texture() {}
	Texture(std::string path);
	void loadTextureFromFile(std::string path);
	unsigned int getID() { return textureID; }
};

