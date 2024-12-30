#include "pvz/GameObject/SeedRepeater.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SeedRepeater::SeedRepeater(std::shared_ptr<GameWorld>gw):Seed(IMGID_SEED_REPEATER,370,WINDOW_HEIGHT-44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,200,Player_click::Seed_Repeater,gw){};
