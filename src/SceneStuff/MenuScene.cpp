#include "MenuScene.h"
#include <GLM\include\GLM\gtc\matrix_transform.hpp>

MenuScene::MenuScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void MenuScene::loadData()
{
	myTestShader = std::make_shared<Shader>();
	myTestShader->Load("./Assets/Shaders/testShader.vs","./Assets/Shaders/testShader.fs");


	myTestCamera = std::make_shared<Camera>();
	myTestCamera->SetPosition(glm::vec3(5, 5, 5));
	myTestCamera->LookAt(glm::vec3(0));
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1600.0f/900.0f, 0.01f, 1000.0f);
	
	myTestCube = std::make_shared<Cube>(myTestShader,myTestCamera,glm::vec3(0,0,0));

	mytestChunk = std::make_shared<Chunk>(myTestShader, myTestCamera);
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
	if (glfwGetKey(_gameWindow, GLFW_KEY_P) == GLFW_PRESS) {
		_changeScene = true;
		_newSceneName = "TestScene";
	}
		

	myTestCamera->Rotate(rotation);
	myTestCamera->Move(movement);

	//myTestCube->_transform._transformMat = myTestCube->_transform.rotate(glm::vec3(1.0f, 0.0, 0.0), 45.0f * dt);

	myTestCube->draw();

	mytestChunk->draw();
}
