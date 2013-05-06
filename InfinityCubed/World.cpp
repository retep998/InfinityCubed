#include "Main.h"
#include "World.h"

namespace World {
    bool Over = false;
    sf::Window * Win;
    void Init() {
        Win = new sf::Window(sf::VideoMode(800, 600, 32), "InfinityCubed", sf::Style::Default, sf::ContextSettings(32, 0, 0, 3, 3));
    }
    bool Loop() {
        return true;
    }
    void Unload() {
        delete Win;
    }
    void Play() {
        Init();
        while (!Over) Loop();
        Unload();
    }
}