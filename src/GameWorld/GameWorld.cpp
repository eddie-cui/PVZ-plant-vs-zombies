#include "pvz/GameWorld/GameWorld.hpp"
#include <vector>
GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  // YOUR CODE HERE
  //GameObject::gameworld = shared_from_this();
  std::shared_ptr<GameObject> background = std::make_shared<BackGround>(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,  LAYER_BACKGROUND,  WINDOW_WIDTH,  WINDOW_HEIGHT, ANIMID_NO_ANIMATION,shared_from_this());
  gameObjects.push_back(background);
  for(int colx=FIRST_COL_CENTER;colx<=(FIRST_COL_CENTER+(LAWN_GRID_WIDTH*8));colx+=LAWN_GRID_WIDTH)
  {
    for(int rowy=FIRST_ROW_CENTER;rowy<=(FIRST_ROW_CENTER+(LAWN_GRID_HEIGHT*4));rowy+=LAWN_GRID_HEIGHT)
    {
      std::shared_ptr<GameObject> plantplace = std::make_shared<PlantPlace>(IMGID_NONE,colx,rowy,LAYER_UI,60,80,ANIMID_NO_ANIMATION,false,shared_from_this());
      gameObjects.push_back(plantplace);
    }
  }
  std::shared_ptr<GameObject> SeedCherry=std::make_shared<SeedCherrybomb>(shared_from_this());
  gameObjects.push_back(SeedCherry);
  std::shared_ptr<GameObject> SP=std::make_shared<SeedPeashooter>(shared_from_this());
  gameObjects.push_back(SP);
  std::shared_ptr<GameObject> SR=std::make_shared<SeedRepeater>(shared_from_this());
  gameObjects.push_back(SR);
  std::shared_ptr<GameObject> SS=std::make_shared<SeedSunflower>(shared_from_this());
  gameObjects.push_back(SS);
  std::shared_ptr<GameObject> Sw=std::make_shared<SeedWallnut>(shared_from_this());
  gameObjects.push_back(Sw);
  std::shared_ptr<GameObject> sh=std::make_shared<Shovel>(shared_from_this());
  gameObjects.push_back(sh);
}

LevelStatus GameWorld::Update() {
    text_sun = std::make_shared<TextBase>(62, WINDOW_HEIGHT - 80, std::to_string(Sun_num), 0, 0, 0, true);
    text_wave = std::make_shared<TextBase>(WINDOW_WIDTH-10, 3, std::to_string(Wave), 0, 0, 0, true);
  // YOUR CODE HERE
    tick++;
    Tick_gz++;
    int P1, P2, P3,Total;
    P1 = 20;
    if (Tick_gz > target_gz)
    {
        Wave ++;
        int Zombie_num = (Wave + 15) / 10;
        P2 = 2 * std::max(Wave - 8, 0);
        P3 = 3 * std::max(Wave - 15, 0);
        Total = P1 + P2 + P3;
        GenerateZombie(P1, P2, P3, Total, Zombie_num);
        Tick_gz = 0;
        target_gz = std::max(150, 600 - 20 * Wave);
    }
    if (tick >= target_tick) {
        std::cout << "drop sun" << std::endl;
        Drop_Sun();
        tick = 0;
        target_tick = 300;
    }
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        if ((*it)->Type_query() == Object_type::Plant) {
            int count = CheckZombie(*it);
            std::shared_ptr<Plant> plant = std::dynamic_pointer_cast<Plant>(*it);
            if (plant) {
                plant->DeltaHp(-count * 3);
            }
        }
        if ((*it)->GetX() <= 0&&gameloss==false) {
            gameloss = true;
        }
    }
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        if ((*it)->Type_query() == Object_type::Zombie) {
            CheckAttack(*it);
        }
        if((*it)->Type_query() == Object_type::Jump){
            JumperAttack(*it);
        }
    }
    for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
        (*it)->Update();
        if (!(*it)->IsValid()) {
            it = gameObjects.erase(it); 
        }
        else {
            ++it;
        }
    }
    if (gameloss == true) {
        text_end = std::make_shared<TextBase>(WINDOW_WIDTH / 3+65, 52, std::to_string(Wave), 1, 1, 1, true);
    return LevelStatus::LOSING;
    }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
    gameObjects.clear();
    toDelete.clear();
    Sun_num = 150;
    target_tick = randInt(63, 263);
    tick = 0;
    Tick_gz = 0;
    tick_end = 0;
    gameloss = false;
    target_gz = 1200;
    Now_click = Player_click::None;
    Wave = 0;
    text_end.reset();
    text_sun.reset();
    text_wave.reset();

}

