#pragma once

#include "Scene.h"
#include "ShaderStuff/Shader.h"
#include "RenderStuff/Mesh.h"
#include "RenderStuff/Camera.h"

#include <glm/gtc/quaternion.hpp>

class MenuScene : public Scene
{
public:
	MenuScene(GLFWwindow* window, std::string sceneName);
	
	void loadData();


private:

	virtual void virtualUpdate(float dt)override;

	Shader* myTestShader = NULL;
	Mesh* myTestMesh = NULL;
	Camera* myTestCamera = NULL;
};