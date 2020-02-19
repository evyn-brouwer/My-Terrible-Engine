#pragma once

#include "Scene.h"
#include "RenderStuff/Cube.h"
#include "WorldStuff/Block.h"

#include <glm/gtc/quaternion.hpp>

class MenuScene : public Scene
{
public:
	MenuScene(GLFWwindow* window, std::string sceneName);
	
	void loadData();

	virtual void Resize(int Width,int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	Shader* myTestShader = NULL;;
	Camera* myTestCamera = NULL;
	Cube* myTestCube = NULL;
	
};