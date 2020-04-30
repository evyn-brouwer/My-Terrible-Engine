#include "Cube.h"

Cube::Cube(std::shared_ptr<mte::Shader> shader, std::shared_ptr<Camera> camera, glm::vec3 position)
	: _shader(shader),_camera(camera),_position(position)
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
	_transform._position->x = _position.x;
	_transform._position->y = _position.y;
	_transform._position->z = _position.z;
	_transform.update();

	_shader->Bind();
	_shader->SetUniform("a_ModelViewProjection", _camera->GetViewProjection() * *_transform._transformMat);
	for (unsigned i = 0; i < 6; i++)
		_faces[i].draw();
}
