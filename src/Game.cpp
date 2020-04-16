#include "Game.h"


void GlfwWindowResizedCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	mte::Game* myGame = (mte::Game*)glfwGetWindowUserPointer(window);
	if (myGame) {
		myGame->Resize(width, height);
	}
}

void GLFW_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	mte::Game* myGame = (mte::Game*)glfwGetWindowUserPointer(window);
	if (myGame) {
		myGame->_input.key_callback(window,key,scancode,action,mods);
	}

}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	mte::Game* myGame = (mte::Game*)glfwGetWindowUserPointer(window);
	if (myGame) {
		myGame->_input.cursor_postion_callback(window,xpos,ypos);
	}
}

mte::Game::Game(std::string gameName, GLuint width, GLuint height)
	: _gameName(gameName),_width(width),_height(height)
{
	_gameWindow = NULL;
	_sceneManager = std::make_shared<SceneManager>();
	if (!init())
		glfwTerminate();
}

mte::Game::~Game()
{
	glfwTerminate();
}

bool mte::Game::init()
{

	// Initialize GLFW
	if (!glfwInit() ) {
		std::cout << "Failed to initialize Glad" << std::endl;
		return false;
	}
	_gameWindow = glfwCreateWindow(_width, _height, _gameName.c_str(), nullptr, nullptr);

	if (!_gameWindow) {
		std::cout << "Failed to create Game Window" << std::endl;
		return false;
	}
	glfwSetWindowSizeCallback(_gameWindow, GlfwWindowResizedCallback);
	glfwSetKeyCallback(_gameWindow, GLFW_key_callback);
	glfwSetCursorPosCallback(_gameWindow, cursor_position_callback);


	glfwMakeContextCurrent(_gameWindow);

	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0) {
		std::cout << "Failed to initialize Glad" << std::endl;
		return false;
	}

	// Display our GPU and OpenGL version
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;

	std::shared_ptr<MenuScene> menuScene = std::make_shared<MenuScene>(_gameWindow,"MenuScene");
	_sceneManager->addScene(menuScene);
	_sceneManager->_currentScene = menuScene;

	std::shared_ptr<TestScene> testScene = std::make_shared<TestScene>(_gameWindow, "TestScene");
	_sceneManager->addScene(testScene);

	glEnable(GL_DEPTH_TEST);


	std::cout << "Game has been initialized!" << std::endl;
	return true;
}


void mte::Game::runGame()
{
	static float prevFrame = (float)glfwGetTime();
	while (!glfwWindowShouldClose(_gameWindow)) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

		

		float thisFrame = (float)glfwGetTime();
		float deltaTime = thisFrame - prevFrame;
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_sceneManager->update(deltaTime);

		prevFrame = thisFrame;
		

		glfwSwapBuffers(_gameWindow);

		glfwPollEvents(); 
		_logger.printErrors();
	}

}

void mte::Game::Resize(GLuint width, GLuint height)
{
	_width = width;
	_height = height;
	for (auto x : _sceneManager->_scenes)
		x->Resize(width,height);
}
