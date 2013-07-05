#pragma once
class Block {
public:
    uint16_t id;
    class Iterator
    {
        Iterator() : x {0}, y {0}, z {0}
        {
        }
        Iterator(Iterator const & o) : x {o.x}, y {o.y}, z {o.z}
        {
        }
        Iterator(uint16_t x, uint16_t y, uint16_t z) : x {x}, y {y}, z {z}
        {
        }
        uint16_t x, y, z;
        Iterator xp()
        {
            return {x + 1u, y, z};
        };
    };
};