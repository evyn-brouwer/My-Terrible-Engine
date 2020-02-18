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

	myTestTransform = new Transform();

	myTestCamera = new Camera();
	myTestCamera->SetPosition(glm::vec3(5, 5, 5));
	myTestCamera->LookAt(glm::vec3(0));
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1.0f, 0.01f, 1000.0f);
	
	myTestCube = new Cube(myTestShader,myTestCamera,glm::vec3(0,0,0));
	//myTestQuad = new QuadRenderer(glm::vec3(0,0,0),glm::vec3(1,0,0));
	//
	//yoinks[0] = QuadRenderer(glm::vec3(0.0f), glm::vec3(1, 0, 0));
	//yoinks[1] = QuadRenderer(glm::vec3(0.0f), glm::vec3(-1, 0, 0));
	//yoinks[2] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 0, 1));
	//yoinks[3] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 0, -1));
	//yoinks[4] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 1, 0));
	//yoinks[5] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, -1, 0));
}

void MenuScene::Resize(int Width, int Height)
{
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), Width / (float)Height, 0.01f, 1000.0f);
}

void MenuScene::virtualUpdate(float dt)
{
	glm::vec3 movement = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	float speed = 1.0f;
	float rotSpeed = 1.0f;

	if (glfwGetKey(_gameWindow, GLFW_KEY_W) == GLFW_PRESS)
		movement.z -= speed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_S) == GLFW_PRESS)
		movement.z += speed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_A) == GLFW_PRESS)
		movement.x -= speed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_D) == GLFW_PRESS)
		movement.x += speed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
		movement.y += speed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		movement.y -= speed * dt;

	if (glfwGetKey(_gameWindow, GLFW_KEY_Q) == GLFW_PRESS)
		rotation.z -= rotSpeed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_E) == GLFW_PRESS)
		rotation.z += rotSpeed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_UP) == GLFW_PRESS)
		rotation.x -= rotSpeed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
		rotation.x += rotSpeed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
		rotation.y -= rotSpeed * dt;
	if (glfwGetKey(_gameWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
		rotation.y += rotSpeed * dt;

	myTestCamera->Rotate(rotation);
	myTestCamera->Move(movement);

	myTestCube->_transform._transformMat = myTestCube->_transform.rotate(glm::vec3(1.0f, 0.0, 0.0), 45.0f * dt);
	//myTestTransform->_transformMat=myTestTransform->rotate(glm::vec3(1.0f,0.0,0.0),45.0f*dt);
	//myTestTransform->update();

	//myTestShader->Bind();
	//myTestShader->SetUniform("a_ModelViewProjection", myTestCamera->GetViewProjection() * myTestTransform->_transformMat);
	//myTestMesh->Draw();
	//myTestQuad->draw();
	//myTestShader->SetUniform("a_ModelViewProjection", myTestCamera->GetViewProjection());

	myTestCube->draw();
	//yoinks[0].draw();
	//yoinks[1].draw();
	//yoinks[2].draw();
	//yoinks[3].draw();
	//yoinks[4].draw();
	//yoinks[5].draw();

}
