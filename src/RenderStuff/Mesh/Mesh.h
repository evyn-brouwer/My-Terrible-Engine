#pragma once

#include <glad/glad.h>

#include "RenderStuff/Mesh/Transform.h"

#include "Logging/Logger.h"

#include <vector>
#include <string>


namespace mte {

	class Mesh
	{
	public:
		Mesh(std::string filename);
		Mesh(const std::vector<float> & verts, const std::vector<float>& texts, const std::vector<float>& norms);
		Mesh(Mesh& copy);
		virtual ~Mesh();

		virtual void draw();

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


		std::string _filename= "";
		std::string _name = "";

		std::shared_ptr<Transform> _transform;

		bool active = true;
	};


}