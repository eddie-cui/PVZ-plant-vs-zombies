#include "pvz/GameObject/SunFlower.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
SunFlower::SunFlower(int x, int y,std::shared_ptr<GameWorld>gw) :Plant(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, 300, false, 0,gw), tick(0) ,gameworld(gw){ target_tick = randInt(30, 600); }
void SunFlower::Update() {
    if (Hp_Query() <= 0)
    {
        Is_dead();
    }
	tick++;
	if (tick >= target_tick) {
        std::cout << this->GetX() << " " << this->GetY() << std::endl;
        if (gameworld) {
            auto sharedThis = SunFlower::shared_from_this();
            gameworld->CreateSun(sharedThis, Sun_Type::Generate );
        }
        tick = 0;
        target_tick = 600;
	}
}
