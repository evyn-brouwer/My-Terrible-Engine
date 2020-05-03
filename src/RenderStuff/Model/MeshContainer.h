#pragma once

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Model/Mesh.h"
#include "RenderStuff/Model/Transform.h"

namespace mte {
	class MeshContainer {
	public:
		MeshContainer(std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::Shader> shader);

		void draw();
		void update(float dt);
		std::shared_ptr<mte::Mesh> _mesh;

		std::shared_ptr <mte::Shader> _shader;

		Transform _tranform;


	};



}