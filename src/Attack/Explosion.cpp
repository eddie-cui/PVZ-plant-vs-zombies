#include "pvz/GameObject/Explosion.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Explosion::Explosion(int x,int y,std::shared_ptr<GameWorld>gw):Attack(IMGID_EXPLOSION,x,y,3*LAWN_GRID_WIDTH,3*LAWN_GRID_HEIGHT,40000,gw),tick(0){}
void Explosion::Update(){
    tick++;
    if(tick==3){
        Dead();
    }
}