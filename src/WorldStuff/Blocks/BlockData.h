#pragma once

#include "Resources/Types.h"
#include "WorldStuff/WorldConstants.h"

#include <string>
#include <glad/glad.h>
#include <unordered_map>
#include <vector>

enum class MeshType : u8 {
	Block = 0,
	Cross = 1,
	None = 2,


	Error,
};

enum class BlockType : u8 {
	Solid = 0,
	Liquid = 1,
	Gas = 2,
	Plant = 3,

	Error,
};


struct blockData {
	blockType _id = 0;

	std::string _blockName;
	std::string _topTexture;
	std::string _sideTexture;
	std::string _bottomTexture;

	// Client only
	GLuint _topTextureId = 0;
	GLuint _sideTextureId = 0;
	GLuint _bottomTextureId = 0;

	MeshType _meshType = MeshType::Block;
	BlockType type = BlockType::Solid;

	bool _isCollidable = true;
};

class BlockDataManager {
public:
	BlockDataManager() {};

	const blockData& getBlockData(blockType id)const;
	const blockData& getBlockData(const std::string& blockName)const;


	blockType getBlockId(const std::string& blockName)const;

	const std::vector<blockData>& getBlockData() const;
private:
	std::vector<blockData> blocks;
	std::unordered_map<std::string, blockType> blockMap;


};