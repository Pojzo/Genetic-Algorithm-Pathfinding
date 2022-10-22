#include "agent.hpp"
#include "utils.hpp"
#include <math.h>
#include <iostream>

void Agent::Move() {
    _pos.x += _moves[_curMove].x;
    _pos.y += _moves[_curMove++].y;
    if (_curMove >= _numMoves) {
        dead = true;
    }
}

void Agent::CreateMoves() {
    _moves = new sf::Vector2f[_numMoves];
    for (int i = 0; i < _numMoves; i++) {
        _moves[i] = sf::Vector2f(RandFloat(0., 1.) * (rand() % 2 == 1 ? -1 : 1), RandFloat(0., 1.) * (rand() % 2 == 1 ? -1 : 1));
        std::cout << _moves[i].x << std::endl;
    }
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

Agent Agent::AgentCopy() {
    Agent newAgent(_pos, _numMoves);
    newAgent._moves = new sf::Vector2f[_numMoves];
    for (int i = 0; i < _numMoves; i++) {
        _moves[i] = sf::Vector2f(RandFloat(0, 5), RandFloat(0, 5));
    }
    return newAgent;
}
