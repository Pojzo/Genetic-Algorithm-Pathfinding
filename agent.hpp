#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>

class Agent {
private:
    float _posX;
    float _posY;
    float _velX;
    float _velY;
    public:
        Agent(float posX, float posY, float velX, float velY) :
            _posX(posX), _posY(posY), _velX(velX), _velY(velY)
    {};
        inline float GetPosX() {return _posX;};
        inline float GetPosY() {return _posY;};
        inline void SetPosX(float value) { _posX = value;};
        inline void SetPosY(float value) {_posY = value;};

        inline float GetVelX() {return _velX;};
        inline float GetVelY() {return _velY;};
        inline void SetVelX(float value) { _velX = value;};
        inline void SetVelY(float value) {_velY = value;};

        void Move();
};

#endif
