#ifndef SUH_HPP
#define SUH_HPP
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
class Sun: public GameObject{
private:
    Sun_Type type;
    int tick;
    int speed;
    int ground;
    std::shared_ptr<GameWorld> gameworld;
public:
    Sun(int x, int y, Sun_Type t,std::shared_ptr<GameWorld>gw);
    void Init() override{}
    void Update() override;
    void OnClick() override;
    void dead();
};


#endif