#pragma once
#include "RenderStuff/QuadRenderer.h"
#include "RenderStuff/Transform.h"
#include "ShaderStuff/Shader.h"
#include "RenderStuff/Camera.h"

class Cube
{
public:
	Cube(Shader* shader,Camera* camera);

	void draw();
	
	Transform _transform;
	glm::vec3 _position;
private:

	QuadRenderer _faces[6];
	
	Shader* _shader;
	Camera* _camera;
};