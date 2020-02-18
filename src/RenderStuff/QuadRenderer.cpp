#include "QuadRenderer.h"

QuadRenderer::QuadRenderer()
	:QuadRenderer(glm::vec3(0.0f),glm::vec3(0,1,0))
{
}

QuadRenderer::QuadRenderer(glm::vec3 Pos, glm::vec3 Dir)
	:_position(Pos),_direction(Dir)
{
	glCreateVertexArrays(1, &myVao);
	glBindVertexArray(myVao);

	glCreateBuffers(2, myBuffers);

	Vertex tempVerts[8] = {
		Vertex(glm::vec3(-0.5, 0.5, 0.5),glm::vec4(1.0f,0.0f,0.0f,1.0f)),//1
		Vertex(glm::vec3( 0.5, 0.5, 0.5),glm::vec4(0.0f,0.0f,1.0f,1.0f)),//2
		Vertex(glm::vec3(-0.5, 0.5,-0.5),glm::vec4(0.0f,0.0f,1.0f,1.0f)),//3
		Vertex(glm::vec3( 0.5, 0.5,-0.5),glm::vec4(1.0f,0.0f,0.0f,1.0f)),//4
		Vertex(glm::vec3(-0.5,-0.5,-0.5),glm::vec4(1.0f,0.0f,0.0f,1.0f)),//5
		Vertex(glm::vec3( 0.5,-0.5,-0.5),glm::vec4(0.0f,0.0f,1.0f,1.0f)),//6
		Vertex(glm::vec3(-0.5,-0.5, 0.5),glm::vec4(0.0f,0.0f,1.0f,1.0f)),//7
		Vertex(glm::vec3( 0.5,-0.5, 0.5),glm::vec4(1.0f,0.0f,0.0f,1.0f)) //8
	};

	Vertex vertices[4];

	if (Dir == glm::vec3(1,0,0)) {
		vertices[1]=tempVerts[1];
		vertices[0]=tempVerts[3];
		vertices[2]=tempVerts[5];
		vertices[3]=tempVerts[7];
	}
	if (Dir == glm::vec3(-1,0,0)) {
		vertices[1] = tempVerts[0];
		vertices[0] = tempVerts[2];
		vertices[2] = tempVerts[4];
		vertices[3] = tempVerts[6];
	}
	if (Dir == glm::vec3(0,1,0)) {
		vertices[0] = tempVerts[0];
		vertices[1] = tempVerts[1];
		vertices[2] = tempVerts[2];
		vertices[3] = tempVerts[3];
	}	
	if (Dir == glm::vec3(0,-1,0)) {
		vertices[0] = tempVerts[4];
		vertices[1] = tempVerts[5];
		vertices[2] = tempVerts[6];
		vertices[3] = tempVerts[7];
	}
	if (Dir == glm::vec3(0,0,1)) {
		vertices[0] = tempVerts[0];
		vertices[1] = tempVerts[1];
		vertices[2] = tempVerts[6];
		vertices[3] = tempVerts[7];
	}
	if (Dir == glm::vec3(0,0,-1)) {
		vertices[0] = tempVerts[2];
		vertices[1] = tempVerts[3];
		vertices[2] = tempVerts[4];
		vertices[3] = tempVerts[5];
	}

	uint32_t indices[6] = {
	0, 1, 2,
	1, 2, 3
	};

	// Bind and buffer our vertex data
	glBindBuffer(GL_ARRAY_BUFFER, myBuffers[0]);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), vertices, GL_STATIC_DRAW);
	// Bind and buffer our index data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myBuffers[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices, GL_STATIC_DRAW);

	//Get a null vertex to get member offsets from
	Vertex* vert = nullptr;
	// Enable vertex attribute 0
	glEnableVertexAttribArray(0);
	// Our first attribute is 3 floats, the distance between
	// them is the size of our vertex, and they will map to the position in our vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), &(vert->_position));
	// Enable vertex attribute 1
	glEnableVertexAttribArray(1);
	// Our second attribute is 4 floats, the distance between
	// them is the size of our vertex, and they will map to the color in our vertices
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(Vertex), &(vert->_colour));

	// Unbind our VAO
	glBindVertexArray(0);
}

void QuadRenderer::draw()
{
	// Bind the mesh
	glBindVertexArray(myVao);
	// Draw all of our vertices as triangles, our indexes are unsigned ints (uint32_t)
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
