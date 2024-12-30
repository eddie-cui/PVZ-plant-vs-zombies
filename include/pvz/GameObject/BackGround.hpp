#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include "GameObject.hpp"
class BackGround: public GameObject{
public:
    BackGround(ImageID imageID=IMGID_BACKGROUND, int x=WINDOW_WIDTH/2, int y=WINDOW_HEIGHT/2, LayerID layer=LAYER_BACKGROUND, int width=WINDOW_WIDTH, int height=WINDOW_HEIGHT, AnimID animID=ANIMID_NO_ANIMATION,std::shared_ptr<GameWorld>gw=nullptr);
    void Init() override {}
    void Update() override{}
    void OnClick() override;
private:
    std::shared_ptr<GameWorld> gameworld;
};
#endif