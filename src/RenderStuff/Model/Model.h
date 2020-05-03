#pragma once
#include "RenderStuff/Model/MeshContainer.h"


namespace mte {
	class Model {
	public:


		void draw();

		std::shared_ptr<Transform> getTransform() { return _transform; }

	private:

		
		std::vector<MeshContainer> _meshes;

		bool _active = true;

		std::shared_ptr<Transform> _transform;
	};
}