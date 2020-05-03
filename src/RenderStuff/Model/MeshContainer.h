#pragma once

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Model/Mesh.h"
#include "RenderStuff/Model/Transform.h"
#include "RenderStuff/Camera.h"

namespace mte {
	class MeshContainer {
	public:
		MeshContainer(std::string meshTag, std::shared_ptr<Camera> camera, std::shared_ptr<mte::Mesh> mesh, std::shared_ptr<mte::Shader> shader);

		void draw();
		void update(float dt);

		std::string _meshTag;


		bool _active = true;

		std::shared_ptr<mte::Mesh> _mesh;

		std::shared_ptr <mte::Shader> _shader;

		Transform _tranform;

		std::shared_ptr<Camera> _camera;

	};



}