#ifndef PEA_HPP
#define PEA_HPP
#include "pvz/GameObject/Attack.hpp"
class Pea:public Attack{
public:
Pea(int x,int y,std::shared_ptr<GameWorld>gw);
void Update() override;
};
#endif