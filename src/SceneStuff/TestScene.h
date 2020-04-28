#pragma once
#include "Scene.h"
#include <iostream>

class TestScene : public mte::Scene
{
public:
	TestScene(GLFWwindow* window, std::string sceneName);

	void loadData();

	virtual void Resize(int Width, int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	unsigned int VBO;

};