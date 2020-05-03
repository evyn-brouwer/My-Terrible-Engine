#include "Model.h"

void mte::Model::draw()
{
	if(_active)
		for (unsigned i = 0; i < _meshes.size(); i++) {
			_meshes[i]->draw();
		}
}

void mte::Model::update(float dt)
{
	if (_active)
		for (unsigned i = 0; i < _meshes.size(); i++) {
			_meshes[i]->update(dt);
		}
}

std::shared_ptr<mte::MeshContainer> mte::Model::getMesh(std::string meshTag)
{
	for (auto x : _meshes) {
		if (x->_meshTag == meshTag)
			return x;
	}
	return NULL;
}
