#include "population.hpp"
#include "utils.hpp"
#include <iostream>

bool running = true;
bool allDead = false;
const int numMoves = 300;

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
            /*
            int firstIndex = RandInt(0, matingPool.size());
            int secondIndex = RandInt(0, matingPool.size());
            Agent firstParent = _agents[matingPool[firstIndex]];
            Agent secondParent = _agents[matingPool[secondIndex]];
            Agent child = firstParent.Crossover(secondParent);
            newAgents.push_back(child);
            */
            int index = RandInt(0, matingPool.size());
            newAgents.push_back(_agents[matingPool[index]].AgentCopy());
        }
        else {
            // int parentIndex = RandInt(0, matingPool.size());
            // Agent agentCopy = _agents[matingPool[parentIndex]].AgentCopy();
            // newAgents.push_back(agentCopy);
            newAgents.push_back(_agents[i].AgentCopy());
        }
    }
    std::copy(newAgents.begin(), newAgents.end(), _agents.begin());
    // std::cout << _agents.size() << std::endl;
}
void Population::Mutate() {
    for (auto &agent : _agents) {
        agent.Mutate(0.02);
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
    const int numGenerations = 10;
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
            float maxFitness = 0;
            for (auto agent : _agents) {
                if (agent._fitnessScore > maxFitness) {
                    maxFitness = agent._fitnessScore;
                }
            }
            std::cout << "Max fitness: " << maxFitness << std::endl;
            CreateMatingPool();
            Crossover();
            Mutate();
            ResetAgents();
        }
        running = false;
    }
}
