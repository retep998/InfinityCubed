//////////////////////////////////////////////////////////////////////////////
// InfinityCubed - A 3D voxel game                                          //
// Copyright � 2013 Peter Atashian                                          //
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
#include "game.hpp"
#include "exception.hpp"
#include <cstdio>
#include <functional>

namespace ic3 {
    game::game() : _window{}, _timer{}, _over{false} {
        std::printf("Game initialized\n");
        try {
            for (;;) {
                _window.update();
                _timer.update();
                _window.display_fps(_timer.fps());
            }
        } catch (shutdown_request e) {
            std::printf("Shutdown requested: %s\n", e.what());
        }
    }

    game::~game() {
        std::printf("Stopping game\n");
    }
}
