#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

#include "RenderStuff/Model/Transform.h"


namespace mte {
	class LightCube {
	public:
		LightCube(glm::vec3 pos, glm::vec3 colour);
		glm::vec3 _colour{ 1.0,1.0,1.0 };
		glm::vec3 _pos{ 0.0,0.0,0.0 };

		bool _drawn = false;
		bool _active = true;
		void drawCube();
	private:
		GLuint _VAO = 0;
		GLuint _VBO = 0;

		std::vector<float> _master;
	};

}
