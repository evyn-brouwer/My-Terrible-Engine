#include "Game.h"

Game::Game(std::string gameName, GLuint width, GLuint height)
	: _gameName(gameName),_width(width),_height(height)
{
	_gameWindow = NULL;
	_sceneManager = new SceneManager();
}

Game::~Game()
{
	delete _sceneManager;
}

void Game::init()
{

	// Initialize GLFW
	if (glfwInit() == GLFW_FALSE) {
		std::cout << "Failed to initialize Glad" << std::endl;
	}
	_gameWindow = glfwCreateWindow(_width, _height, _gameName.c_str(), nullptr, nullptr);


	glfwMakeContextCurrent(_gameWindow);

	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0) {
		std::cout << "Failed to initialize Glad" << std::endl;
	}

	// Display our GPU and OpenGL version
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;

	MenuScene* menuScene = new MenuScene(_gameWindow,"MenuScene");
	menuScene->active = true;
	_sceneManager->addScene(menuScene);

	std::cout << "Game has been initialized!" << std::endl;
}

void Game::runGame()
{

	while (!glfwWindowShouldClose(_gameWindow)) {
		glfwPollEvents();


		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(_gameWindow);
	}

}
