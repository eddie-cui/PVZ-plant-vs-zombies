#ifndef WALLNUT_HPP
#define WALLNUT_HPP
#include "pvz/GameObject/Plant.hpp"
class Wallnut: public Plant{
private:
//std::shared_ptr<GameWorld>gameworld;
	bool HasChanged = false;
public:
Wallnut(int x,int y,std::shared_ptr<GameWorld>gw);
//void OnClick() override;
void Update() override;
};
#endif