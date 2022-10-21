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

    public:
        Population(Canvas &canvas, int pop_size) :
            _canvas(canvas),
            _pop_size(pop_size) {};
        inline int RandInt(int, int);
        inline float rRandFloat(float, float);
        void CreateAgents();
        void ShowAgents();
        void MoveAgents();
        void Simulate();
};
#endif
