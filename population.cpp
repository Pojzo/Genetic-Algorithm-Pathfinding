#include "population.hpp"
#include <iostream>

bool running = true;

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
        _agents.push_back(Agent(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY)));
    }
}

void Population::ShowAgents() {
    int numAlive = 0;
    for (auto agent : _agents) {
        // only show those agents who are not dead
        if (agent.dead == false) {
            numAlive++;
            _canvas.DrawPoint(agent.GetPosX(), agent.GetPosY(), sf::Color::Blue);
        }
    }
    if (numAlive == 0) {
        running = false;        
    }
}

void Population::MoveAgents() {
    for (auto &agent: _agents) {
        agent.Move(); 
        // if agent moved outside the bounds, declare him dead
        if (agent.InBounds(_canvas.GetWidth(), _canvas.GetHeight()) == false) {
            agent.dead = true; 
        }
    }
}

void Population::CalculateFitness() {
    for (auto &agent : _agents) {
        agent.CalculateFitness(_canvas.GetEndPoint());
        // std::cout << agent._fitnessScore << std::endl;
    }
}

void Population::CreateMatingPool() {
    _matingPool.clear();
    for (auto agent : _agents) {
        if (agent.dead) {
            continue;
        }
        for (int i = 0; i < (int) agent._fitnessScore; i++) {
             _matingPool.push_back(&agent); 
        }
    }
    std::cout << _matingPool.size() << std::endl;
}

void Population::Simulate() {
    while (_canvas.isOpen() && running) {
        sf::Event event;
        while (_canvas.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _canvas.close();
            }
        }
        _canvas.clear(sf::Color::White);
        _canvas.DrawStart();
        _canvas.DrawEnd();
        ShowAgents();
        MoveAgents();
        CalculateFitness();
        CreateMatingPool();
        _canvas.display();
    }
    std::cout << "Koniec\n";
}
