#include "pvz/GameObject/GameObject.hpp"

GameObject::GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,Object_type type): ObjectBase(imageID, x, y, layer, width, height, animID),Type(type),valid(true){}
// Your everything begins from here.
bool GameObject::IsValid() const { return valid; }
void GameObject::Invalidate() { valid = false; }
Object_type GameObject::Type_query() const{
    return Type;
}