#pragma once
#include "RenderStuff/Model/MeshContainer.h"


namespace mte {
	class Model {
	public:


		void draw();

		Transform getTransform() { return _transform; }

	private:

		
		std::vector<MeshContainer> _meshes;

		bool _active = true;

		Transform _transform;
	};
}