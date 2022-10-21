#include "agent.hpp"
#include <iostream>

// setters and getters

std::pair<float, float> Agent::GetPos() {
    return _pos;
}

std::pair<float, float> Agent::GetVel() {
    return _vel;
}

void Agent::SetPos(std::pair<float, float> pos) {
    _pos = pos;
}

void Agent::SetVel(std::pair<float, float> vel) {
    _vel = vel;
}

void Agent::Move() {
    _pos.first += _vel.first;
    _pos.second += _vel.second;
}
