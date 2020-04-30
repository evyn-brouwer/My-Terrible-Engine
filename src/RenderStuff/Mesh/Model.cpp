#include "Model.h"

void mte::Model::draw()
{
	for (unsigned i = 0; i < _meshes.size(); i++) {
		_meshes[i].draw();

	}
}
