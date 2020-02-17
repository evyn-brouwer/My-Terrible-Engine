#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>

class Shader {
public:
	Shader();
	~Shader();

	void compile(const char* vs_source, const char* fs_source);
	void Load(const char* vsFile, const char* fsFile);
	void Bind();
private:
	GLuint __CompileShaderPart(const char* source, GLenum type);
	GLuint myShaderHandle;

};