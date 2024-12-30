#include "pvz/GameObject/Zombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
Zombie::Zombie(ImageID image,int x,int y,int Hp,bool image_change,AnimID animation,std::shared_ptr<GameWorld>gw,Object_type type,int img_change_Hp,ImageID img):GameObject(image,x,y,LAYER_ZOMBIES,20,80,animation,type),Hp(Hp), gameworld(gw), image_change(image_change), img_change_Hp(img_change_Hp), image_new(img) {}
void Zombie::Update(){
    if(Hp<=0){
        gameworld->DeleteObject(shared_from_this());
    }
    if(Is_eating==false){
        int x_old=GetX();
        int y_old=GetY();
        MoveTo(x_old-1,y_old);
        //std::cout << x_old << " " << y_old << std::endl;
    }
    //std::cout << img_change_Hp << std::endl;
    if(image_change==true&&HasChanged==false){
        //std::cout << "1111111111111111111111" << std::endl;
        if(Hp<=img_change_Hp){
            ChangeImage(image_new);
            //std::cout << "1111111111111111111111" << std::endl;
            HasChanged = true;
        }
    }
    //Set_eat(false);
    //Hp -= 3;
    //std::cout << Hp << std::endl;
}
void Zombie::Set_eat(bool eat){
    if(eat){
        Is_eating=true;
        PlayAnimation(ANIMID_EAT_ANIM);
    }
    else{
        Is_eating=false;
        PlayAnimation(ANIMID_WALK_ANIM);
    }
}
void Zombie::OnClick(){
    gameworld->SetClick(Player_click::None);
}
void Zombie::Delta_Hp(int attack) {
    Hp += attack;
}
bool Zombie::Eating_query()const {
    return Is_eating;
}
int Zombie::Hp_query() const{
    return Hp;
}