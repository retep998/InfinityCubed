#pragma once
#include "TileEntity.h"
#include "Block.h"
class Chunk {
public:
    Chunk(uint32_t x, uint32_t y, uint32_t z);
    static Chunk * Get(uint32_t x, uint32_t y, uint32_t z);
    static Chunk * ForceGet(uint32_t x, uint32_t y, uint32_t z);
    Chunk * GetSide(uint8_t);
    void Render();
    void Update();
private:
    Chunk & operator=(Chunk const &);
    void Generate();
    uint32_t const X, Y, Z;
    array<Chunk *, 6> Sides;//x+ x- y+ y- z+ z-
    map<tuple<uint8_t, uint8_t, uint8_t>, TileEntity> TileEntities;
    array<array<array<Block, 32>, 32>, 32> Blocks;
    GLuint VBO;
    GLsizei Vertices;
};