#include "Mesh.h"

#include <fstream>
#include <sstream>
#include <iostream>
/*
A lot of this comes from the cappuccino engine
*/


namespace mte {
	struct faceData {
		unsigned vertexesIndexex[3];
		unsigned textureIndexex[3];
		unsigned normalIndexex[3];
	};

}

mte::Mesh::Mesh(std::string meshFileName,std::string meshName, std::string texturefile, std::string textureName)
	:_meshFileName(meshFileName),_meshName(meshName),_textureFileName(texturefile),_textureName(textureName)
{
	loadData(); 
}

mte::Mesh::Mesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName, std::string specularFile, std::string specularName)
	: _meshFileName(meshFile), _meshName(meshName), _textureFileName(texturefile), _textureName(textureName),_specularName(specularName),_specularFileName(specularFile)
{
	loadData();
}

mte::Mesh::Mesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName, std::string specularFile, std::string specularName, std::string emissionFile, std::string emissionName)
	: _meshFileName(meshFile), _meshName(meshName), _textureFileName(texturefile), _textureName(textureName), _specularName(specularName), _specularFileName(specularFile),_emissionName(emissionName),_emissionFileName(emissionFile)
{
	loadData();
}


mte::Mesh::Mesh(Mesh& copy)
{
	_meshFileName = copy._meshFileName;
	_vertices = copy._vertices;
	_normals = copy._normals;
	_uvs = copy._uvs;
}

mte::Mesh::~Mesh()
{
	glDeleteVertexArrays(1,&_VAO);
	
}

void mte::Mesh::draw()
{
	if (_active) {
		glBindTexture(GL_TEXTURE_2D, _texture);
		glBindVertexArray(_VAO);
		glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
	}
}

