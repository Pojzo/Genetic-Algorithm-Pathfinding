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
        sf::Vector2f _startPoint;
        sf::Vector2f _endPoint;

    public:
        Canvas(int window_width, int window_height, sf::Vector2f startPoint, sf::Vector2f endPoint) : 
            RenderWindow(VideoMode(window_width, window_height), "Test"),
            _WINDOW_WIDTH(window_width),
            _WINDOW_HEIGHT(window_height),
            _startPoint(startPoint),
            _endPoint(endPoint)
            {};

        int GetWidth();
        int GetHeight();
        sf::Vector2f GetStartPoint();
        sf::Vector2f GetEndPoint();
        void SetCircleRadius(float);
        void DrawStart();
        void DrawEnd();
        void DrawPoint(float, float, sf::Color);
        void Test();
};

int run();
#endif
