#pragma once

#include "helper/scene.h"
#include <glad/glad.h>
#include "helper/glslprogram.h"
#include "helper/camera.h"
#include "helper/model.h"
#include "helper/light.h"
#include <memory>
#include "helper/skybox.h"

class SceneBasic_Uniform : public Scene
{
private:
    GLSLProgram prog;
    GLSLProgram skyShader;
    
    SkyBox      *m_skybox;
    Camera      *m_camera;
    Model       *m_model;
    DirLight    *m_dirLight;
    PointLight  *m_pointLight; 
    SpotLight   *m_spotLight;


    float angle;
    void compile();

public:
    SceneBasic_Uniform();
    ~SceneBasic_Uniform()
    {}
    void initScene();
    void update(float t);
    void render();
    void resize(int, int);
};
