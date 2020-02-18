#pragma once

#include "Scene.h"
#include "ShaderStuff/Shader.h"
#include "RenderStuff/Mesh.h"
#include "RenderStuff/Camera.h"
#include "RenderStuff/Transform.h"
#include "RenderStuff/QuadRenderer.h"

#include <glm/gtc/quaternion.hpp>

class MenuScene : public Scene
{
public:
	MenuScene(GLFWwindow* window, std::string sceneName);
	
	void loadData();

	virtual void Resize(int Width,int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	Shader* myTestShader = NULL;
	Mesh* myTestMesh = NULL;
	Transform* myTestTransform = NULL;
	Camera* myTestCamera = NULL;
	QuadRenderer* myTestQuad = NULL;
	QuadRenderer yoinks[6];
};