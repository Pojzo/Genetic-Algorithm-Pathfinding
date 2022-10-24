#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>

class Agent {
private:
    sf::Vector2f _pos;
    sf::Vector2f *_moves = NULL;
    int _numMoves;
    int _curMove = 0;
    public:
        Agent(sf::Vector2f pos, int numMoves) :
            _pos(pos),
            _numMoves(numMoves)
    {};
        inline float GetPosX() {return _pos.x;};
        inline float GetPosY() {return _pos.y;};
        void SetPos(float x, float y);
        int GetNumMoves() {return _numMoves;};
        void CreateMoves();
        void Move();
        bool InBounds(int, int);
        void CalculateFitness(sf::Vector2f);
        Agent Crossover(Agent);
        void Mutate(float);

        bool dead = false;
        bool reachedGoal = false;
        float _fitnessScore = 0;

        Agent AgentCopy();
};

#endif
