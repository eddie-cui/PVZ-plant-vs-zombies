#include "pvz/GameObject/Pea.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Pea::Pea(int x,int y,std::shared_ptr<GameWorld>gw):Attack(IMGID_PEA,x,y,28,28,20,gw){}
void Pea::Update(){
    int x_old=GetX();
    int y_old=GetY();
    if(x_old>=WINDOW_WIDTH){
        Dead();
        //std::cout << "deletePea" << std::endl;
    }
    else{
        MoveTo(x_old+8,y_old);
        //std::cout << "move" << std::endl;
    }
}