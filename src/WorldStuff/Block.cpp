#include "Block.h"

Block::Block(Shader* shader, Camera* camera, glm::vec3 position, std::string name, unsigned id)
	: _cube(&Cube(shader,camera,position)),_blockId(id),_blockName(name)
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
