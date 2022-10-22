#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>
#include <SFML/Graphics.hpp>

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
        void CreateMoves();
        void Move();
        bool InBounds(int, int);
        float EucDistance(sf::Vector2f, sf::Vector2f);
        void CalculateFitness(sf::Vector2f);

        bool dead = false;
        float _fitnessScore = 0;

        Agent AgentCopy();
};

#endif
