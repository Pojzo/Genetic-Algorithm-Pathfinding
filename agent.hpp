#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>
#include <SFML/Graphics.hpp>

class Agent {
private:
    sf::Vector2f _pos;
    sf::Vector2f _vel;

    public:
        Agent(sf::Vector2f pos, sf::Vector2f vel) :
            _pos(pos), _vel(vel)
    {};
        inline float GetPosX() {return _pos.x;};
        inline float GetPosY() {return _pos.y;};
        inline void SetPosX(float value) { _pos.x = value;};
        inline void SetPosY(float value) { _pos.y = value;};

        inline float GetVelX() {return _vel.x;};
        inline float GetVelY() {return _vel.y;};
        inline void SetVelX(float value) { _vel.x = value;};
        inline void SetVelY(float value) { _vel.y = value;};

        void Move();
        bool InBounds(int, int);
        float EucDistance(sf::Vector2f, sf::Vector2f);
        void CalculateFitness(sf::Vector2f);

        bool dead = false;
        float _fitnessScore = 0;
};

#endif
