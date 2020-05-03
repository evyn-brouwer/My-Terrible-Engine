#include "ResourceManager.h"



std::vector<std::shared_ptr<mte::Shader>> mte::ResourceManager::_shaders;
std::vector<std::shared_ptr<mte::Mesh>> mte::ResourceManager::_meshes;

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

std::shared_ptr<mte::Mesh> mte::ResourceManager::createMesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName)
{
	for (auto x : _meshes) {
		if (x->_meshName == meshName && x->_textureName == textureName) {
			return x;
		}
	}
	std::shared_ptr<mte::Mesh> tempMesh = std::make_shared<mte::Mesh>(meshFile, meshName, texturefile, textureName);
	_meshes.push_back(tempMesh);
	return tempMesh;
}
