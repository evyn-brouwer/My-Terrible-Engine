#pragma once

#include "RenderStuff/Mesh/Vertex.h"

#include <memory>
#include <vector>

namespace mte {

	class Mesh
	{
	public:
		Mesh(std::vector<Vertex> vertices,size_t numVerts,std::vector<uint32_t> indices,size_t numIndices);
		~Mesh();

		void Draw();

	private:

		GLuint _VAO;
		GLuint _buffers[2];
		size_t _vertexCount, _indexCount;

	};


}