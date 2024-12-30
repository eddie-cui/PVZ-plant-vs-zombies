#include "pvz/GameObject/Sun.hpp"
Sun::Sun(int x, int y, Sun_Type t,std::shared_ptr<GameWorld>gw) :GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM,Object_type::Other), type(t), tick(0), ground(y),gameworld(gw){ speed = 0; }
void Sun::Update() {
	tick++;
	int x_old = GetX();
	int y_old = GetY();
	if (type == Sun_Type::Generate) {
		speed = 5 - tick;
		MoveTo(ground>=(y_old+speed)?x_old:x_old-1, std::max(y_old + speed,ground));
	}
	if (type == Sun_Type::Drop) {
		speed = -2;
		MoveTo(x_old, std::max(y_old + speed,1));
	}
	if(tick==312)
		dead();
}
void Sun::dead() {
	gameworld->DeleteObject(shared_from_this());
}
void Sun::OnClick() {
	gameworld->Delta_Sun(25);
	gameworld->SetClick(Player_click::None);
	gameworld->DeleteObject(shared_from_this());
}