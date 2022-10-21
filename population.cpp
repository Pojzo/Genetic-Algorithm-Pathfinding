#include "population.hpp"
#include <iostream>


template <typename T>

inline int RandInt(int a, int b) {
    return ((b - a) * ((int)rand() / RAND_MAX)) + a;
}

inline float RandFloat(float a, float b) {
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

void Population::CreateAgents() {
    for (int i = 0; i < _pop_size; i++) {
        auto posX = RandFloat(0, _canvas.GetWidth());
        auto posY = RandFloat(0, _canvas.GetHeight());

        auto velX = RandFloat(0., 1.);
        auto velY = RandFloat(0., 1.);
        _agents.push_back(Agent(posX, posY, velX, velY));
    }
}

void Population::ShowAgents() {
    for (auto agent : _agents) {
        _canvas.DrawPoint(agent.GetPosX(), agent.GetPosY(), sf::Color(0, 100, 0));
    }
}

void Population::MoveAgents() {
    for (auto &agent: _agents) {
        agent.Move(); 
    }
}

void Population::Simulate() {
    while (_canvas.isOpen()) {
        sf::Event event;
        while (_canvas.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _canvas.close();
            }
        }
        _canvas.clear(sf::Color::White);
        MoveAgents();
        ShowAgents();
        _canvas.display();
    }
    std::cout << "Koniec\n";
}
