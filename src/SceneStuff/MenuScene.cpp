#include "MenuScene.h"

MenuScene::MenuScene(GLFWwindow* window, std::string sceneName)
	:Scene(window,sceneName)
{

}

void MenuScene::loadData()
{
	myTestShader = new Shader();
	myTestShader->Load("testShader.vs","testShader.fs");
}

void MenuScene::virtualUpdate(float dt)
{
	
}
