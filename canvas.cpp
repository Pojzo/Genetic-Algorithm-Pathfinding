#include <iostream>
// #include <SFML/Graphics.hpp>
// its already included in the header

#include "canvas.hpp"

void Canvas::Test() {
}

int Canvas::GetWidth() {
    return _WINDOW_WIDTH;
}

int Canvas::GetHeight() {
    return _WINDOW_HEIGHT;
}

void Canvas::SetCircleRadius(float radius) {
    if (radius < 0) {
        std::cerr << "Radius must be positive\n";
        return;
    }
    _circleRadius = radius;
}

void Canvas::DrawStart() {
    sf::CircleShape startCircle(25);
    startCircle.setFillColor(sf::Color::Green);
    startCircle.setPosition(_startPoint);
    draw(startCircle);
}

void Canvas::DrawEnd() {
    sf::CircleShape endCircle(25);
    endCircle.setFillColor(sf::Color::Red);
    endCircle.setPosition(_endPoint);
    draw(endCircle);
}

void Canvas::DrawPoint(float pos_x, float pos_y, sf::Color color) {
    sf::CircleShape shape(_circleRadius);
    shape.setFillColor(color);
    shape.setPosition(pos_x, pos_y);
    draw(shape);
}
