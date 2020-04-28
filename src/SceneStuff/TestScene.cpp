#include "TestScene.h"

TestScene::TestScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void TestScene::loadData()
{
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void TestScene::Resize(int Width, int Height)
{
}

void TestScene::virtualUpdate(float dt)
{
	 

	
	




}
