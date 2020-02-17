#pragma once

#include"Scene.h"

#include <vector>
#include <iostream>

class SceneManager
{
public:
	SceneManager();

	void update(float dt);

	void addScene(Scene* newScene) { _scenes.push_back(newScene); }

private:


	std::vector<Scene*> _scenes;


};