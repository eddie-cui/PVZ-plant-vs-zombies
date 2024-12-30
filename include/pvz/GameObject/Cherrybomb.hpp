#ifndef CHERRYBOMB_HPP
#define CHERRYBOMB_HPP
#include "pvz/GameObject/Plant.hpp"
class Cherrybomb: public Plant{
private:
    std::shared_ptr<GameWorld>gameworld;
    int tick=0;
public:
Cherrybomb(int x,int y,std::shared_ptr<GameWorld>gw);
//void OnClick() override;
void Update() override;
};

#endif