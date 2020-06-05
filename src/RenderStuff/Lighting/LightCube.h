#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <vector>

#include "RenderStuff/Model/Transform.h"


namespace mte {
	enum class lightType {
		pointLight,
		directionLight,
		spotLight,
	};

	class LightCube {
	public:
		LightCube(glm::vec3 pos, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
		glm::vec3 _ambient{ 1.0,1.0,1.0 };
		glm::vec3 _diffuse{ 1.0,1.0,1.0 };
		glm::vec3 _specular{ 1.0,1.0,1.0 };
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
