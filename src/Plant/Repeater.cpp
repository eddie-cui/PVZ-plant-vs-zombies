#include "pvz/GameObject/Repeater.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Repeater::Repeater(int x,int y,std::shared_ptr<GameWorld>gw):Plant(IMGID_REPEATER,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,300,false,0,gw),gameworld(gw){}
void Repeater::Update(){
    if(Hp_Query()<=0){
        Is_dead();
    }
    if (gameworld->ShootAllow(shared_from_this()) == true) {
        tick++;
        if (tick == 25) {
            gameworld->CreatePea(shared_from_this());
        }
        if (tick == 30) {
            gameworld->CreatePea(shared_from_this());
            tick = 0;
        }
    }
    else {
        tick = 0;
    }
}