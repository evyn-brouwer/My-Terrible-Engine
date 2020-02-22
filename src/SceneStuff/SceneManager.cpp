#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	for (unsigned i = 0; i < _scenes.size(); i++)
		delete _scenes[i];
}

void SceneManager::update(float dt)
{
	bool sceneRan = false;
	for (auto x : _scenes) {
		if (x->active) {
			if (x->changeScene) {
				if (x->newSceneName != "") {
					for (unsigned i = 0; i < _scenes.size(); i++) {
						if (_scenes[i]->_sceneName == x->newSceneName) {
							if (x != _scenes[i]) {
								_scenes[i]->active = true;
								_scenes[i]->update(dt);
								sceneRan = true;
							}
							else
							{
								std::cout << x->_sceneName << " is trying to swap to itself!" << std::endl;
							}
						}
						else if (i==_scenes.size()) {
							std::cout << "There is no " << x->newSceneName << " Scene!"<<std::endl;
						}
					}
						
					 
				}
				else {
					x->changeScene = false;
					std::cout << x->_sceneName << " wants to change scene, but doesn't know to what scene!" << std::endl;
				}
				x->active = false;
				x->newSceneName = "";
			}
			else {
				x->update(dt);
				if (sceneRan) {
					for(auto y : _scenes)
						if (y->active) {
							std::cout << y->_sceneName << " and " << x->_sceneName << " are both active at the same time!" << std::endl;
							break;
						}
				}
				sceneRan = true;
			}
				
		}
	}
	if (!sceneRan)
		std::cout<<"No scene is active!"<<std::endl;
}
