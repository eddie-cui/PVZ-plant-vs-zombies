#include "pvz/GameObject/BackGround.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
BackGround::BackGround(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, std::shared_ptr<GameWorld>gw)
    : GameObject(imageID, x, y, layer, width, height, animID,Object_type::Other) ,gameworld(gw){
}
void BackGround::OnClick() {
    gameworld->SetClick(Player_click::None);
}