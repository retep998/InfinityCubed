#include "Main.h"
#include "Game.h"
#include "Window.h"
#include "World.h"
#include "Time.h"
namespace Game {
    bool Over = false;
    void Init() {
        Window::Init();
        World::Init();
		Time::Init();
    }
    void Loop() {
        World::Render();
		Time::Update();
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