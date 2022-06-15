#pragma 
#include "RectangleCollider.h"
#include "MoveableObject.h"

class Player : public MoveableObject
{

public:
	Player(const std::string& objectName, const CustomVector2& position);

	virtual void OnColliderOverlap(const Object& other) override;
	
protected:
	virtual void OnSpriteScaleUpdated() override;

private:

	RectangleCollider collider;

	void MovementInput(float deltaTime);
	void ColliderPositionUpdate();
	void virtual Update(float deltaTime) override;

};

