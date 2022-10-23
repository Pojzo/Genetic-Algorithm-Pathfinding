#include "agent.hpp"
#include "utils.hpp"
#include <math.h>
#include <iostream>

void Agent::SetPos(float x, float y) {
    _pos.x = x;
    _pos.y = y;
}

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
    }
}

bool Agent::InBounds(int window_width, int window_height) {
    return GetPosX() > 0 && GetPosX() < window_width &&
           GetPosY() > 0 && GetPosY() < window_height;
}

void Agent::CalculateFitness(sf::Vector2f endPoint) {
    auto fit = 10000 / EucDistance(_pos, endPoint);
    _fitnessScore = pow(fit, 4);
}

Agent Agent::Crossover(Agent secondParent) {
    int crossoverIndex = rand() % _numMoves;
    Agent child(sf::Vector2f(0, 0), _numMoves);
    child._moves = new sf::Vector2f[_numMoves];
    for (int i = 0; i < crossoverIndex; i++) {
        child._moves[i] = _moves[i];
    }

    for (int i = crossoverIndex; i < _numMoves; i++) {
        child._moves[i] = secondParent._moves[i]; 
    }
    return child;
}

void Agent::Mutate(float mutationRate) {
    for (int i = 0; i < _numMoves; i++) {
        if (RandFloat(0, 1) < mutationRate) {
            _moves[i] = sf::Vector2f(RandFloat(0., 1.) * (rand() % 2 == 1 ? -1 : 1), RandFloat(0., 1.) * (rand() % 2 == 1 ? -1 : 1));
        }
    }
}

Agent Agent::AgentCopy() {
    Agent newAgent(_pos, _numMoves);
    newAgent._moves = new sf::Vector2f[_numMoves];
    for (int i = 0; i < _numMoves; i++) {
        newAgent._moves[i] = _moves[i];
    }
    return newAgent;
}
