#include "MenuScene.h"
#include <GLM\include\GLM\gtc\matrix_transform.hpp>

MenuScene::MenuScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void MenuScene::loadData()
{
	myTestCamera = std::make_shared<Camera>();
	myTestCamera->SetPosition(glm::vec3(5, 5, 5));
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1600.0f/900.0f, 0.01f, 1000.0f);
		
	meshShader = _resources.createShader("meshShader", "./Assets/Shaders/meshShader.vs", "./Assets/Shaders/meshShader.fs");

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
	if(_input.getKeyState(GLFW_KEY_W))
		movement.z -= speed * dt;
	if (_input.getKeyState(GLFW_KEY_S))
		movement.z += speed * dt;
	if (_input.getKeyState(GLFW_KEY_A))
		movement.x -= speed * dt;
	if (_input.getKeyState(GLFW_KEY_D))
		movement.x += speed * dt;
	if (_input.getKeyState(GLFW_KEY_SPACE))
		movement.y += speed * dt;
	if (_input.getKeyState(GLFW_KEY_LEFT_CONTROL))
		movement.y -= speed * dt;

	if (_input.getKeyState(GLFW_KEY_Q))
		rotation.z -= rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_E))
		rotation.z += rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_UP))
		rotation.x -= rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_DOWN))
		rotation.x += rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_LEFT))
		rotation.y -= rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_RIGHT))
		rotation.y += rotSpeed * dt;
	if (_input.getKeyState(GLFW_KEY_P)) {
		_changeScene = true;
		_newSceneName = "TestScene";
	}
		

	myTestCamera->Rotate(rotation);
	myTestCamera->Move(movement);
	
	
}
