#include "Main.h"
#include "Chunk.h"
#include "World.h"
#include "Log.h"
uint8_t s1[] = {1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0};
uint8_t s2[] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1};
uint8_t s3[] = {0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1};
uint8_t s4[] = {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0};
uint8_t s5[] = {1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1};
uint8_t s6[] = {0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0};
uint8_t * SideCoords[] = {s1, s2, s3, s4, s5, s6};
static char Buf[0x10000000];
char * Bufi;
Chunk::Chunk(uint32_t x, uint32_t y, uint32_t z) : X(x), Y(y), Z(z) {
    Link(X + 1, Y, Z, 0);
    Link(X - 1, Y, Z, 1);
    Link(X, Y + 1, Z, 2);
    Link(X, Y - 1, Z, 3);
    Link(X, Y, Z + 1, 4);
    Link(X, Y, Z - 1, 5);
    glGenBuffers(1, &VBO);
    Generate();
}
void Chunk::Generate() {
	for (uint8_t x = 0; x < 32; ++x) for (uint8_t y = 0; y < 32; ++y) for (uint8_t z = 0; z < 32; ++z) Blocks[x][y][z].id = 0;
    for (uint8_t x = 4; x < 28; ++x) for (uint8_t y = 4; y < 28; ++y) for (uint8_t z = 4; z < 28; ++z) {
		Blocks[x][y][z].id = 1;
		Blocks[x][y][z].r = rand() % 256;
		Blocks[x][y][z].g = rand() % 256;
		Blocks[x][y][z].b = rand() % 256;
    }
	Updated = false;
}
void AddVertex(uint8_t s, uint8_t x, uint8_t y, uint8_t z) {
    for (uint8_t i = 0; i < 4; ++i) {
        Bufi[i * 3 + 0] = x;
        Bufi[i * 3 + 1] = y;
        Bufi[i * 3 + 2] = z;
    }
    for (uint8_t i = 0; i < 12; ++i) {
        Bufi[i] += SideCoords[s][i];
    }
    Bufi += 12;
}
void AddColor(Block const & b) {
    for (size_t i = 0; i < 4; ++i) {
        Bufi[0] = b.r;
        Bufi[1] = b.g;
        Bufi[2] = b.b;
        Bufi += 3;
    }
};
void Chunk::Update() {
    Bufi = Buf;
    for (uint8_t x = 0; x < 32; ++x) for (uint8_t y = 0; y < 32; ++y) for (uint8_t z = 0; z < 32; ++z) {
        if (Blocks[x][y][z].id) {
            AddVertex(0, x, y, z);
            AddVertex(1, x, y, z);
            AddVertex(2, x, y, z);
            AddVertex(3, x, y, z);
            AddVertex(4, x, y, z);
            AddVertex(5, x, y, z);
        }
    }
    Vertices = (Bufi - Buf) / 3;
    for (uint8_t x = 0; x < 32; ++x) for (uint8_t y = 0; y < 32; ++y) for (uint8_t z = 0; z < 32; ++z) {
        auto const & b = Blocks[x][y][z];
        if (b.id) {
            AddColor(b);
            AddColor(b);
            AddColor(b);
            AddColor(b);
            AddColor(b);
            AddColor(b);
        }
    }
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices * 6, Buf, GL_STATIC_DRAW);
	Log::Write("Vertices: " + to_string(Vertices));
	Log::Write("Size: " + to_string(Bufi - Buf));
}
void Chunk::Render() {
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_UNSIGNED_BYTE, GL_FALSE, 3, 0);
    glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_TRUE, 3, reinterpret_cast<GLvoid *>(Vertices * 3));
    glDrawArrays(GL_QUADS, 0, Vertices);
}
Chunk * Chunk::Get(uint32_t x, uint32_t y, uint32_t z, bool force) {
    auto i = World::Chunks.find(make_tuple(x, y, z));
    if (i != World::Chunks.end()) return i->second;
	if (!force) return nullptr;
	Chunk * c = new Chunk(x, y, z);
    World::Chunks.insert(make_pair(make_tuple(x, y, z), c));
    return c;
}
Chunk * Chunk::GetSide(uint8_t s, bool force) {
    assert(s >= 6);
    auto & c = Sides[s];
    if (c) return c;
    else switch (s) {
    case 0: return Get(X + 1, Y, Z, force); break;
    case 1: return Get(X - 1, Y, Z, force); break;
    case 2: return Get(X, Y + 1, Z, force); break;
    case 3: return Get(X, Y - 1, Z, force); break;
    case 4: return Get(X, Y, Z + 1, force); break;
    case 5: return Get(X, Y, Z - 1, force); break;
    default: throw; return nullptr;
    }
}