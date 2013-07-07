#include "timer.hpp"

namespace ic3 {
    timer::timer() : _frames{{std::chrono::high_resolution_clock::now()}}, _delta{0} {
    }

    void timer::update() {
        std::chrono::high_resolution_clock::time_point last{_frames.back()};
        std::chrono::high_resolution_clock::time_point now{std::chrono::high_resolution_clock::now()};
        _delta = std::chrono::duration_cast<std::chrono::duration<double>>(now - last).count();
        while (!_frames.empty() && now - _frames.front() > std::chrono::seconds{1}) _frames.pop_front();
        _frames.emplace_back(std::move(now));
        _fps = _frames.size();
    }
}