bool mte::Mesh::loadData()
{
	if (_loaded)
		return true;

	char inputString[128];

	std::vector<glm::vec3> vertexData{};
	std::vector<glm::vec2> textureData{};
	std::vector<glm::vec3> normalData{};

	std::vector<faceData> faces{};
	std::vector<float> unPvertexData{};
	std::vector<float> unPtextureData{};
	std::vector<float> unPnormalData{};


	std::ifstream input{};

	input.open(_meshFileName);
	if (!input.good()) {
		Error error;
		error._errorLocation = "Mesh.cpp";
		error._errorSeverity = mte::ErrorSeverityLevel::bad;
		error._errorMessage = "Problem loading: " + _meshFileName;
		_logger.sendError(error);
		return false;
	}

	while (!input.eof()) {
		input.getline(inputString, 128);

		if (inputString[0] == 'v' && inputString[1] == ' ') {
			glm::vec3 vertData{ 0,0,0 };

			int error = std::sscanf(inputString, "v %f %f %f", &vertData.x, &vertData.y, &vertData.z);
			vertexData.push_back(vertData);
		}
		else if (inputString[0] == 'v' && inputString[1] == 't') {
			glm::vec2 texCoord{ 0,0 };

			int error = std::sscanf(inputString, "vt %f %f", &texCoord.x, &texCoord.y);
			textureData.push_back(texCoord);
		}
		else if (inputString[0] == 'v' && inputString[1] == 'n') {
			glm::vec3 normData{ 0,0,0 };

			int error = std::sscanf(inputString, "vn %f %f %f", &normData.x, &normData.y, &normData.z);
			normalData.push_back(normData);
		}
		else if (inputString[0] == 'f' && inputString[1] == ' ') {
			faces.emplace_back();

			int error = std::sscanf(inputString, "f %u/%u/%u %u/%u/%u %u/%u/%u",
				&faces.back().vertexesIndexex[0], &faces.back().textureIndexex[0], &faces.back().normalIndexex[0],
				&faces.back().vertexesIndexex[1], &faces.back().textureIndexex[1], &faces.back().normalIndexex[1],
				&faces.back().vertexesIndexex[2], &faces.back().textureIndexex[2], &faces.back().normalIndexex[2]);
		}
		else
			continue;
	}

	for (unsigned i = 0; i < faces.size(); i++) {
		for (unsigned j = 0; j < 3; j++) {
			unPvertexData.push_back(vertexData[faces[i].vertexesIndexex[j] - 1].x);
			unPvertexData.push_back(vertexData[faces[i].vertexesIndexex[j] - 1].y);
			unPvertexData.push_back(vertexData[faces[i].vertexesIndexex[j] - 1].z);

			if (!textureData.empty()) {
				unPtextureData.push_back(textureData[faces[i].textureIndexex[j] - 1].x);
				unPtextureData.push_back(textureData[faces[i].textureIndexex[j] - 1].y);
			}
			if (!normalData.empty()) {
				unPnormalData.push_back(normalData[faces[i].normalIndexex[j] - 1].x);
				unPnormalData.push_back(normalData[faces[i].normalIndexex[j] - 1].y);
				unPnormalData.push_back(normalData[faces[i].normalIndexex[j] - 1].z);
			}
		}

	}
	_indexCount = faces.size();
	_vertexCount = _indexCount * 3;


	for (unsigned i = 0; i < unPvertexData.size(); i++) {
		_master.push_back(unPvertexData[i]);
		_vertices.push_back(unPvertexData[i]);
	}

	for (unsigned i = 0; i < unPtextureData.size(); i++) {
		_master.push_back(unPtextureData[i]);
		_uvs.push_back(unPtextureData[i]);
	}

	for (unsigned i = 0; i < unPnormalData.size(); i++) {
		_master.push_back(unPnormalData[i]);
		_normals.push_back(unPnormalData[i]);
	}


	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);

	glBindVertexArray(_VAO);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);

	glBufferData(GL_ARRAY_BUFFER, _master.size() * sizeof(float), &_master[0], GL_STATIC_DRAW);

	//vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//uvs
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(unPvertexData.size() * sizeof(float)));

	//normals
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)((unPvertexData.size() + unPtextureData.size()) * sizeof(float)));


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	input.close();


	glGenTextures(1, &_texture);
	

	

	{
		int width, height, nrChannels;
		unsigned char* data = stbi_load(_textureFileName.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			GLenum format;
			if (nrChannels == 1)
				format = GL_RED;
			else if (nrChannels == 3)
				format = GL_RGB;
			else if (nrChannels == 4)
				format = GL_RGBA;
			glBindTexture(GL_TEXTURE_2D, _texture);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			stbi_image_free(data);
		}
		else
		{
			Error error;
			error._errorLocation = "Mesh.cpp";
			error._errorSeverity = mte::ErrorSeverityLevel::bad;
			error._errorTypes.push_back(mte::ErrorType::LoadFail);
			error._errorMessage = "Failed to load texture: " + _textureFileName;
			_logger.sendError(error);
			stbi_image_free(data);
		}
		
	}


	glGenTextures(1, &_specularMap);
	

	

	{
		std::string filename = "Assets/Textures/default_map.jpg";
		if (_specularFileName != "")
		{
			filename = _specularFileName;
		}
		int width, height, nrChannels;
		unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			GLenum format;
			if (nrChannels == 1)
				format = GL_RED;
			else if (nrChannels == 3)
				format = GL_RGB;
			else if (nrChannels == 4)
				format = GL_RGBA;
			glBindTexture(GL_TEXTURE_2D, _specularMap);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			stbi_image_free(data);
		}
		else
		{
			Error error;
			error._errorLocation = "Mesh.cpp";
			error._errorSeverity = mte::ErrorSeverityLevel::bad;
			error._errorTypes.push_back(mte::ErrorType::LoadFail);
			error._errorMessage = "Failed to load specular texture: " + filename;
			_logger.sendError(error);
			stbi_image_free(data);
		}
		
	}


	glGenTextures(1, &_emissionMap);
	

	

	{
		std::string filename = "Assets/Textures/meme.jpg";
		if (_emissionFileName != "") 
		{
			filename = _emissionFileName;
		}
		int width, height, nrChannels;
		unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			GLenum format;
			if (nrChannels == 1)
				format = GL_RED;
			else if (nrChannels == 3)
				format = GL_RGB;
			else if (nrChannels == 4)
				format = GL_RGBA;
			glBindTexture(GL_TEXTURE_2D, _emissionMap);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			stbi_image_free(data);
		}
		else
		{
			Error error;
			error._errorLocation = "Mesh.cpp";
			error._errorSeverity = mte::ErrorSeverityLevel::bad;
			error._errorTypes.push_back(mte::ErrorType::LoadFail);
			error._errorMessage = "Failed to load emissive texture: " + filename;
			_logger.sendError(error);
			stbi_image_free(data);
		}
		
	}

	_loaded = true;
	return true;
}
