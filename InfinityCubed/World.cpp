#include "Main.h"
#include "World.h"
#include "Shader.h"
#include "Quaternion.h"
namespace World {
    Shader TerrainShader;
    GLuint VBO;
    GLint RotationUniform, PerspectiveUniform;
    void Init() {
        TerrainShader = Shader("Basic");
        RotationUniform = TerrainShader.UniformLoc("Rotation");
        PerspectiveUniform = TerrainShader.UniformLoc("Perspective");
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        float lol[] = {
            -1, -1, -1,  1, -1, -1,  1,  1, -1, -1,  1, -1,
             1, -1, -1,  1, -1,  1,  1,  1,  1,  1,  1, -1,
             1, -1,  1, -1, -1,  1, -1,  1,  1,  1,  1,  1,
            -1, -1,  1, -1, -1, -1, -1,  1, -1, -1,  1,  1,
            -1, -1, -1, -1, -1,  1,  1, -1,  1,  1, -1, -1,
            -1,  1, -1,  1,  1, -1,  1,  1,  1, -1,  1,  1};
        glBufferData(GL_ARRAY_BUFFER, sizeof(lol), lol, GL_STATIC_DRAW);
    }
    void Render() {
        glClearColor(0.6, 0.75, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        TerrainShader.Use();
        double n = clock() * 0.0001;
        Quaternion q(Vector3(sin(n), cos(n), 0), n * 10);
        q.Normalize();
        q.LoadMatrix(RotationUniform);
        float far = 10, near = 0.1;
        float p[] = {9 / 16., 0, 0, 0, 0, 1, 0, 0, 0, 0,
            (near + far) / (near - far), (2 * near * far) / (near - far),
            0, 0, -1, 0};
        glUniformMatrix4fv(PerspectiveUniform, 1, GL_FALSE, p);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_QUADS, 0, 24);
    }
}