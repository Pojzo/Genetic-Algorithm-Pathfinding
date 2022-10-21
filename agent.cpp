#include "agent.hpp"
#include <math.h>

void Agent::Move() {
    SetPosX(GetPosX() + GetVelX());
    SetPosY(GetPosY() + GetVelY());
}

float Agent::EucDistance(sf::Vector2f first, sf::Vector2f second) {
    auto x1 = first.x;
    auto x2 = second.x;
    auto y1 = first.y;
    auto y2 = second.y;

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool Agent::InBounds(int window_width, int window_height) {
    return GetPosX() > 0 && GetPosX() < window_width &&
           GetPosY() > 0 && GetPosY() < window_height;
}

void Agent::CalculateFitness(sf::Vector2f endPoint) {
    _fitnessScore = 10000 / EucDistance(_pos, endPoint);
}
