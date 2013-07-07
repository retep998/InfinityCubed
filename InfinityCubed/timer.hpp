#pragma once
#include <deque>
#include <chrono>

namespace ic3 {
    class timer {
    public:
        timer();
        void update();
    private:
        std::deque<std::chrono::high_resolution_clock::time_point> _frames;
        double _delta;
        size_t _fps;
    };
}
