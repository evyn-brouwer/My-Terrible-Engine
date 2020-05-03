#include "TestScene.h"

TestScene::TestScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void TestScene::loadData()
{


	_myTestCamera = std::make_shared<Camera>();
	_myTestCamera->SetPosition(glm::vec3(5, 0, 5));
	_myTestCamera->LookAt(glm::vec3(0));
	_myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1600.0f / 900.0f, 0.01f, 1000.0f);


	_testModel = std::make_shared<mte::Model>();
	_testModel->addMesh(std::make_shared<mte::MeshContainer>("box0",_myTestCamera, _resources.createMesh("Assets/Meshes/test.obj", "Test Mesh", "Assets/Textures/container.jpg", "Test Texture"), _resources.createShader("meshShader", "./Assets/Shaders/meshShader.vs", "./Assets/Shaders/meshShader.fs")));
	_testModel->addMesh(std::make_shared<mte::MeshContainer>("box1",_myTestCamera, _resources.createMesh("Assets/Meshes/test.obj", "Test Mesh", "Assets/Textures/container.jpg", "Test Texture"), _resources.createShader("meshShader", "./Assets/Shaders/meshShader.vs", "./Assets/Shaders/meshShader.fs")));

}

void TestScene::Resize(int Width, int Height)
{
	_myTestCamera->Projection = glm::perspective(glm::radians(60.0f), (float)Width / (float)Height, 0.01f, 1000.0f);
}

void TestScene::virtualUpdate(float dt)
{

	glm::vec3 movement = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	float speed = 1.0f;
	float rotSpeed = 1.0f;
	if (_input.getKeyState(GLFW_KEY_W))
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


	_myTestCamera->Rotate(rotation);
	_myTestCamera->Move(movement);
	
	std::shared_ptr<mte::MeshContainer> tempModel = _testModel->getMesh("box1");
	if (tempModel != NULL) {
		tempModel->_tranform.translate(glm::vec3(0,0.05,0));
	}

	_testModel->update(dt);
	_testModel->draw();

}
