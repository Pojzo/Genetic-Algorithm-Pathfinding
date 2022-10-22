#include <iostream>

#include "canvas.hpp"
#include "population.hpp"

const int window_width = 640;
const int window_height = 640;
const int population_size = 100;
const sf::Vector2f startPoint(310, 590);
const sf::Vector2f endPoint(310, 0);

int main() {
    srand(time(NULL));
    Canvas canvas(window_width, window_height, startPoint, endPoint);
    Population population(canvas, population_size);
    population.CreateAgents();
    population.Simulate();
}
