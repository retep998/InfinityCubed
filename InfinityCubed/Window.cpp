#include "Main.h"
#include "Window.h"
#include "Game.h"
#include "Log.h"
namespace Window {
    sf::Window * Window;
    uint32_t Width, Height;
    uint32_t WWidth = 800, WHeight = 600;
    uint32_t FWidth, FHeight;
    string Title = "InfinityCubed";
    bool Fullscreen = false;
    void Init() {
        auto v = sf::VideoMode::getFullscreenModes()[0];
        FWidth = v.width;
        FHeight = v.height;
        Window = new sf::Window();
        Create(false);
        GLenum err = glewInit();
        switch (err) {
        case GLEW_OK:
            break;
        case GLEW_ERROR_NO_GL_VERSION:
            Log::Write("ERROR: You need OpenGL");
            throw; break;
        case GLEW_ERROR_GL_VERSION_10_ONLY:
            Log::Write("ERROR: You need something newer than OpenGL 1.0");
            throw; break;
        case GLEW_ERROR_GLX_VERSION_11_ONLY:
            Log::Write("ERROR: You need something newer than GLX 1.1");
            throw; break;
        default:
            Log::Write("ERROR: Unknown error");
            throw;
        }
    }
    void Create(bool fullscreen) {
        if (fullscreen) Window->create(sf::VideoMode(FWidth, FHeight, 32), Title, sf::Style::Default | sf::Style::Fullscreen, sf::ContextSettings(32, 0, 0, 3, 3));
        else Window->create(sf::VideoMode(WWidth, WHeight, 32), Title, sf::Style::Default, sf::ContextSettings(32, 0, 0, 3, 3));
        AdjustView(Window->getSize().x, Window->getSize().y);
        Fullscreen = fullscreen;
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    void AdjustView(uint32_t w, uint32_t h) {
        Width = w;
        Height = h;
        glViewport(0, 0, Width, Height);
    }
    void Update() {
        GLenum err = glGetError();
        switch (err) {
        case GL_NO_ERROR:
            break;
        case GL_INVALID_ENUM:
            Log::Write("ERROR: Invalid enum");
            throw; break;
        case GL_INVALID_VALUE:
            Log::Write("ERROR: Invalid value");
            throw; break;
        case GL_INVALID_OPERATION:
            Log::Write("ERROR: Invalid operation");
            throw; break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            Log::Write("ERROR: Invalid framebuffer operation");
            throw; break;
        case GL_OUT_OF_MEMORY:
            Log::Write("ERROR: Out of memory");
            throw; break;
        default:
            Log::Write("ERROR: Unknown OpenGL error code " + to_string(err));
            throw;
        }
        Window->display();
        sf::Event e;
        while (Window->pollEvent(e)) switch (e.type) {
        case sf::Event::Closed:
            Game::Over = true;
            break;
        case sf::Event::GainedFocus: break;
        case sf::Event::LostFocus: break;
        case sf::Event::JoystickButtonPressed: break;
        case sf::Event::JoystickButtonReleased: break;
        case sf::Event::JoystickConnected: break;
        case sf::Event::JoystickDisconnected: break;
        case sf::Event::JoystickMoved: break;
        case sf::Event::KeyPressed:
            switch (e.key.code) {
            case sf::Keyboard::F11:
                Create(!Fullscreen);
                break;
            case sf::Keyboard::Escape:
                Game::Over = true;
                break;
            }
            break;
        case sf::Event::KeyReleased: break;
        case sf::Event::MouseButtonPressed: break;
        case sf::Event::MouseButtonReleased: break;
        case sf::Event::MouseEntered: break;
        case sf::Event::MouseLeft: break;
        case sf::Event::MouseMoved: break;
        case sf::Event::MouseWheelMoved: break;
        case sf::Event::Resized:
            AdjustView(e.size.width, e.size.height);
            break;
        case sf::Event::TextEntered: break;
        }
    }
}