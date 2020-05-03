#include "MeshContainer.h"

mte::MeshContainer::MeshContainer(std::string meshTag, std::shared_ptr<Camera> camera, std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::Shader> shader)
	:_camera(camera),_mesh(mesh),_shader(shader),_meshTag(meshTag)
{

}

void mte::MeshContainer::draw()
{
	if (_active) {
		_shader->Bind();
		_shader->SetUniform("a_ModelViewProjection", _camera->GetViewProjection() * _tranform._worldTransformMat);
		_mesh->draw();
	}
}

void mte::MeshContainer::update(float dt)
{
	if(_active)
		_tranform.update();
}
