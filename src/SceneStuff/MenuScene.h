#pragma once

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene(GLFWwindow* window, std::string sceneName);



private:

	virtual void virtualUpdate(float dt)override;


};