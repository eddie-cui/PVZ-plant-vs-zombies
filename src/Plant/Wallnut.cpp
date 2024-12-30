#include "pvz/GameObject/Wallnut.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Wallnut::Wallnut(int x,int y,std::shared_ptr<GameWorld>gw):Plant(IMGID_WALLNUT,x,y,LAYER_PLANTS,60,80,ANIMID_IDLE_ANIM,4000,true,1200,gw){}
void Wallnut::Update(){
    if(Hp_Query()<=0){
        Is_dead();
    }
    if(Hp_Query()<=1200&&HasChanged==false){
        Change_Image(IMGID_WALLNUT_CRACKED);
        HasChanged = true;
    }
    //std::cout<<"Wallnut"<<Hp_Query()<<std::endl;
}
