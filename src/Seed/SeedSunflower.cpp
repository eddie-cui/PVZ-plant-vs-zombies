#include "pvz/GameObject/SeedSunflower.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SeedSunflower::SeedSunflower(std::shared_ptr<GameWorld>gw):Seed(IMGID_SEED_SUNFLOWER,130,WINDOW_HEIGHT-44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,50,Player_click::Seed_Sunflower,gw){};
