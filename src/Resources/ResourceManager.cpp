#include "ResourceManager.h"



std::vector<std::shared_ptr<mte::Shader>> mte::ResourceManager::_shaders;

std::shared_ptr<mte::Shader> mte::ResourceManager::createShader(std::string shaderName, std::string vsSource, std::string fsSource)
{
	for (auto x : _shaders) {
		if (x->_shaderName==shaderName) {
			return x;
		}
	}
	std::shared_ptr<mte::Shader> tempShader = std::make_shared<mte::Shader>(shaderName, vsSource, fsSource);
	_shaders.push_back(tempShader);
	return tempShader;
}
