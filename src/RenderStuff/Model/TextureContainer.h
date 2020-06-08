#pragma once


#include <string>

#include "Logging/Logger.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <stb_image.h>


namespace mte {
	class TextureContainer {
	public:
		TextureContainer(std::string textureName,std::string textureFile);
		std::string _textureName;
		std::string _textureFile;

		GLuint _texture;

	private:
		Logger _logger;
	};

}
