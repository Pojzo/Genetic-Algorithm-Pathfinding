#include "agent.hpp"
#include <iostream>

void Agent::Move() {
    SetPosX(GetPosX() + GetVelX());
    SetPosY(GetPosY() + GetVelY());
}

bool Agent::InBounds(int window_width, int window_height) {
    return GetPosX() > 0 && GetPosX() < window_width &&
           GetPosY() > 0 && GetPosY() < window_height;
}
