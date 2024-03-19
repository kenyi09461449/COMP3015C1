#ifndef MODEL_H
#define MODEL_H
#include "glslprogram.h"
#include "mesh.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


//create opengl texture obj
unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);


class Model
{
public:
    /*attritbute*/
    glm::vec3 Position = glm::vec3(0.0,0.0,-10.0);
    glm::vec3 Scale = glm::vec3(1.25,1.25, 1.25);


    Model(const char* path)
    {
        loadModel(path);
    }
    void Draw(GLSLProgram& shader);
public:
    vector<Texture> textures_loaded;
private:
    vector<Mesh> meshes;
    string directory;
    /*  º¯Êý   */
    void loadModel(string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    //get 
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

#endif