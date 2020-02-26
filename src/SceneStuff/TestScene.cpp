#include "TestScene.h"

TestScene::TestScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{
	loadData();
}

void TestScene::loadData()
{
}

void TestScene::Resize(int Width, int Height)
{
}

void TestScene::virtualUpdate(float dt)
{
	std::cout << "Gottem"<<std::endl;
}
