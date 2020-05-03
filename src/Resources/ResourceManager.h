#pragma once

#include "RenderStuff/ShaderStuff/Shader.h"

namespace mte {
	class ResourceManager {
	public:
		std::shared_ptr<mte::Shader> createShader(std::string shaderName, std::string vsSource,std::string fsSource);

		static std::vector<std::shared_ptr<mte::Shader>> _shaders;


	private:

	};
}
