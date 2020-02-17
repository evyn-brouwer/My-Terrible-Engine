#include "MenuScene.h"

MenuScene::MenuScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void MenuScene::loadData()
{
	myTestShader = new Shader();
	myTestShader->Load("./Assets/Shaders/testShader.vs","./Assets/Shaders/testShader.fs");

	Vertex vertices[4] = {
		// Position Color
		// x y z r g b a
		{{ -0.5f, -0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f }},
		{{ 0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f, 0.0f, 1.0f }},
		{{ -0.5f, 0.5f, 0.0f }, { 1.0f, 0.0f, 1.0f, 1.0f }},
		{{ 0.5f, 0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f }},
	};
	// Create our 6 indices
	uint32_t indices[6] = {
	0, 1, 2,
	2, 1, 3
	};
	myTestMesh = new Mesh(vertices, 4, indices, 6);
}

void MenuScene::virtualUpdate(float dt)
{
	myTestShader->Bind();
	myTestMesh->Draw();

}
