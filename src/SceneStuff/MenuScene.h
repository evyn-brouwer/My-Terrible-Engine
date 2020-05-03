#pragma once

#include "Scene.h"
#include "RenderStuff/Cube.h"
#include "WorldStuff/Block.h"
#include "WorldStuff/Chunk.h"

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

	std::shared_ptr<mte::Shader> myTestShader = NULL;;
	std::shared_ptr<Camera> myTestCamera = NULL;
	std::shared_ptr<Cube> myTestCube = NULL;
	std::shared_ptr<Chunk> mytestChunk = NULL;

	std::shared_ptr<mte::Shader> meshShader;


	mte::ResourceManager _resources;
};