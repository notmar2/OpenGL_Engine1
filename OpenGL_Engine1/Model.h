#pragma once
#include "AssImpMesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Model
{
public:
    Model(char* path)
    {
        loadModel(path);
    }
    void Draw(std::string shaderName);
private:
    // model data
    //vector<AssImpMesh> textures_loaded;
    vector<AssImpMesh> meshes;
    string directory;

    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    AssImpMesh processMesh(aiMesh* mesh, const aiScene* scene);
    //vector<AssImpMesh> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

