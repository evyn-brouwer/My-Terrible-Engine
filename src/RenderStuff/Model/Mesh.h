#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "Logging/Logger.h"

#include <vector>
#include <string>
#include <stb_image.h>


namespace mte {
	class Mesh
	{
	public:
		Mesh(std::string meshFile, std::string meshName,std::string texturefile, std::string textureName);
		Mesh(Mesh& copy);
		virtual ~Mesh();

		virtual void draw();

	private:
		Logger _logger;
		bool loadData();

		GLuint _VAO = 0;
		GLuint _VBO = 0;

		GLuint _texture;

		unsigned _vertexCount = 0, _indexCount = 0;



		bool _loaded = false;

		std::vector<float> _master;
		std::vector<float> _vertices;
		std::vector<float> _uvs;
		std::vector<float> _normals;


		std::string _meshFileName = "";
		std::string _meshName = "";

		std::string _textureFileName = "";
		std::string _textureName = "";


		bool active = true;
	};
}