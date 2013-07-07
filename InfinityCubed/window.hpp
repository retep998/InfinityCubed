#pragma once
#include <SFML/Window/Window.hpp>
#include <cstdint>

namespace ic3 {
    class game;
    class window {
    public:
        window();
        void recreate();
        bool update();
    private:
        sf::Window _window;
        sf::ContextSettings _context;
        std::string _title;
        uint32_t _winwidth, _winheight;
        uint32_t _fullwidth, _fullheight;
        uint32_t _width, _height;
        bool _fullscreen;
    };
}
