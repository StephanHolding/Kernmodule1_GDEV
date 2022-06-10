#pragma 
#include "RectangleCollider.h"
#include "MoveableObject.h"

class Player : public MoveableObject
{

public:
	Player(std::string objectName, const CustomVector2& position);

	virtual void OnColliderOverlap(const Object& other) override;
	
protected:
	virtual void OnSpriteScaleUpdated() override;

private:

	//RectangleCollider* collider = new RectangleCollider(Rect(position.x, position.y, texture.getSize().x, texture.getSize().y));
	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 0, 0));

	void MovementInput(float deltaTime);
	void ColliderPositionUpdate();
	void virtual Update(float deltaTime) override;

};

