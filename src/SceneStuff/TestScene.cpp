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
	_myTestCamera->Projection = glm::perspective(glm::radians(60.0f), 1600.0f / 900.0f, 0.01f, 1000.0f);


	_testModel = std::make_shared<mte::Model>();
	_testModel->addMesh(std::make_shared<mte::MeshContainer>("box0",_myTestCamera, _resources.createShader("testMeshShader", "./Assets/Shaders/testShader.vs", "./Assets/Shaders/testShader.fs"), _resources.createMesh("Assets/Meshes/test.obj", "Test Mesh"), _resources.createTexture( "Test Texture", "Assets/Textures/meme.jpg"), _resources.createTexture(), _resources.createTexture()));
	_testModel->addMesh(std::make_shared<mte::MeshContainer>("box1",_myTestCamera, _resources.createShader("meshShader", "./Assets/Shaders/meshShader.vs", "./Assets/Shaders/meshShader.fs"),_resources.createMesh("Assets/Meshes/box.obj", "Box Mesh"), _resources.createTexture(), _resources.createTexture("Specular Test", "Assets/Textures/Specular_test_map.png"), _resources.createTexture()));

	std::shared_ptr<mte::LightCube> tempLight = std::make_shared<mte::LightCube>(glm::vec3(5, 1, 6), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1), glm::vec3(1, 1, 1));
	_resources.getShader("meshShader")->_lightCubes.push_back(tempLight);

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
	

	_resources.drawLightCubes(_myTestCamera);
	_resources.updateDrawCubes();




	std::shared_ptr<mte::MeshContainer> tempModel = _testModel->getMesh("box1");
	if (tempModel != NULL) {
		tempModel->_tranform.translate(glm::vec3(0,0.01*dt,0));
	}

	_testModel->update(dt);
	_testModel->draw();

	//std::shared_ptr<mte::Shader> _tempShader = _resources.getShader("meshShader");
	//
	//_tempShader->_lightCubes[0]->_diffuse.x = sin(glfwGetTime() * 2.0f);
	//_tempShader->_lightCubes[0]->_diffuse.y = sin(glfwGetTime() * 0.7f);
	//_tempShader->_lightCubes[0]->_diffuse.z = sin(glfwGetTime() * 1.3f);
}
