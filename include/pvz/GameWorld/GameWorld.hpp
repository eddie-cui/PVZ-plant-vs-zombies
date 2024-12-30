#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include <list>
#include <memory>
#include <vector>
#include "pvz/Framework/WorldBase.hpp"
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameObject/Plant.hpp"
#include "pvz/GameObject/Seed.hpp"
#include "pvz/GameObject/BackGround.hpp"
#include "pvz/GameObject/PlantPlace.hpp"
#include "pvz/GameObject/SunFlower.hpp"
#include "pvz/GameObject/Sun.hpp"
#include "pvz/GameObject/Shovel.hpp"
#include "pvz/GameObject/SeedCherrybomb.hpp"
#include "pvz/GameObject/SeedPeashooter.hpp"
#include "pvz/GameObject/SeedRepeater.hpp"
#include "pvz/GameObject/SeedSunflower.hpp"
#include "pvz/GameObject/SeedWallnut.hpp"
#include "pvz/GameObject/Wallnut.hpp"
#include "pvz/GameObject/Cherrybomb.hpp"
#include "pvz/GameObject/Explosion.hpp"
#include "pvz/GameObject/Pea.hpp"
#include "pvz/GameObject/Peashooter.hpp"
#include "pvz/GameObject/Repeater.hpp"
#include "pvz/GameObject/CoolDownMask.hpp"
#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameObject/BucketHeadZombie.hpp"
#include "pvz/GameObject/RegularZombie.hpp"
#include "pvz/GameObject/PoleVaultingZombie.hpp"
#include "pvz/GameObject/Gameend.hpp"
#include "pvz/GameObject/Attack.hpp"
class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;
  void CreatePlant(std::shared_ptr<GameObject> plantPlace,Player_click t);
  void CreateSun(std::shared_ptr<GameObject> Sunflower  , Sun_Type ty);
  void DeleteObject(std::shared_ptr<GameObject> gameobject);
  void Drop_Sun();
  void Delta_Sun(int num);
  Player_click WhatClick() const;
  void SetClick(Player_click click);
  int Sun_Query() const;
  void CreateExplosion(std::shared_ptr<GameObject>Cherrybomb);
  void CreatePea(std::shared_ptr<GameObject>shooter);
  void GenerateZombie(int P1, int P2, int P3, int Total,int Zombie_num);
  bool CheckForJumper(std::shared_ptr<GameObject>Jumper) const;
  int CheckZombie(std::shared_ptr<GameObject> plant)const;
  void CheckAttack(std::shared_ptr<GameObject> zombie);
  bool ShootAllow(std::shared_ptr<GameObject> shooter)const;
  void JumperAttack(std::shared_ptr<GameObject>Jumper);
private: 
  std::list<std::shared_ptr<GameObject>> gameObjects;
  std::list<std::shared_ptr<GameObject>> toDelete;
  int Sun_num=150;
  int target_tick=randInt(63,263);
  int tick=0;
  int Tick_gz = 0;
  int tick_end = 0;
  bool gameloss = false;
  int Wave = 0;
  int target_gz = 1200;
  Player_click Now_click=Player_click::None;
  std::shared_ptr<TextBase> text_sun,text_wave,text_end;

};

#endif // !GAMEWORLD_HPP__
