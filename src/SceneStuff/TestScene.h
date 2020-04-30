#pragma once
#include "Scene.h"
#include <iostream>
#include <memory>
#include <stb_image.h>

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Mesh/Mesh.h"

class TestScene : public mte::Scene
{
public:
	TestScene(GLFWwindow* window, std::string sceneName);

	void loadData();

	virtual void Resize(int Width, int Height)override;
private:

	virtual void virtualUpdate(float dt)override;

	float vertices[32] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};

	unsigned int indices[6] = {  // note that we start from 0!
    0, 1, 3,
	1, 2, 3// first triangle
	};

	float texCoords[6] = {
	0.0f, 0.0f,  // lower-left corner  
	1.0f, 0.0f,  // lower-right corner
	0.5f, 1.0f   // top-center corner
	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

	unsigned int texture;

	std::shared_ptr<mte::Shader> _simpleShader;

	std::shared_ptr<mte::Mesh> _testMesh;

};