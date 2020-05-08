#pragma once

#include "RenderStuff/ShaderStuff/Shader.h"
#include "RenderStuff/Model/Mesh.h"


namespace mte {
	class ResourceManager {
	public:
		ResourceManager();
		std::shared_ptr<mte::Shader> createShader(std::string shaderName, std::string vsSource,std::string fsSource);
		static std::vector<std::shared_ptr<mte::Shader>> _shaders;
		std::shared_ptr<mte::Shader> getShader(std::string shaderName);


		std::shared_ptr<mte::Mesh> createMesh(std::string meshFile, std::string meshName, std::string texturefile, std::string textureName);
		static std::vector<std::shared_ptr<mte::Mesh>> _meshes;

		void drawLightCubes(std::shared_ptr<Camera> camera);
		void updateDrawCubes();

	private:

		std::shared_ptr<mte::Shader> _lightCubeShader;
	};
}
