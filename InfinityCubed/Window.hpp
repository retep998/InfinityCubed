#pragma once
class Window
{
private:
    sf::Window window;
    sf::ContextSettings context;
    std::string title;
    uint32_t width, height;
    uint32_t fullWidth, fullHeight;
    uint32_t winWidth, winHeight;
    bool fullscreen;
public:
    Window() :
        window { },
        context {32, 0, 4, 3, 3},
        title {"InfinityCubed"},
        winWidth {800},
        winHeight {600},
        fullWidth {1920},
        fullHeight {1080},
        width {winWidth},
        height {winHeight},
        fullscreen {false}
    {
        setFullscreen(fullscreen);
    }
    void doUpdate()
    {

    }
private:
    void setView(uint32_t w, uint32_t h)
    {
        width = w;
        height = h;
        glViewport(0, 0, width, height);
    }
    void setFullscreen(bool f)
    {
        window.create(f ? sf::VideoMode(fullWidth, fullHeight, 32) : sf::VideoMode(winWidth, winHeight, 32),
                      title,
                      f ? sf::Style::Default | sf::Style::Fullscreen : sf::Style::Default,
                      context);
        fullscreen = f;
    }
};