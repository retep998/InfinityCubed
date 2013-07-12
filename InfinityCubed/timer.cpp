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
#include "timer.hpp"

namespace ic3 {
    timer::timer() : _frames{{std::chrono::high_resolution_clock::now()}}, _delta{0} {}

    void timer::update() {
        std::chrono::high_resolution_clock::time_point last{_frames.back()};
        std::chrono::high_resolution_clock::time_point now{std::chrono::high_resolution_clock::now()};
        _delta = std::chrono::duration_cast<std::chrono::duration<double>>(now - last).count();
        while (!_frames.empty() && now - _frames.front() > std::chrono::seconds{1}) _frames.pop_front();
        _frames.emplace_back(std::move(now));
        _fps = _frames.size();
    }

    size_t timer::fps() const {
        return _fps;
    }
}
