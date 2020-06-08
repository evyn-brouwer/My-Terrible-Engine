#include "ResourceManager.h"



std::vector<std::shared_ptr<mte::Shader>> mte::ResourceManager::_shaders;
std::vector<std::shared_ptr<mte::Mesh>> mte::ResourceManager::_meshes;


mte::ResourceManager::ResourceManager()
{
	_lightCubeShader = createShader("lightCubeShader", "./Assets/Shaders/lightCubeShader.vs", "./Assets/Shaders/lightCubeShader.fs");
}

std::shared_ptr<mte::Shader> mte::ResourceManager::createShader(std::string shaderName, std::string vsSource, std::string fsSource)
{
	for (auto x : _shaders) {
		if (x->_shaderName==shaderName) {
			return x;
		}
	}
	std::shared_ptr<mte::Shader> tempShader = std::make_shared<mte::Shader>(shaderName, vsSource, fsSource);
	tempShader->_lightCubeShader = _lightCubeShader;
	_shaders.push_back(tempShader);
	return tempShader;
}

std::shared_ptr<mte::Shader> mte::ResourceManager::getShader(std::string shaderName)
{
	for (auto x : _shaders) {
		if (x->_shaderName == shaderName) {
			return x;
		}
	}
	return NULL;
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

//std::shared_ptr<mte::TextureContainer> mte::ResourceManager::createTexture(std::string textureName, std::string textureFile)
//{
//	for (auto x : _textures) {
//		if (x->_textureName == textureName && x->_textureFile == textureFile) {
//			return x;
//		}
//	}
//	std::shared_ptr<mte::TextureContainer> tempTexture = std::make_shared<mte::TextureContainer>(textureName, textureFile);
//	_textures.push_back(tempTexture);
//	return tempTexture;
//}

void mte::ResourceManager::drawLightCubes(std::shared_ptr<Camera> camera)
{
	for (auto x : _shaders) {
		if(x->_shaderName!="lightCubeShader")
			x->drawCubes(camera);
	}
}

void mte::ResourceManager::updateDrawCubes()
{
	for (auto x : _shaders) {
		x->updateCubes();
	}
}
