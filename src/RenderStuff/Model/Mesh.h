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
		Mesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName, std::string specularFile, std::string specularName);
		Mesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName, std::string specularFile, std::string specularName, std::string emissionFile, std::string emissionName);

		Mesh(Mesh& copy);
		virtual ~Mesh();

		virtual void draw();

		std::string _meshName = "";
		std::string _textureName = "";
		std::string _specularName = "";
		std::string _emissionName = "";

		GLuint _texture;
		GLuint _specularMap;
		GLuint _emissionMap;

	private:
		Logger _logger;
		bool loadData();

		GLuint _VAO = 0;
		GLuint _VBO = 0;

		

		unsigned _vertexCount = 0, _indexCount = 0;

		bool _loaded = false;

		std::vector<float> _master;
		std::vector<float> _vertices;
		std::vector<float> _uvs;
		std::vector<float> _normals;


		std::string _meshFileName = "";

		std::string _textureFileName = "";

		std::string _specularFileName = "";
		
		std::string _emissionFileName = "";

		bool _active = true;
	};
}