#pragma once
#include "window.hpp"
#include "timer.hpp"

namespace ic3 {
    class game {
    public:
        game();
        ~game();
    private:
        window _window;
        timer _timer;
        bool _over;
    };
}
