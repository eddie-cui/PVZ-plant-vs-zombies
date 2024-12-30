#include "pvz/GameObject/SeedCherrybomb.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SeedCherrybomb::SeedCherrybomb(std::shared_ptr<GameWorld>gw):Seed(IMGID_SEED_CHERRY_BOMB,310,WINDOW_HEIGHT-44,LAYER_UI,50,70,ANIMID_NO_ANIMATION,50,Player_click::Seed_Cherry,gw){};
