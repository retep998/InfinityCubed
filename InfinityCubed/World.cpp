#include "Main.h"
#include "World.h"
#include "Shader.h"
#include "Quaternion.h"
#include "Window.h"
namespace World {
    map<tuple<uint32_t, uint32_t, uint32_t>, Chunk *> Chunks;
    Shader TerrainShader;
    GLint RotationUniform, PerspectiveUniform;
    Quaternion Rotation;
    void Init() {
        TerrainShader = Shader("Basic");
        RotationUniform = TerrainShader.UniformLoc("Rotation");
        PerspectiveUniform = TerrainShader.UniformLoc("Perspective");
    }
    void Render() {
        glClearColor(0.6, 0.75, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        TerrainShader.Use();
        double n = clock() * 0.0002;
        Rotation = Quaternion(Vector3(cos(n * 1.01 + 1), cos(n * 1.03 + 2), cos(n * 1.07 + 3)), 0.01) * Rotation;
        Rotation.LoadMatrix(RotationUniform);
        float far = 100, near = 0.01;
        float p[] = {1. * Window::Height / Window::Width,
            0, 0, 0, 0, 1, 0, 0, 0, 0,
            (near + far) / (near - far), (2 * near * far) / (near - far),
            0, 0, -1, 0};
        glUniformMatrix4fv(PerspectiveUniform, 1, GL_FALSE, p);
        Chunk::ForceGet(0, 0, 0)->Render();
    }
}