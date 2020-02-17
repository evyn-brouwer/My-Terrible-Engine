#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include<iostream>

#include "SceneStuff/SceneManager.h"

#include "SceneStuff/MenuScene.h"

class Game
{
public:
	Game(std::string gameName,GLuint width,GLuint height);

	~Game();

	void init();
	void runGame();

	void Resize(GLuint width, GLuint height);
private:

	GLuint _width, _height;
	std::string _gameName;

	GLFWwindow* _gameWindow;

	SceneManager* _sceneManager;
};