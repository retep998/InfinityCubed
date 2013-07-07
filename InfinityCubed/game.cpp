#include "game.hpp"
#include <cstdio>
#include <functional>

namespace ic3 {
    game::game() : _window{}, _over{false} {
        std::printf("Game initialized\n");
        for (;;) {
            if (!_window.update()) return;
        }
    }

    game::~game() {
        std::printf("Shutting down\n");
    }
}
