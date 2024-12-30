#ifndef SEED_HPP
#define SEED_HPP
#include "pvz/GameObject/GameObject.hpp"
class Seed: public GameObject{
private:
std::shared_ptr<GameWorld>gameworld;
int sun_need;
Player_click type;
public:
    Seed(ImageID image,int x,int y,LayerID layer,int width,int height,AnimID animid,int sun,Player_click click_type,std::shared_ptr<GameWorld>gw);
    void Update()override {};
    void Init()override{}
    void OnClick()override;

};


#endif
