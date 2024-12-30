#include "pvz/GameObject/Plant.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Plant::Plant(ImageID imageID = IMGID_NONE, int x = 0, int y = 0, LayerID layer = LAYER_PLANTS, int width = 40, int height = 60, AnimID animID = ANIMID_NO_ANIMATION, int hp = 1000, bool image_change = false, int image_change_hp = 0,std::shared_ptr<GameWorld>gw=nullptr) :GameObject(imageID, x, y, layer, width, height, animID,Object_type::Plant), Hp(hp), Image_change(image_change), Image_change_Hp(image_change_hp),gameworld(gw) {}
void Plant::DeltaHp(int attack){
    Hp+=attack;
}
void Plant::Is_dead(){
    gameworld->DeleteObject(shared_from_this());
}
void Plant::Change_Image(ImageID image){
    ChangeImage(image);
}
void Plant::OnClick(){
    if(gameworld->WhatClick()==Player_click::Shovel){
        gameworld->SetClick(Player_click::None);
        gameworld->DeleteObject(shared_from_this());
    }
    else{
        gameworld->SetClick(Player_click::None);
    }
}
int Plant::Hp_Query()const{
    return Hp;
}