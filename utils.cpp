#include "utils.hpp"
#include <cstdlib>
#include <math.h>

int RandInt(int low, int high) {
    return rand() % (high - low) + low;
}

float RandFloat(float a, float b) {
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

float EucDistance(sf::Vector2f first, sf::Vector2f second) {
    auto x1 = first.x;
    auto x2 = second.x;
    auto y1 = first.y;
    auto y2 = second.y;

    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
