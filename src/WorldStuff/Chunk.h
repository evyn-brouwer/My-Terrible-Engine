#pragma once
#include "Block.h"
#include "WorldConstants.h"

class Chunk
{
public:
	Chunk(Shader* shader, Camera* camera);

	void draw();
private:
	Cube* _blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
};
