#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>

#include "Logging/Logger.h"

#include <GLM/glm.hpp>
namespace mte {
	class Shader {
	public:
		Shader();
		~Shader();
		char* readFile(const char* filename);

		void compile(const char* vs_source, const char* fs_source);
		void Load(const char* vsFile, const char* fsFile);
		void Bind();

		void SetUniform(const char* name, const glm::mat4& value);
		void SetUniform(const char* name, const glm::mat3& value);
		void SetUniform(const char* name, const glm::vec3& value);
		void SetUniform(const char* name, const float& value);
	private:
		GLuint __CompileShaderPart(const char* source, GLenum type);
		GLuint myShaderHandle;

		Logger _logger;

	};
}
