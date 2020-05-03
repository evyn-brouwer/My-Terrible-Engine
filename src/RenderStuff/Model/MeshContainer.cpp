#include "MeshContainer.h"

mte::MeshContainer::MeshContainer(std::shared_ptr<Camera> camera, std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::Shader> shader)
	:_camera(camera),_mesh(mesh),_shader(shader)
{

}

void mte::MeshContainer::draw()
{
	_shader->Bind();
	_shader->SetUniform("a_ModelViewProjection",_camera->GetViewProjection() *_tranform._worldTransformMat);
	_mesh->draw();
}

void mte::MeshContainer::update(float dt)
{
	_tranform.update();
}
