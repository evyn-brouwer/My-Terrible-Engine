#pragma once
#include "Scene.h"
#include <iostream>
#include <memory>
#include <stb_image.h>

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Model/Mesh.h"
#include "RenderStuff/Camera.h"

class TestScene : public mte::Scene
{
public:
	TestScene(GLFWwindow* window, std::string sceneName);

	void loadData();

	virtual void Resize(int Width, int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	std::shared_ptr<mte::Shader> _meshShader;
	std::shared_ptr<mte::Mesh> _testMesh;
	std::shared_ptr<Camera> _myTestCamera;

};