#ifndef BUCKETHEADZOMBIE_HPP
#define BUCKETHEADZOMBIE_HPP
#include "pvz/GameObject/Zombie.hpp"
class BucketHeadZombie:public Zombie{
public:
BucketHeadZombie(int x,int y,std::shared_ptr<GameWorld>gw);
};
#endif