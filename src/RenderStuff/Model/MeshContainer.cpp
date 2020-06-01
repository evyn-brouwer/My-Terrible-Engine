#include "MeshContainer.h"

mte::MeshContainer::MeshContainer(std::string meshTag, std::shared_ptr<Camera> camera, std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::Shader> shader)
	:_camera(camera),_mesh(mesh),_shader(shader),_meshTag(meshTag)
{

}

void mte::MeshContainer::draw()
{
	if (_active) {
		_shader->Bind();
		_shader->SetUniform("a_ViewProjection", _camera->GetViewProjection());
		_shader->SetUniform("a_Model", _tranform._worldTransformMat);
		if (_shader->_lightCubes.size()) { 
			_shader->SetUniform("lightPos", _shader->_lightCubes[0]->_pos);
			_shader->SetUniform("lightCol", _shader->_lightCubes[0]->_colour);
		}
		if (_camera != nullptr) {
			_shader->SetUniform("viewPos", _camera->GetPosition());
		}
		_mesh->draw();
	}
}

void mte::MeshContainer::update(float dt)
{
	if(_active)
		_tranform.update();
}
