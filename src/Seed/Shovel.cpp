#include"pvz/GameObject/Shovel.hpp"
#include"pvz/GameWorld/GameWorld.hpp"
Shovel::Shovel(std::shared_ptr<GameWorld>gw) :Seed(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, 0, Player_click::Shovel, gw) {};
