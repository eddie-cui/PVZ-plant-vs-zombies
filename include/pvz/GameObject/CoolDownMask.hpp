#ifndef COOLDOWNMASK_HPP
#define COOLDOWNMASK_HPP
#include "pvz/GameObject/GameObject.hpp"
class CoolDownMask: public GameObject{
private :
int tick=0;
int target_tick;
std::shared_ptr<GameWorld>gameworld;
public:
CoolDownMask(int x,int y,std::shared_ptr<GameWorld>gw,int time);
void Update() override;
void Init() override{}
void OnClick() override;
};
#endif