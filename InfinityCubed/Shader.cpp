#include "Main.h"
#include "Shader.h"
#include "Log.h"
static char buf[0x1000];
map<string, GLuint> Shaders;
Shader::Shader() : p(0) {}
Shader::Shader(string name) {
    auto i = Shaders.find(name);
    if (i != Shaders.end()) {
        p = i->second;
        return;
    }
    p = glCreateProgram();
    Shaders.insert(i, make_pair(name, p));
    auto AddShader = [&](path name, GLenum type) {
        if (!exists(name)) return;
        GLint l = static_cast<GLint>(file_size(name));
        GLuint s = glCreateShader(type);
        ifstream f(name);
        f.read(buf, 0x1000);
        GLchar const * t = buf;
        glShaderSource(s, 1, &t, &l);
        glCompileShader(s);
        glGetShaderInfoLog(s, 0x1000, 0, buf);
        Log::Write(buf);
        GLint compiled;
        glGetShaderiv(s, GL_COMPILE_STATUS, &compiled);
        if (!compiled) throw;
        glAttachShader(p, s);
    };
    AddShader("Shaders/" + name + ".gs", GL_GEOMETRY_SHADER);
    AddShader("Shaders/" + name + ".fs", GL_FRAGMENT_SHADER);
    AddShader("Shaders/" + name + ".vs", GL_VERTEX_SHADER);
    glLinkProgram(p);
    glGetProgramInfoLog(p, 0x1000, 0, buf);
    Log::Write(buf);
    GLint linked;
    glGetProgramiv(p, GL_LINK_STATUS, &linked);
    if (!linked) throw;
}
void Shader::Use() {
    glUseProgram(p);
}
GLint Shader::UniformLoc(string name) {
    return glGetUniformLocation(p, name.c_str());
}