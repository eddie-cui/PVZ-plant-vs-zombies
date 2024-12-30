#include "pvz/GameObject/Attack.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Attack::Attack(ImageID image,int x,int y,int Width,int Height,int Harm,std::shared_ptr<GameWorld>gw):GameObject(image,x,y,LAYER_PROJECTILES,Width,Height,ANIMID_NO_ANIMATION,Object_type::Attack),Harm(Harm),gameworld(gw){}
int Attack::Get_harm()const{
    return Harm;
}
void Attack::Dead() {
    gameworld->DeleteObject(shared_from_this());
}
void Attack::OnClick() {
    gameworld->SetClick(Player_click::None);
}