#include "Block.h"

Block::Block(std::shared_ptr<mte::Shader> shader, std::shared_ptr<Camera> camera, glm::vec3 position, std::string name, unsigned id)
	: _cube(std::make_shared<Cube>(shader,camera,position)),_blockId(id),_blockName(name)
{
}

void Block::update(float dt)
{
	//virtualUpdate(dt);
	
}

void Block::draw()
{
	if (_cubeNotMesh)
		_cube->draw();
	else
		_mesh->Draw();
}
