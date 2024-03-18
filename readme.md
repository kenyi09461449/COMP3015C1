

# Introduction

A model was loaded, which includes diffuse maps, normal maps, and ambient maps.
You can use WASD and mouse movement control to move the perspective, the spacebar can rise, and the CTRL key can sink



# Model，Texture 

The third-party library assimp was used to load the model. And convert the material maps loaded into the model and the model into custom data structures: model, mesh, texture

Model provides an interface for OpenGL drawing

void Model::Draw(GLSLProgram& shader)

A model contains multiple meshes, each with a diffuse map, normal map, and ambient map.

By defining a material structure in blinn_phone.frag to receive the model map read. Shininess refers to the glossiness of the material.

```
struct Material {
    sampler2D diffuse;
    sampler2D normal;
    sampler2D specular;
    float shininess;
}; 
```

# blinn_phone

Using blinn_phone coloring in blinn_phone.frag.

```
 // specular shading
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
```



# Input

Added an Input class and set it as a singleton class. If other classes require the acquisition of button and mouse states, they can be directly obtained through Input.

# Light

A total of three lights have been added to the scene, one Direction Light, one Point Light, and one Spot Light. And corresponding light source calculations have been added in blinn_phone.frag.

