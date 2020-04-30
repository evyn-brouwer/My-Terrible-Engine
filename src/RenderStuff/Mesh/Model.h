#pragma once
#include "RenderStuff/Mesh/Mesh.h"
#include "RenderStuff/Mesh/Transform.h"


namespace mte {
	class Model {
	public:


		void draw();

		std::shared_ptr<Transform> getTransform() { return _transform; }

	private:

		
		std::vector<Mesh> _meshes;

	std::shared_ptr<Transform> _transform;
	};
}