#include "BlockData.h"

const blockData& BlockDataManager::getBlockData(blockType id) const
{
	return blocks.at(id);
}

const blockData& BlockDataManager::getBlockData(const std::string& blockName) const
{
	return blocks.at(getBlockId(blockName));
}

blockType BlockDataManager::getBlockId(const std::string& blockName) const
{
	return blockMap.at(blockName);
}

const std::vector<blockData>& BlockDataManager::getBlockData() const
{
	return blocks;
}
