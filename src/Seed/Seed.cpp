#include "pvz/GameObject/Seed.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Seed::Seed(ImageID image,int x,int y,LayerID layer,int width,int height,AnimID animid,int sun,Player_click click_type,std::shared_ptr<GameWorld>gw):GameObject(image,x,y,layer,width,height,animid,Object_type::Other),gameworld(gw),sun_need(sun),type(click_type){};
void Seed::OnClick() {
    Player_click click = gameworld->WhatClick();
    if (click != Player_click::None) {
        return;
    }
    else {
        if (gameworld->Sun_Query() >= sun_need)
            gameworld->SetClick(type);
    }
}