#pragma once
#include "Block.h"
#include "WorldConstants.h"

class Chunk
{
public:
	Chunk(std::shared_ptr<mte::Shader> shader, std::shared_ptr<Camera> camera);

	void draw();
private:
	Cube* _blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];
};
