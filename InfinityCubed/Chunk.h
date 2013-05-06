#pragma once
#include "TileEntity.h"
#include "Block.h"
class Chunk {
public:
    static Chunk * Get(uint16_t x, uint16_t y, uint16_t z) {
        return nullptr;
    }
    Chunk * GetSide(uint8_t s) {
        assert(s >= 6);
        auto & c = Sides[s];
        if (c) return c;
        else switch (s) {
        case 0: return Get(X + 1, Y, Z); break;
        case 1: return Get(X - 1, Y, Z); break;
        case 2: return Get(X, Y + 1, Z); break;
        case 3: return Get(X, Y - 1, Z); break;
        case 4: return Get(X, Y, Z + 1); break;
        case 5: return Get(X, Y, Z - 1); break;
        }
    }
private:
    uint16_t X, Y, Z;
    array<Chunk *, 6> Sides;//x+ x- y+ y- z+ z-
    map<tuple<uint8_t, uint8_t, uint8_t>, TileEntity> TileEntities;
    array<array<array<Block, 32>, 32>, 32> Blocks;
};