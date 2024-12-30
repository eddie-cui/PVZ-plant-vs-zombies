#ifndef REGULARZOMBIE_HPP
#define REGULARZOMBIE_HPP
#include "pvz/GameObject/Zombie.hpp"
class RegularZombie:public Zombie{
public:
RegularZombie(int x,int y,std::shared_ptr<GameWorld>gw);
};
#endif