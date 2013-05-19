#include "Main.h"
#include "Time.h"
namespace Time {
    uint32_t FPS = 0;
    double Delta = 1;
    typedef chrono::high_resolution_clock Clock;
    deque<Clock::time_point> LastFrames;
    void Init() {

    }
    void Update() {
        auto now = Clock::now();
        if (!LastFrames.empty()) Delta = chrono::duration_cast<chrono::duration<double>>(now - LastFrames.back()).count();
        LastFrames.push_back(now);
        while (!LastFrames.empty() && now - LastFrames.front() > chrono::seconds(1)) LastFrames.pop_front();
        FPS = LastFrames.size();
    }
}