#include "Main.h"
#include "World.h"
#include "Shader.h"
#include "Quaternion.h"
#include "Window.h"
namespace World {
    Shader TerrainShader;
    GLuint VBO;
    GLint RotationUniform, PerspectiveUniform, MouseUniform;
    void Init() {
        TerrainShader = Shader("Basic");
        RotationUniform = TerrainShader.UniformLoc("Rotation");
        PerspectiveUniform = TerrainShader.UniformLoc("Perspective");
        MouseUniform = TerrainShader.UniformLoc("Mouse");
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
        float p[] = {1. * Window::Height / Window::Width, 0, 0, 0, 0, 1, 0, 0, 0, 0,
            (near + far) / (near - far), (2 * near * far) / (near - far),
            0, 0, -1, 0};
        glUniformMatrix4fv(PerspectiveUniform, 1, GL_FALSE, p);
        glUniform2f(MouseUniform, 1. * sf::Mouse::getPosition(*Window::Window).x / Window::Width,
            1. * sf::Mouse::getPosition(*Window::Window).y / Window::Height);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_QUADS, 0, 24);
    }
}