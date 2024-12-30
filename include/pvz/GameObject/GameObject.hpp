#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
	using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
	
	GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,Object_type type);
	virtual void Init() = 0;
	bool IsValid() const;
	void Invalidate();
	virtual Object_type Type_query()const;
private:
	bool valid;
	Object_type Type=Object_type::Other;

};
#endif // !GAMEOBJECT_HPP__