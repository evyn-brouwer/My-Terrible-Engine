#pragma once

#include "Scene.h"

#include "Resources/ResourceManager.h"

#include "RenderStuff/Model/Mesh.h"

#include <glm/gtc/quaternion.hpp>

#include <memory>

#include <stb_image.h>

class MenuScene : public mte::Scene
{
public:
	MenuScene(GLFWwindow* window, std::string sceneName);
	
	void loadData();

	virtual void Resize(int Width,int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	std::shared_ptr<Camera> myTestCamera = NULL;
	std::shared_ptr<mte::Shader> meshShader;


	mte::ResourceManager _resources;
};