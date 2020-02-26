#include "Scene.h"

Scene::Scene(GLFWwindow* window, std::string sceneName)
	:_gameWindow(window),_sceneName(sceneName)
{
}

void Scene::update(float dt)
{
	
	virtualUpdate(dt);
}
