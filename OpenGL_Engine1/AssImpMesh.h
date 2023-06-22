#pragma once

#include <string>
#include <vector>
#include "DeviceAccessPoint.h"

using namespace std;

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct AssTexture {
	unsigned int id;
	std::string type;
};

class AssImpMesh
{
public:
    // mesh data
    vector<Vertex>       vertices;
    vector<unsigned int> indices;
    vector<AssTexture>      textures;
    DeviceAccessPoint* device;

    AssImpMesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<AssTexture> textures);
    void Draw(std::string shaderName);
private:
    //  render data
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};

