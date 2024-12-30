#ifndef PLANT_HPP
#define PLANT_HPP

#include "pvz/GameObject/GameObject.hpp"

class Plant:public GameObject{
private:
    int Hp;
    bool Image_change=false;
    int Image_change_Hp;
    std::shared_ptr<GameWorld> gameworld;
public:
    Plant(ImageID imageID, int x , int y , LayerID layer , int width, int height , AnimID animID , int hp , bool image_change , int image_change_hp ,std::shared_ptr<GameWorld>gw);
    void Init() override {}
    //void Update()override {}
    void OnClick() override ;
    void DeltaHp(int attack);
    void Is_dead();
    void Change_Image(ImageID image);
    int Hp_Query()const;
};
#endif