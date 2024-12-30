#include "pvz/GameObject/PoleVaultingZombie.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
PoleVaultingZombie::PoleVaultingZombie(int x,int y,std::shared_ptr<GameWorld>gw):Zombie(IMGID_POLE_VAULTING_ZOMBIE,x,y,340,true,ANIMID_RUN_ANIM,gw,Object_type::Jump,0,IMGID_NONE),gameworld(gw){}
void PoleVaultingZombie::Update() {
	if (Hp_query() <= 0) {
		gameworld->DeleteObject(shared_from_this());
	}
	if (Is_running == true) {
		if (gameworld->CheckForJumper(shared_from_this()) == true) {
			PlayAnimation(ANIMID_JUMP_ANIM);
			Is_running = false;
			Is_jumpping = true;
		}
		else {
			int x_old = GetX();
			int y_old = GetY();
			MoveTo(x_old - 2, y_old);
		}
	}
	if (Is_jumpping == true) {
		tick++;
		if (tick == 42) {
			PlayAnimation(ANIMID_WALK_ANIM);
			//std::cout << "333333333" << std::endl;
			Is_jumpping = false;
			Is_Walking = true;
			int x_old = GetX();
			int y_old = GetY();
			MoveTo(x_old - 150, y_old);
			tick = 0;
		}
	}
	if (Is_Walking == true) {
		if (Eating_query() == false) {
			int x_old = GetX();
			int y_old = GetY();
			MoveTo(x_old - 1, y_old);
		}
	}
}
JumperType PoleVaultingZombie::type_query()const {
	if (Is_running == true) {
		return JumperType::Run;
	}
	if (Is_jumpping == true) {
		return JumperType::Jump;
	}
	if(Is_Walking == true) {
		return JumperType::Walk;
	}
	return JumperType::Walk;
}