#pragma once

#include"Scene.h"

#include <vector>
#include <iostream>

class SceneManager
{
public:
	SceneManager();
	void update(float dt);

	void addScene(std::shared_ptr<Scene> newScene) { _scenes.push_back(newScene); }

	std::shared_ptr<Scene> _currentScene;
	std::vector<std::shared_ptr<Scene>> _scenes;
private:


	


};