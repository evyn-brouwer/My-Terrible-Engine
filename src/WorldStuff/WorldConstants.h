#pragma once

#include "Types.h"

using blockType = u8;

constexpr unsigned CHUNK_SIZE = 32;
constexpr int CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE;
constexpr int CHUNK_VOLUME = CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE;

constexpr int WATER_LEVEL = CHUNK_SIZE;