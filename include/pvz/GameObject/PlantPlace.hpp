#ifndef PLANTPLACE_HPP
#define PLANTPLACE_HPP
#include "GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
class PlantPlace: public GameObject{
private:
    bool IsPlants=false;
    std::shared_ptr<GameWorld> gameworld;
public:
    PlantPlace(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,bool IsPlant,std::shared_ptr<GameWorld>gw);
    bool IsPlanted()const;
    void Init() override{}
    void Update() override{}
    void OnClick() override;
    void SetPlanted(bool t);
};

#endif