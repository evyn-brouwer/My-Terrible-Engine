#include "Cube.h"

Cube::Cube(Shader* shader, Camera* camera)
	: _shader(shader),_camera(camera)
{
	_faces[0] = QuadRenderer(glm::vec3(0.0f), glm::vec3(1, 0, 0));
	_faces[1] = QuadRenderer(glm::vec3(0.0f), glm::vec3(-1, 0, 0));
	_faces[2] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 0, 1));
	_faces[3] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 0, -1));
	_faces[4] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, 1, 0));
	_faces[5] = QuadRenderer(glm::vec3(0.0f), glm::vec3(0, -1, 0));
}

void Cube::draw()
{
	_shader->Bind();
	_shader->SetUniform("a_ModelViewProjection", _camera->GetViewProjection() * _transform._transformMat);
	for (unsigned i = 0; i < 6; i++)
		_faces[i].draw();
}
