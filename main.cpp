#include <iostream>

#include "canvas.hpp"
#include "population.hpp"

const int window_width = 640;
const int window_height = 640;
const int population_size = 100;

using std::cout;

int main() {
    Canvas canvas(window_width, window_height);
    Population population(canvas, population_size);
    population.CreateAgents();
    population.Simulate();
}
