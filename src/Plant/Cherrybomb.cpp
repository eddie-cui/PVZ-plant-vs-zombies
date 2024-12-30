#include "pvz/GameObject/Cherrybomb.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Cherrybomb::Cherrybomb(int x,int y,std::shared_ptr<GameWorld>gw):Plant(IMGID_CHERRY_BOMB,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,4000,false,0,gw),gameworld(gw){}
void Cherrybomb::Update(){
    tick++;
    if(tick==15)
    {
        gameworld->CreateExplosion(shared_from_this());
        Is_dead();
    }
}
