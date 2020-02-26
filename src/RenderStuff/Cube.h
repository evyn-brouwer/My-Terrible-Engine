#pragma once
#include "RenderStuff/QuadRenderer.h"
#include "RenderStuff/Transform.h"
#include "ShaderStuff/Shader.h"
#include "RenderStuff/Camera.h"

#include <memory>

class Cube
{
public:
	Cube(std::shared_ptr<Shader> shader, std::shared_ptr<Camera> camera, glm::vec3 position);

	void draw();
	
	Transform _transform;
	glm::vec3 _position;
private:

	QuadRenderer _faces[6];
	
	std::shared_ptr<Shader> _shader;
	std::shared_ptr<Camera> _camera;
};