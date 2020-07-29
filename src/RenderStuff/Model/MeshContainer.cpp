#include "MeshContainer.h"

mte::MeshContainer::MeshContainer(std::string meshTag, std::shared_ptr<Camera> camera, std::shared_ptr<mte::Shader> shader, std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::TextureContainer> diffuse, std::shared_ptr<mte::TextureContainer> specular, std::shared_ptr<mte::TextureContainer> emission)
	: _camera(camera), _mesh(mesh), _shader(shader), _meshTag(meshTag),_diffuse(diffuse),_specular(specular),_emission(emission)
{
}

void mte::MeshContainer::draw()
{
	if (_active) {
		_shader->Bind();
		_shader->SetUniform("a_ViewProjection", _camera->GetViewProjection());
		_shader->SetUniform("a_Model", _tranform._worldTransformMat);
		if (_shader->_lightCubes.size()) { 
			_shader->SetUniform("light.position", _shader->_lightCubes[0]->_pos);
			_shader->SetUniform("light.diffuse", _shader->_lightCubes[0]->_diffuse);
			_shader->SetUniform("light.specular", _shader->_lightCubes[0]->_specular);
			_shader->SetUniform("light.ambient", _shader->_lightCubes[0]->_ambient);
			_shader->SetUniform("light.constant", _shader->_lightCubes[0]->_constant);
			_shader->SetUniform("light.linear", _shader->_lightCubes[0]->_linear);
			_shader->SetUniform("light.quadratic", _shader->_lightCubes[0]->_quadratic);
		}
		if (_camera != nullptr) {
			_shader->SetUniform("viewPos", _camera->GetPosition());
		}
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _diffuse->_texture);
		_shader->SetUniform("material.diffuse", 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, _specular->_texture);
		_shader->SetUniform("material.specular", 1);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, _emission->_texture);
		_shader->SetUniform("material.emission", 2);
		
		_shader->SetUniform("material.shininess", 32.0f);
		_mesh->draw();
	}
}

void mte::MeshContainer::update(float dt)
{
	if(_active)
		_tranform.update();
}
