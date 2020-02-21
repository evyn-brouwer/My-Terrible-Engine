#pragma once
#include "RenderStuff/Cube.h"
#include "RenderStuff/Mesh.h"

class Block
{
public:
	Block(Shader* shader, Camera* camera, glm::vec3 position,std::string name,unsigned id);
	void update(float dt);
	void draw();
	//virtual void virtualUpdate(float dt) = 0;

private:
	Cube* _cube = NULL;
	Mesh* _mesh = NULL;
	bool _cubeNotMesh = true;
	unsigned _blockId = 0;
	std::string _blockName = "";
	glm::vec3 _position;
};