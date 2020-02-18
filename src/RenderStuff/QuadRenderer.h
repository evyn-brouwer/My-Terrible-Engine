#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

#include "Structs.h"

class QuadRenderer
{
public:
	QuadRenderer();
	QuadRenderer(glm::vec3 Pos, glm::vec3 Dir);

	void draw();

private:
	glm::vec3 _position;
	glm::vec3 _direction;

	GLuint myVao;
	GLuint myBuffers[2];
};