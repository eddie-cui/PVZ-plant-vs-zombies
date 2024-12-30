#ifndef POLEVAULTINGZOMBIE_HPP
#define POLEVAULTINGZOMBIE_HPP
#include "pvz/GameObject/Zombie.hpp"
#include "pvz/utils.hpp"
class PoleVaultingZombie: public Zombie{
private:
bool Is_running = true;
bool Is_jumpping=false;
bool Is_Walking = false;
std::shared_ptr<GameWorld>gameworld;
int tick = 0;
public:
PoleVaultingZombie(int x,int y,std::shared_ptr<GameWorld>gw);
void Update() override;
JumperType type_query()const;
};
#endif