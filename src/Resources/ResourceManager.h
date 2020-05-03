#pragma once

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Model/Mesh.h"

namespace mte {
	class ResourceManager {
	public:
		std::shared_ptr<mte::Shader> createShader(std::string shaderName, std::string vsSource,std::string fsSource);
		static std::vector<std::shared_ptr<mte::Shader>> _shaders;

		std::shared_ptr<mte::Mesh> createMesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName);
		static std::vector<std::shared_ptr<mte::Mesh>> _meshes;


	private:

	};
}
