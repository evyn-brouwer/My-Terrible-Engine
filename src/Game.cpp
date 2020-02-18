#include "Game.h"


void GlfwWindowResizedCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	
}

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
	_gameWindow = glfwCreateWindow(_width, _height, _gameName.c_str(), nullptr, nullptr)
		;
	glfwSetWindowSizeCallback(_gameWindow, GlfwWindowResizedCallback);

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

	glEnable(GL_DEPTH_TEST);


	std::cout << "Game has been initialized!" << std::endl;
}

void Game::runGame()
{
	static float prevFrame = (float)glfwGetTime();
	while (!glfwWindowShouldClose(_gameWindow)) {
		glfwPollEvents();

		float thisFrame = (float)glfwGetTime();
		float deltaTime = thisFrame - prevFrame;

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_sceneManager->update(deltaTime);

		prevFrame = thisFrame;
		

		glfwSwapBuffers(_gameWindow);
		
	}

}

void Game::Resize(GLuint width, GLuint height)
{
	_width = width;
	_height = height;
	for (auto x : _sceneManager->_scenes)
		x->Resize(width,height);
}
