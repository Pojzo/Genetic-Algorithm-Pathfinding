#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "agent.hpp"


using std::string;
using std::vector;

using sf::RenderWindow;
using sf::VideoMode;

class Canvas : public RenderWindow {
    private:
        int _WINDOW_WIDTH;
        int _WINDOW_HEIGHT;
        float _circleRadius = 5;

    public:
        Canvas(int window_width, int window_height) : 
            RenderWindow(VideoMode(window_width, window_height), "Test"),
            _WINDOW_WIDTH(window_width),
            _WINDOW_HEIGHT(window_height) {};

        int GetWidth();
        int GetHeight();
        void SetCircleRadius(float);
        void DrawPoint(float, float, sf::Color);
        void Test();
};

int run();
#endif
