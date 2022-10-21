#ifndef AGENT_HPP
#define AGENT_HPP

#include <utility>

class Agent {
private:
        std::pair <float, float> _pos;
        std::pair <float, float> _vel;
    public:
        Agent(std::pair<float, float> pos, 
              std::pair<float, float> vel) :
         _pos(pos),
         _vel(vel)
    {};
        std::pair<float, float> GetPos();
        std::pair<float, float> GetVel();

        void SetPos(std::pair<float, float>);
        void SetVel(std::pair<float, float>);

        void Move();
};

#endif
