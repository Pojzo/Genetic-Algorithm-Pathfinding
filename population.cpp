#include "population.hpp"
#include "utils.hpp"
#include <iostream>

bool running = true;
bool allDead = false;
const int numMoves = 1000;

void Population::CreateAgents() {
    for (int i = 0; i < _pop_size; i++) {
        // auto posX = RandFloat(0, _canvas.GetWidth());
        // auto posY = RandFloat(0, _canvas.GetHeight());
        float posX = _canvas.GetWidth() / 2;
        float posY = _canvas.GetHeight() - 20;
        Agent agent = Agent(sf::Vector2f(posX, posY), numMoves);
        agent.CreateMoves();
        _agents.push_back(agent);
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
        allDead = true;
        // running = false;        
    }
}

void Population::MoveAgents() {
    for (auto &agent: _agents) {
        if (agent.dead) {
            continue;
        }
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
    matingPool.clear();
    for (auto agent : _agents) {
        if (agent.dead) {
            continue;
        }
        for (int i = 0; i < (int) agent._fitnessScore; i++) {
             matingPool.push_back(&agent); 
        }
    }
    std::cout << matingPool.size() << std::endl;
}

void Population::Crossover() {
    vector<Agent> newAgents;
    for (auto agent : _agents) {
        if (RandFloat(0, 1) < _crossoverRate) {
            int firstIndex = RandInt(0, matingPool.size());
            int secondIndex = RandInt(0, matingPool.size());
            Agent *firstParent = matingPool[firstIndex];
            Agent *secondParent = matingPool[firstIndex];
            (void) firstIndex;
            (void) secondIndex;
            (void) firstParent; 
            (void) secondParent;
        }
        else {
            Agent agentCopy = agent.AgentCopy();
            newAgents.push_back(agentCopy);
        }
    }
}
void Population::Mutate() {

}

void Population::Simulate() {
    const int numGenerations = 1;
    while (_canvas.isOpen() && running) {
        for (int i = 0; i < numGenerations; i++) {
            allDead = false;
            while (!allDead) {
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
                _canvas.display();

            }
            std::cout << "All agents are dead in " << i << " generation\n";
            CalculateFitness();
            CreateMatingPool();
            // Crossover();
            // Mutate
        }
    }
    std::cout << "Koniec\n";
}
