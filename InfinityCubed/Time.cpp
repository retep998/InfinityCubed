//#include "Main.h"
//#include "Time.h"
//namespace Time {
//    uint32_t FPS = 0;
//    double Delta = 1;
//    typedef chrono::high_resolution_clock Clock;
//    deque<Clock::time_point> LastFrames;
//    void Init() {
//        LastFrames.push_back(Clock::now());
//    }
//    void Update() {
//        auto last = LastFrames.back();
//        auto now = Clock::now();
//        Delta = chrono::duration_cast<chrono::duration<double>>(now - last).count();
//        while (!LastFrames.empty() && now - LastFrames.front() > chrono::seconds(1)) LastFrames.pop_front();
//        LastFrames.push_back(now);
//        FPS = LastFrames.size();
//    }
//}