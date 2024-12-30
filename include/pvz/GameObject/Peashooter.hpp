#ifndef PEASHOOTER_HPP
#define PEASHOOTER_HPP
#include "pvz/GameObject/Plant.hpp"
class Peashooter :public Plant{
private:
int tick=0;
std::shared_ptr<GameWorld>gameworld;
public:
Peashooter(int x,int y,std::shared_ptr<GameWorld>gw);
void Update() override;
};
#endif