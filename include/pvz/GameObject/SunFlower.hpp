#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP

#include "pvz/GameObject/Plant.hpp"

class SunFlower:  public Plant{
private:
    int tick;
    std::shared_ptr<GameWorld> gameworld;
    int target_tick;
public:
    SunFlower(int x, int y,std::shared_ptr<GameWorld>gw) ;
    void Update() override;
    //void OnClick() override;
};
#endif