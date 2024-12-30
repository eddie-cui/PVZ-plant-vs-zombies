#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include "pvz/GameObject/GameObject.hpp"
class Zombie : public GameObject{
private:
    int Hp;
    bool image_change=false;
    bool Is_eating=false;
    std::shared_ptr<GameWorld> gameworld;
    int img_change_Hp=0;
    ImageID image_new;
    bool HasChanged = false;
public:
Zombie(ImageID image,int x,int y,int Hp,bool image_change,AnimID animation,std::shared_ptr<GameWorld>gw,Object_type type,int img_change_hp,ImageID img);
void Update() override;
void Init() override{}
void OnClick() override;
void Set_eat(bool eat);
void Delta_Hp(int attack);
bool Eating_query()const;
int Hp_query()const;
};
#endif