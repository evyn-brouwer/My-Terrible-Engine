#include "MenuScene.h"
#include <GLM\include\GLM\gtc\matrix_transform.hpp>

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


	myTestCamera = new Camera();
	myTestCamera->SetPosition(glm::vec3(5, 5, 5));
	myTestCamera->LookAt(glm::vec3(0));
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1.0f, 0.01f, 1000.0f);
	
}

void MenuScene::virtualUpdate(float dt)
{
	myTestShader->Bind();
	myTestShader->SetUniform("a_ModelViewProjection", myTestCamera->GetViewProjection());
	myTestMesh->Draw();

}
