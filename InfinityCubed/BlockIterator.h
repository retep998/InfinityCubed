#pragma once
#include "Block.h"
#include "Chunk.h"
class BlockIterator {
public:
    void Xp() {
        if (X++ == 31) {
            C = C->GetSide(0);
            X = 0;
        }
    }
    void Xm() {
        if (X-- == 0) {
            C = C->GetSide(1);
            X = 31;
        }
    }
    void Yp() {
        if (Y++ == 31) {
            C = C->GetSide(2);
            Y = 0;
        }
    }
    void Ym() {
        if (Y-- == 0) {
            C = C->GetSide(3);
            Y = 31;
        }
    }
    void Zp() {
        if (Z++ == 31) {
            C = C->GetSide(4);
            Z = 0;
        }
    }
    void Zm() {
        if (Z-- == 0) {
            C = C->GetSide(5);
            Z = 31;
        }
    }
private:
    uint8_t X, Y, Z;
    Chunk * C;
};