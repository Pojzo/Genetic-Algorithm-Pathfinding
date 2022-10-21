#include "population.hpp"
#include <iostream>

// return random pair of values in specified range
inline std::pair<int, int> RandomPairInt(int low1, int low2, int high1, int high2) {
    auto randFirst = rand() % (high1 - low1) + low1;
    auto randSecond = rand() % (high2 - low2) + low2;
    return {randFirst, randSecond};
}

void Population::CreateAgents() {
    for (int i = 0; i < _pop_size; i++) {
        auto pos = RandomPairInt(0, 0, _canvas.GetWidth(), _canvas.GetHeight());
        auto vel = RandomPairInt(0, 0, 5, 5);
        Agent agent(pos, vel);
        _agents.push_back(agent);
    }
}

void Population::ShowAgents() {
    for (auto agent : _agents) {
        auto pos = agent.GetPos();
        _canvas.DrawPoint(pos.first, pos.second, sf::Color(0, 100, 0));
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
        ShowAgents();
        _canvas.display();
    }
}
