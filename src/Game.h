#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include<iostream>
#include <memory>

#include "SceneStuff/SceneManager.h"
#include "Logging/Logger.h"

#include "SceneStuff/MenuScene.h"
#include "SceneStuff/TestScene.h" 



namespace mte {

	class Game
	{
	public:
		Game(std::string gameName, GLuint width, GLuint height);

		~Game();


		void runGame();

		void Resize(GLuint width, GLuint height);

		InputHandler _input;
		Logger _logger;
	private:
		bool init();


		
		GLint _width, _height;
		std::string _gameName;

		GLFWwindow* _gameWindow;

		std::shared_ptr<SceneManager> _sceneManager;
	};
}