#include "Mesh.h"

void Mesh::loadBasicBuffersFromFile(std::string vertexPath, std::string indexPath) {
	// carga vertex buffer desde archivo
	std::string line;
	std::vector<float> vertexVector;
	std::ifstream vertexfile(vertexPath);
	if (vertexfile.is_open()) {
		while (std::getline(vertexfile, line)) {
			vertexVector.push_back(std::stof(line));
		}
		vertexfile.close();
	}
	else {
		std::cout << "VERTEX_BUFFER::LOAD::EXCEPTION file can't open";
	}

	float* vertexArray = new float[vertexVector.size()];
	for (size_t i = 0; i < vertexVector.size(); i++) {
		vertexArray[i] = vertexVector[i];
	}

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexVector.size(), vertexArray, GL_STATIC_DRAW);

	delete[] vertexArray;

	// carga index buffer desde archivo
	std::vector<int> indexVector;
	std::ifstream indexfile(indexPath);
	if (indexfile.is_open()) {
		while (std::getline(indexfile, line)) {
			int value = std::stoi(line);
			indexVector.push_back(value);
		}
		indexfile.close();
	}
	else {
		std::cout << "INDEX_BUFFER::LOAD::EXCEPTION file can't open";
	}

	int* indexArray = new int[indexVector.size()];
	for (size_t i = 0; i < indexVector.size(); i++) {
		indexArray[i] = indexVector[i];
	}

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexVector.size(), indexArray, GL_STATIC_DRAW);

	delete[] indexArray;
}