#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
#include "pvz/GameObject/Attack.hpp"
class Explosion:public Attack{
private:
    int tick;
public:
    Explosion(int x,int y,std::shared_ptr<GameWorld>gw);
    void Update() override;
};

#endif