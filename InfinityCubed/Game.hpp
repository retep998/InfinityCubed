#pragma once
class Game
{
private:
    bool over;
    Window window;
public:
    Game() :
        over {false},
        window { }
    {
        while (!isOver()) loop();
    }
    ~Game()
    {

    }
    bool isOver()
    {
        return over;
    }
    Window & getWindow()
    {
        return window;
    }
private:
    void loop()
    {
    }
};