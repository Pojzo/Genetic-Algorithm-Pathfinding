#include "population.hpp"
#include "utils.hpp"
#include <iostream>

bool running = true;
bool allDead = false;
const int numMoves = 500;

void Population::CreateAgents() {
    for (int i = 0; i < _pop_size; i++) {
        // auto posX = RandFloat(0, _canvas.GetWidth());
        // auto posY = RandFloat(0, _canvas.GetHeight());
        float posX = _canvas.GetWidth() / 2;
        float posY = _canvas.GetHeight() - 20;
        Agent agent(sf::Vector2f(posX, posY), numMoves);
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
    int numAlive = 0;
    for (auto &agent: _agents) {
        if (agent.dead) {
            continue;
        }
        numAlive++;
        // std::cout << agent.GetPosX() << " " << agent.GetPosY() << std::endl;
        agent.Move(); 
        // if agent moved outside the bounds, declare him dead
        if (agent.InBounds(_canvas.GetWidth(), _canvas.GetHeight()) == false) {
            agent.dead = true; 
        }
    }
    // std::cout << "Num alive " << numAlive << std::endl;
}

float Population::GetFitnessMax() {
    float fitness = 0;
    for (auto agent :  _agents) {
        fitness += agent._fitnessScore;
    }
    return fitness;
}

float Population::GetFitnessMean() {
    return GetFitnessMax() / _pop_size;
}


void Population::CalculateFitness() {
    fitnessSum = 0;
    for (auto &agent : _agents) {
        agent.CalculateFitness(_canvas.GetEndPoint());
        fitnessSum += agent._fitnessScore;
    }
}

void Population::CreateMatingPool() {
    matingPool.clear();
    int agentNum = 0;
    for (auto agent : _agents) {
        for (int i = 0; i < (int) agent._fitnessScore; i++) {
             matingPool.push_back(agentNum); 
        }
        agentNum++;
    }
}

void Population::Crossover() {
    vector<Agent> newAgents;
    std::cout << "Mating pool size  " << matingPool.size() << std::endl;
    for (long unsigned int i = 0; i < _agents.size(); i++) {
        if (RandFloat(0, 1) < _crossoverRate) {
            Agent agent = SelectParent();
            newAgents.push_back(agent);
        }
        else {
            newAgents.push_back(_agents[i].AgentCopy());
        }
    }
    std::copy(newAgents.begin(), newAgents.end(), _agents.begin());
    // std::cout << _agents.size() << std::endl;
}

Agent Population::SelectParent() {
    float rand = RandFloat(0, fitnessSum);  
    float runningSum = 0;
    for (int i = 0; i < _pop_size; i++) {
        runningSum += _agents[i]._fitnessScore; 
        if (runningSum > rand) {
            return _agents[i].AgentCopy(); 
        }
    }
    return _agents[_pop_size - 1].AgentCopy();
}

void Population::Mutate() {
    for (auto &agent : _agents) {
        agent.Mutate(0.05);
    }
}

void Population::ResetAgents() {
    float posX = _canvas.GetWidth() / 2;
    float posY = _canvas.GetHeight() - 20;
    for (auto &agent : _agents) {
        agent.SetPos(posX, posY);  
    }
}


void Population::Simulate() {
    const int numGenerations = 100;
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
            std::cout << "Max fitness: " << GetFitnessMax() << std::endl;
            std::cout << "Mean fitness: " << GetFitnessMean() << std::endl;
            // CreateMatingPool();
            Crossover();
            Mutate();
            ResetAgents();
        }
        running = false;
    }
}
