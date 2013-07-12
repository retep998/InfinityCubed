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
#pragma once
#include <SFML/Window/Window.hpp>
#include <cstdint>

namespace ic3 {
    class game;
    class window {
    public:
        window();
        ~window();
        void update();
        void display_fps(size_t fps);
    private:
        void _recreate();
        void _adjust_size(uint32_t w, uint32_t h);
        void _adjust_view();
        sf::Window _window;
        sf::VideoMode _fullmode, _winmode;
        bool _fullscreen;
    };
}
