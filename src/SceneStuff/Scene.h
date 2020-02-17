#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include <string>

class Scene
{
public:
	Scene(GLFWwindow* window, std::string sceneName);

	void update(float dt);
	

	bool active = false;
	std::string _sceneName = "";

	bool changeScene = false;
	std::string newSceneName = "";
private:

	GLFWwindow* _gameWindow;

	virtual void virtualUpdate(float dt) = 0;
};