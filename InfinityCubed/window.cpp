//////////////////////////////////////////////////////////////////////////////
// InfinityCubed - A 3D voxel game                                          //
// Copyright © 2013 Peter Atashian                                          //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program. If not, see < http://www.gnu.org/licenses/ >.   //
//////////////////////////////////////////////////////////////////////////////
#include "window.hpp"
#include "exception.hpp"
#include <GL/glew.h>
#include <SFML/Window/Event.hpp>
#include <cstdio>

namespace ic3 {
    window::window() : _window{}, _fullmode{sf::VideoMode::getFullscreenModes().front()}, _winmode{800, 600, 32}, _fullscreen{false} {
        if (glewInit() != GLEW_OK) throw std::exception{"Failed to initialize GLEW"};
        _recreate();
        std::printf("Window initialized\n");
    }

    window::~window() {
        std::printf("Closing window\n");
    }

    void window::_recreate() {
        _window.create(_fullscreen ? _fullmode : _winmode, "InfinityCubed", _fullscreen ? sf::Style::Fullscreen : sf::Style::Default, sf::ContextSettings{32, 0, 4, 3, 3});
        _adjust_view();

        glClearColor(0.3f, 0.6f, 1.0f, 1.0f);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void window::update() {
        _window.display();
        sf::Event e{};
        while (_window.pollEvent(e)) switch (e.type) {
        case sf::Event::Closed:
            throw shutdown_request{"User closed the window"};
        case sf::Event::KeyPressed:
            switch (e.key.code) {
            case sf::Keyboard::Escape:
                throw shutdown_request{"User pressed escape"};
            case sf::Keyboard::F11:
                _fullscreen = !_fullscreen;
                _recreate();
                break;
            default:;
            }
            break;
        case sf::Event::Resized:
            _adjust_size(e.size.width, e.size.height);
            break;
        default:;
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void window::display_fps(size_t fps) {
        _window.setTitle("InfinityCubed{FPS=" + std::to_string(fps) + "}");
    }

    void window::_adjust_size(uint32_t w, uint32_t h) {
        if (_fullscreen) throw std::exception{"Resize occured while in fullscreen"};
        _winmode.width = w, _winmode.height = h;
        _adjust_view();
    }

    void window::_adjust_view() {
        glViewport(0, 0, static_cast<GLsizei>(_fullscreen ? _fullmode.width : _winmode.width), static_cast<GLsizei>(_fullscreen ? _fullmode.height : _winmode.height));
    }
}
