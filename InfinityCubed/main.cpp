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
#include "game.hpp"
#include <cstdio>

int main() {
    try {
        std::freopen("ic3.log", "w", stdout);
        ic3::game lol{};
        return EXIT_SUCCESS;
    } catch (std::exception e) {
        std::printf("Fatal exception: %s\n", e.what());
        return EXIT_FAILURE;
    } catch (...) {
        std::printf("Unknown fatal exception!");
        return EXIT_FAILURE;
    }
}
