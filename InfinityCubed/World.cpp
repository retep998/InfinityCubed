//#include "Main.h"
//#include "World.h"
//#include "Shader.h"
//#include "Quaternion.h"
//#include "Window.h"
//#include "Block.hpp"
//#include "Time.h"
//namespace World {
//    Shader TerrainShader;
//    GLint RotationUniform, TranslationUniform, PerspectiveUniform;
//    Quaternion Rotation;
//    GLuint VBO;
//    const uint32_t ViewSize = 32;
//    array<array<array<Block, ViewSize>, ViewSize>, ViewSize> Blocks;
//    uint8_t Buf[0x1000000];
//    uint32_t const Vertices = ViewSize * ViewSize * ViewSize;
//    GLuint TerrainDataTexture;
//    void Init() {
//        TerrainShader = Shader("Basic");
//        RotationUniform = TerrainShader.UniformLoc("Rotation");
//        TranslationUniform = TerrainShader.UniformLoc("Translation");
//        PerspectiveUniform = TerrainShader.UniformLoc("Perspective");
//
//        uint32_t i = 0;
//        for (uint8_t x = 0; x < ViewSize; ++x) {
//            for (uint8_t y = 0; y < ViewSize; ++y) {
//                for (uint8_t z = 0; z < ViewSize; ++z) {
//                    Buf[i++] = x;
//                    Buf[i++] = y;
//                    Buf[i++] = z;
//                }
//            }
//        }
//        glGenBuffers(1, &VBO);
//        glBindBuffer(GL_ARRAY_BUFFER, VBO);
//        glBufferData(GL_ARRAY_BUFFER, i, Buf, GL_STATIC_DRAW);
//    }
//    void Render() {
//        glClearColor(0.6, 0.75, 1.0, 1.0);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        TerrainShader.Use();
//        double n = clock() * 0.0002;
//        Rotation = Quaternion(Vector3(cos(n * 1.01 + 1), cos(n * 1.03 + 2), cos(n * 1.07 + 3)), Time::Delta) * Rotation;
//        Rotation.LoadMatrix(RotationUniform);
//        float far = 100, near = 0.01;
//        float p[] = {1.f * Window::Height / Window::Width,
//            0, 0, 0, 0, 1, 0, 0, 0, 0,
//            (near + far) / (near - far), (2 * near * far) / (near - far),
//            0, 0, -1, 0};
//        glUniformMatrix4fv(PerspectiveUniform, 1, GL_FALSE, p);
//        glEnableVertexAttribArray(0);
//        glBindBuffer(GL_ARRAY_BUFFER, VBO);
//        glVertexAttribPointer(0, 3, GL_UNSIGNED_BYTE, GL_FALSE, 3, 0);
//        glDrawArrays(GL_POINTS, 0, Vertices);
//    }
//}