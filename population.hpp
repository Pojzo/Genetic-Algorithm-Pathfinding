#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "agent.hpp"
#include "canvas.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;

class Population {
    private:
        Canvas &_canvas;
        int _pop_size;
        vector<Agent> _agents;
        float _crossoverRate;
        float _mutationRate;

    public:
        Population(Canvas &canvas, int pop_size, float crossoverRate = 0.5, float mutationRate = 0.05) :
            _canvas        (canvas),
            _pop_size      (pop_size),
            _crossoverRate (crossoverRate),
            _mutationRate  (mutationRate) {};

        void CreateAgents();
        void ShowAgents();
        void MoveAgents();
        void Simulate();

        void CalculateFitness();
        void CreateMatingPool();
        void Crossover();
        void Mutate();

        vector<Agent*> matingPool;

};
#endif