void GameWorld::CreatePlant(std::shared_ptr<GameObject> plantPlaceptr,Player_click t){
    int x = plantPlaceptr->GetX();
    int y = plantPlaceptr->GetY();
    std::shared_ptr<GameObject> plant;
    std::shared_ptr<GameObject> cooldown;
    switch (t) {
        case Player_click::Seed_Sunflower:
            plant = std::make_shared<SunFlower>(x, y, shared_from_this());
            Sun_num -= 50;
            cooldown =std::make_shared<CoolDownMask>(130,WINDOW_HEIGHT-44,shared_from_this(),240);
            std::cout << Sun_num << std::endl;
            break;
        case Player_click::Seed_Wallnut:
            plant = std::make_shared<Wallnut>(x, y, shared_from_this());
            Sun_num -= 50;
            cooldown =std::make_shared<CoolDownMask>(250,WINDOW_HEIGHT-44,shared_from_this(),900);
            std::cout << Sun_num << std::endl;
            break;
         case Player_click::Seed_Cherry:
             plant = std::make_shared<Cherrybomb>(x, y, shared_from_this());
             Sun_num -= 150;
             cooldown =std::make_shared<CoolDownMask>(310,WINDOW_HEIGHT-44,shared_from_this(),1200);
             break;
         case Player_click::Seed_Repeater:
             plant = std::make_shared<Repeater>(x, y, shared_from_this());
             Sun_num -= 200;
             cooldown =std::make_shared<CoolDownMask>(370,WINDOW_HEIGHT-44,shared_from_this(),240);
             break;
         case Player_click::Seed_Peashooter:
             plant = std::make_shared<Peashooter>(x, y, shared_from_this());
             Sun_num -= 100;
             cooldown =std::make_shared<CoolDownMask>(190,WINDOW_HEIGHT-44,shared_from_this(),240);
             break;
        default:
            std::cerr << "Unknown plant type" << std::endl;
            return;
    }
    gameObjects.push_back(plant);
    gameObjects.push_back(cooldown);
}
void GameWorld::CreateSun(std::shared_ptr<GameObject> Sunflower,Sun_Type ty) {
    int x = Sunflower->GetX();
    int y = Sunflower->GetY();
    std::shared_ptr<GameObject> plant = std::make_shared<Sun>(x, y, ty,shared_from_this());
    gameObjects.push_back(plant);
}
void GameWorld::DeleteObject(std::shared_ptr<GameObject> obj) {
    std::cout << "start delete" << std::endl;
    obj->Invalidate();
    std::cout << "delete" << std::endl;
}   
void GameWorld::Delta_Sun(int num) {
    Sun_num+= num;
    std::cout << Sun_num << std::endl;
}
void GameWorld::Drop_Sun() {
    int x = randInt(75, WINDOW_WIDTH - 75);
    int y = WINDOW_HEIGHT - 1;
    std::shared_ptr<GameObject> sun = std::make_shared<Sun>(x, y, Sun_Type::Drop,shared_from_this());
    gameObjects.push_back(sun);
}
Player_click GameWorld::WhatClick() const{
    return Now_click;
}
void GameWorld::SetClick(Player_click click) {
    Now_click = click;
    if (click == Player_click::Shovel) {
        std::cout << "Shovel" << std::endl;
    }
    else if (click == Player_click::Seed_Cherry) {
        std::cout << "Seed_Cherry" << std::endl;
    }
    else if (click == Player_click::Seed_Peashooter) {
        std::cout << "Seed_Peashooter" << std::endl;
    }
    else if (click == Player_click::Seed_Sunflower) {
        std::cout << "Seed_Sunflower" << std::endl;
    }
    else if (click == Player_click::Seed_Repeater) {
        std::cout << "Seed_Repeater" << std::endl;
    }
    else if (click == Player_click::Seed_Wallnut) {
        std::cout << "Seed_Wallnut" << std::endl;
    }
    else if (click == Player_click::None) {
        std::cout << "None" << std::endl;
    }
}
int GameWorld::Sun_Query() const{
    return Sun_num;
}
void GameWorld::CreateExplosion(std::shared_ptr<GameObject>Cherrybomb){
  int x = Cherrybomb->GetX();
  int y = Cherrybomb->GetY();
  std::shared_ptr<GameObject> Ex = std::make_shared<Explosion>(x,y,shared_from_this());
  gameObjects.push_back(Ex);
}
void GameWorld::CreatePea(std::shared_ptr<GameObject>shooter){
  int x=shooter->GetX()+30;
  int y=shooter->GetY()+20;
  std::cout << "start make" << std::endl;
  std::shared_ptr<GameObject> Pe=std::make_shared<Pea>(x,y,shared_from_this());
  gameObjects.push_back(Pe);
  std::cout << "made" << std::endl;
}
void GameWorld::GenerateZombie(int P1, int P2, int P3, int Total,int Zombie_num) {
    for (int i = 1; i <= Zombie_num; i++)
    {
        std::shared_ptr<GameObject> zombie;
        int Temp = randInt(1, Total);
        if (Temp <= P1) {
            zombie = std::make_shared<RegularZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + (randInt(0, 4) * LAWN_GRID_HEIGHT), shared_from_this());
            std::cout << "generate regular zombie" << std::endl;
        }
        else if (Temp <= (P2 + P1)) {
            zombie = std::make_shared<PoleVaultingZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + (randInt(0, 4) * LAWN_GRID_HEIGHT), shared_from_this());
            std::cout << "generate Jumper" << std::endl;
        }
        else {
            zombie = std::make_shared<BucketHeadZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + (randInt(0, 4) * LAWN_GRID_HEIGHT), shared_from_this());
            std::cout << "generate Bucket" << std::endl;
        }
        gameObjects.push_back(zombie);
    }
}
bool GameWorld::CheckForJumper(std::shared_ptr<GameObject>Jumper) const {
    int x_j = Jumper->GetX() - 40;
    int y_j = Jumper->GetY();
    int Width_J = Jumper->GetWidth();
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        if ((*it)->Type_query() == Object_type::Plant) {
            int x_p = (*it)->GetX();
            int y_p = (*it)->GetY();
            int Width_p = (*it)->GetWidth();
            if (y_p == y_j && x_j - x_p <= (Width_J + Width_p)/2&&x_j-x_p>=0) {
                return true;
            }
        }
    }
    return false;
}
int GameWorld::CheckZombie(std::shared_ptr<GameObject>plant) const {
    int x_p = plant->GetX();
    int y_p = plant->GetY();
    int Width_p = plant->GetWidth();
    int count = 0;
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        int x_z = (*it)->GetX();
        int y_z = (*it)->GetY();
        int Width_z = (*it)->GetWidth();
        if ((*it)->Type_query() == Object_type::Zombie) {
            std::shared_ptr<Zombie> zombie = std::dynamic_pointer_cast<Zombie>(*it);
            if (y_z == y_p && x_z - x_p <= ((Width_p + Width_z)/2)&&x_z-x_p>=0) {
                count++;
                if (zombie) {
                    if (zombie->Eating_query() == false) {
                        zombie->Set_eat(true);
                    }
                }
            }
        }
        if ((*it)->Type_query() == Object_type::Jump) {
            std::shared_ptr<PoleVaultingZombie> zombie = std::dynamic_pointer_cast<PoleVaultingZombie>(*it);
            if (y_z == y_p &&  (x_z-x_p) <= (Width_p + Width_z)/2&&zombie->type_query()==JumperType::Walk&&x_z-x_p>=0) {
                count++;
                if (zombie) {
                    if (zombie->Eating_query() == false) {
                        zombie->Set_eat(true);
                        //std::cout << "22222222222222222" << std::endl;
                    }
                }
            }
        }
    }
    return count;
}
void GameWorld::CheckAttack(std::shared_ptr<GameObject>zombie){
    std::shared_ptr<Zombie> zom= std::dynamic_pointer_cast<Zombie>(zombie);
    int x_z = zombie->GetX();
    int y_z = zombie->GetY();
    int Width_z = zombie->GetWidth();
    int Height_z = zombie->GetHeight();
    int count = 0;
    bool temp=true;
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        int x = (*it)->GetX();
        int y = (*it)->GetY();
        int width = (*it)->GetWidth();
        int height = (*it)->GetHeight();
        if ((*it)->Type_query() == Object_type::Plant) {
            if (y == y_z && x_z - x<= (Width_z + width)/2&&x_z>=x) {
                temp = false;
            }
        }
        if ((*it)->Type_query() == Object_type::Attack) {
            std::shared_ptr<Attack>attack = std::dynamic_pointer_cast<Attack>(*it);
            if (std::abs(y_z - y) < ((Height_z + height) / 2) && std::abs(x_z - x) < ((Width_z + width) / 2)) {
                zom->Delta_Hp(-(attack)->Get_harm());
                DeleteObject(*it);
            }
        }
    }
    if (temp == true && zom->Eating_query() == true) {
        zom->Set_eat(false);
    }
}
bool GameWorld::ShootAllow(std::shared_ptr<GameObject>Shooter) const {
    int y = Shooter->GetY();
    int x = Shooter->GetX();
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        if ((*it)->Type_query() == Object_type::Zombie || (*it)->Type_query() == Object_type::Jump) {
            if (y == (*it)->GetY()&&x<(*it)->GetX()) {
                return true;
            }
        }
    }
    return false;
}
void GameWorld::JumperAttack(std::shared_ptr<GameObject>Jumper) {
    std::shared_ptr<PoleVaultingZombie> JumpZom = std::dynamic_pointer_cast<PoleVaultingZombie>(Jumper);
    int x_j = Jumper->GetX();
    int y_j = Jumper->GetY();
    int Width_j = Jumper->GetWidth();
    int Height_j = Jumper->GetHeight();
    bool temp=true;
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) {
        int x = (*it)->GetX();
        int y = (*it)->GetY();
        int width = (*it)->GetWidth();
        int height = (*it)->GetHeight();
        if (JumpZom->type_query() == JumperType::Walk) {
            if ((*it)->Type_query() == Object_type::Plant) {
                if (y == y_j && x_j - x <= ((Width_j + width))/2&&x_j-x>=0) {
                    temp = false;
                }
            }
        }
        if ((*it)->Type_query() == Object_type::Attack) {
            std::shared_ptr<Attack>attack = std::dynamic_pointer_cast<Attack>(*it);
            if (std::abs(y_j - y) < ((Height_j + height) / 2) && std::abs(x_j - x) < ((Width_j + width) / 2)) {
                JumpZom->Delta_Hp(-(attack)->Get_harm());
                DeleteObject(*it);
            }
        }
    }
    if (temp == true && JumpZom->Eating_query() == true) {
        //std::cout << "1111111111111" << std::endl;
        JumpZom->Set_eat(false);
    }
}