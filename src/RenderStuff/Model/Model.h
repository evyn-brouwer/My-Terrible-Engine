#pragma once
#include "RenderStuff/Model/MeshContainer.h"


namespace mte {
	class Model {
	public:
		Model() {};

		void addMesh(std::shared_ptr<MeshContainer> mesh) { _meshes.push_back(mesh); };

		void draw();
		void update(float dt);
		
		std::shared_ptr<mte::MeshContainer> getMesh(std::string meshTag);  

		Transform getTransform() { return _transform; }

	private:

		
		std::vector<std::shared_ptr<MeshContainer>> _meshes;

		bool _active = true;

		Transform _transform;
	};
}