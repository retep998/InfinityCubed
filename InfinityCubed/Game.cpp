#include "Main.h"
#include "Game.h"
#include "Window.h"
#include "World.h"
namespace Game {
    bool Over = false;
    void Init() {
        Window::Init();
        World::Init();
    }
    void Loop() {
        World::Render();
        Window::Update();
    }
    void Unload() {

    }
    void Play() {
        Init();
        while (!Over) Loop();
        Unload();
    }
}