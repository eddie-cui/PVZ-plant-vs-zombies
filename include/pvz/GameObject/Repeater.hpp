#ifndef REPEATER_HPP
#define REPEATER_HPP
#include "pvz/GameObject/Plant.hpp"
class Repeater :public Plant{
private:
int tick=0;
std::shared_ptr<GameWorld>gameworld;
public:
Repeater(int x,int y,std::shared_ptr<GameWorld>gw);
void Update() override;
};
#endif