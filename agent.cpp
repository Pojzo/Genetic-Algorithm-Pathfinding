#include "agent.hpp"
#include <iostream>

void Agent::Move() {
    SetPosX(GetPosX() + GetVelX());
    SetPosY(GetPosY() + GetVelY());
}
