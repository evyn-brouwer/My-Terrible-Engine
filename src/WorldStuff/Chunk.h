#pragma once
#include "Block.h"
#include "WorldConstants.h"

class Chunk
{
public:
	Chunk();

private:
	Block* _blocks[CHUNK_VOLUME];
};
