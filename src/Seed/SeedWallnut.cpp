#include "pvz/GameObject/SeedWallnut.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SeedWallnut::SeedWallnut(std::shared_ptr<GameWorld>gw):Seed(IMGID_SEED_WALLNUT,250,WINDOW_HEIGHT-44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,50,Player_click::Seed_Wallnut,gw){};
