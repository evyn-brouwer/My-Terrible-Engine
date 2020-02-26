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
	
	std::string _sceneName = "";

	bool _changeScene = false;
	std::string _newSceneName = "";

	GLFWwindow* _gameWindow;
	
	virtual void Resize(int width,int height)=0;

private:

	

	virtual void virtualUpdate(float dt) = 0;
};