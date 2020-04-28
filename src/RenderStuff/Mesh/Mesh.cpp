#include "Mesh.h"


mte::Mesh::Mesh(std::vector<Vertex> vertices, size_t numVerts, std::vector<uint32_t> indices, size_t numIndices)
{
	_vertexCount = numVerts;
	_indexCount = numIndices;

	// create and bind the vertex array
	glCreateVertexArrays(1,&_VAO);
	glBindVertexArray(_VAO);

	//create two buffers for vertex data
	glCreateBuffers(2,_buffers);

	//bind the vertex data
	glBindBuffer(GL_ARRAY_BUFFER,_buffers[0]);
	glBufferData(GL_ARRAY_BUFFER,_vertexCount * sizeof(Vertex),&vertices,GL_STATIC_DRAW);

	//Bind and buffer our index data
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, _indexCount * sizeof(uint32_t), &indices, GL_STATIC_DRAW);

	Vertex* vert = nullptr;

}

mte::Mesh::~Mesh()
{
}

void mte::Mesh::Draw()
{
}
