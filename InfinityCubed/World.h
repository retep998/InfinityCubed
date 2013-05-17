#pragma once
#include "Chunk.h"
namespace World {
    void Init();
    void Render();
    extern map<tuple<uint32_t, uint32_t, uint32_t>, Chunk *> Chunks;
}