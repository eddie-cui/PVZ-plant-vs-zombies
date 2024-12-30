#include "pvz/GameObject/SeedPeashooter.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SeedPeashooter::SeedPeashooter(std::shared_ptr<GameWorld>gw) :Seed(IMGID_SEED_PEASHOOTER, 190, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 100, Player_click::Seed_Peashooter, gw) {};