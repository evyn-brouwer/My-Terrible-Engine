#include "InputHandler.h"

void mte::InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		_keylist[key] = true;
	else if (action == GLFW_RELEASE)
		_keylist[key] = false;
}

void mte::InputHandler::cursor_postion_callback(GLFWwindow* window, double xPos, double yPos)
{
	_mouseX = xPos;
	_mouseY = yPos;
}

void mte::InputHandler::cursorMode(GLFWwindow* window, int mode)
{
	glfwSetInputMode(window, GLFW_CURSOR, mode);
}

bool mte::InputHandler::getKeyState(int key)
{
	return _keylist[key];
}

glm::vec2 mte::InputHandler::getMousePos()
{
	return glm::vec2(_mouseX,_mouseY);
}

bool mte::InputHandler::getMouseButtonState(int button)
{
	return _mouseButtonList[button];
}

double mte::InputHandler::_mouseX = 0.0f;
double mte::InputHandler::_mouseY = 0.0f;

bool mte::InputHandler::_keylist[1024];
bool mte::InputHandler::_mouseButtonList[32];