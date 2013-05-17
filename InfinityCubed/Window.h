#pragma once
namespace Window {
    void Init();
    void Create(bool fullscreen);
    void Update();
    void AdjustView(uint32_t w, uint32_t h);
    extern uint32_t Width, Height;
    extern sf::Window * Window;
}