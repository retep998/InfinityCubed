#pragma once
#include "Shader.h"
class Shader {
public:
    Shader();
    Shader(string);
    void Use();
    GLint UniformLoc(string name);
private:
    GLuint p;
};