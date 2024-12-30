#include "pvz/GameObject/PlantPlace.hpp"
#include "pvz/utils.hpp"
PlantPlace::PlantPlace(ImageID imageID=IMGID_NONE, int x=FIRST_COL_CENTER, int y=FIRST_ROW_CENTER, LayerID layer=LAYER_UI, int width=40, int height=60, AnimID animID=ANIMID_NO_ANIMATION,bool IsPlant=false,std::shared_ptr<GameWorld>gw=nullptr) :GameObject(imageID, x, y, layer, width, height, animID,Object_type::Other), IsPlants(IsPlant),gameworld(gw) {}
bool PlantPlace::IsPlanted()const{
    return IsPlants;
}
void PlantPlace::OnClick(){
    std::cout << this->GetX() << " " <<this->GetY()<< std::endl;
    if (gameworld ) {
        auto sharedThis = PlantPlace::shared_from_this();
        auto ty = gameworld->WhatClick();
        if (ty != Player_click::None && ty != Player_click::Shovel) {
            gameworld->CreatePlant(sharedThis,ty);
            IsPlants = true;
        }
    }
    gameworld->SetClick(Player_click::None);
}
void PlantPlace::SetPlanted(bool t) {
    IsPlants = t;
}