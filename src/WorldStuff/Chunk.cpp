#include "Chunk.h"

Chunk::Chunk(std::shared_ptr<Shader> shader, std::shared_ptr<Camera> camera)
{
	for (unsigned i = 0; i < CHUNK_SIZE; i++)
		for (unsigned n = 0; n < CHUNK_SIZE; n++)
			for (unsigned p = 0; p < CHUNK_SIZE; p++)
				_blocks[i][n][p]=  new Cube(shader,camera,glm::vec3(i,n,p));
}

void Chunk::draw()
{
	for (unsigned i = 0; i < CHUNK_SIZE; i++)
		for (unsigned n = 0; n < CHUNK_SIZE; n++)
			for (unsigned p = 0; p < CHUNK_SIZE; p++)
				_blocks[i][n][p]->draw();
}
