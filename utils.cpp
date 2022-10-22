#include "utils.hpp"
#include <cstdlib>

int RandInt(int low, int high) {
    return rand() % (high - low) + low;
}

float RandFloat(float a, float b) {
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}
