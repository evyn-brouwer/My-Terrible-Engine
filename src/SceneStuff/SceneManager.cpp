#include "SceneManager.h"

SceneManager::SceneManager()
:_currentScene(NULL)
{
}

void SceneManager::update(float dt)
{
	if (_currentScene != NULL) {//if there is a scene active
		if (!_currentScene->changeScene) {//if the current scene doesn't want to change
			_currentScene->update(dt);//update the scene
		}
		else {//if the current scene wants to change
			if (_currentScene->_newSceneName != _currentScene->_sceneName) {//if the scenes to change to is not this scene
				if (_currentScene->_newSceneName!="") {
					for (unsigned i = 0; i < _scenes.size(); i++) {//check all the scenes
						if (_currentScene->_newSceneName == _scenes[i]->_sceneName) {
							_currentScene->_newSceneName = "";
							_currentScene->changeScene = false;
							_currentScene = _scenes[i];
							_currentScene->changeScene = false;
							_currentScene->_newSceneName = "";
							_currentScene->update(dt);
						}
						else if (i == _scenes.size()) {
							_currentScene->update(dt);
							std::cout << "There is no " << _currentScene->_newSceneName << " Scene!" << std::endl;
						}
					}
				
				}
				else {
					std::cout << _currentScene->_sceneName << " wants to change scene, but doesn't know to what scene!" << std::endl;
					_currentScene->changeScene = false;
				}
			}
			else {
				std::cout << _currentScene->_sceneName << " is trying to swap to itself!" << std::endl;
				_currentScene->changeScene = false;
				_currentScene->_newSceneName = "";
			}
			
		}
	}
	else {//if the current scene is NULL
		std::cout << "There is no active Scene!" <<std::endl;
	}
}
