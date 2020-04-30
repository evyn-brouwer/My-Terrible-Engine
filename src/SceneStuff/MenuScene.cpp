#include "MenuScene.h"
#include <GLM\include\GLM\gtc\matrix_transform.hpp>

MenuScene::MenuScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void MenuScene::loadData()
{
	myTestShader = std::make_shared<mte::Shader>();
	myTestShader->Load("./Assets/Shaders/testShader.vs","./Assets/Shaders/testShader.fs");


	myTestCamera = std::make_shared<Camera>();
	myTestCamera->SetPosition(glm::vec3(5, 5, 5));
	myTestCamera->LookAt(glm::vec3(0));
	myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1600.0f/900.0f, 0.01f, 1000.0f);
	
	//myTestCube = std::make_shared<Cube>(myTestShader,myTestCamera,glm::vec3(0,0,0));

	//mytestChunk = std::make_shared<Chunk>(myTestShader, myTestCamera);

	_testMesh = std::make_shared<mte::Mesh>("Assets/Meshes/test.obj");
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

	//myTestCube->_transform._transformMat = myTestCube->_transform.rotate(glm::vec3(1.0f, 0.0, 0.0), 45.0f * dt);

	//myTestCube->draw();
	//
	//mytestChunk->draw();



	_testMesh->Draw();
}
