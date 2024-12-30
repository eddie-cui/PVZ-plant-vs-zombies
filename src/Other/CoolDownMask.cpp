#include "pvz/GameObject/CoolDownMask.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
CoolDownMask::CoolDownMask(int x,int y, std::shared_ptr<GameWorld>gw,int time):GameObject(IMGID_COOLDOWN_MASK,x,y,LAYER_COOLDOWN_MASK,50,70,ANIMID_NO_ANIMATION,Object_type::Other),gameworld(gw),target_tick(time){}
void CoolDownMask::Update(){
    tick++;
    if(tick==target_tick){
        gameworld->DeleteObject(shared_from_this());
    }
}
void CoolDownMask::OnClick() {
    gameworld->SetClick(Player_click::None);
}