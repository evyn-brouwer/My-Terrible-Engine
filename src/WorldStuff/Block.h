#pragma once
#include "RenderStuff/Cube.h"
#include "RenderStuff/Model/Mesh.h"

class Block
{
public:
	Block(std::shared_ptr<mte::Shader> shader, std::shared_ptr<Camera> camera, glm::vec3 position,std::string name,unsigned id);
	void update(float dt);
	void draw();
	//virtual void virtualUpdate(float dt) = 0;

private:
	std::shared_ptr<Cube> _cube = NULL;
	std::shared_ptr<mte::Mesh> _mesh = NULL;
	bool _cubeNotMesh = true;
	unsigned _blockId = 0;
	std::string _blockName = "";
	glm::vec3 _position;
};