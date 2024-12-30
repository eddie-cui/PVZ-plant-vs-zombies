#ifndef ATTACK_HPP
#define ATTACK_HPP
#include "pvz/GameObject/GameObject.hpp"
class Attack: public GameObject{
private:
int Harm;
std::shared_ptr<GameWorld> gameworld;
public:
Attack(ImageID image,int x,int y,int Width,int Height,int Harm,std::shared_ptr<GameWorld>gw);
int Get_harm() const;
void Init()override{}
void OnClick()override;
void Dead();
};
#endif