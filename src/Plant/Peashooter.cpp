#include "pvz/GameObject/Peashooter.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Peashooter::Peashooter(int x,int y,std::shared_ptr<GameWorld>gw):Plant(IMGID_PEASHOOTER,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,300,false,0,gw),gameworld(gw){}
void Peashooter::Update(){
    if(Hp_Query()<=0){
        Is_dead();
    }
    if (gameworld->ShootAllow(shared_from_this()) == true) {
        tick++;
        if (tick == 30) {
            gameworld->CreatePea(shared_from_this());
            tick = 0;
        }
    }
    else {
        tick = 0;
    }
}