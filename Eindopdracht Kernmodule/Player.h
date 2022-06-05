#pragma once
#include "Object.h"
#include "RectangleCollider.h"

class Player : public Object
{

public:
	Player(std::string objectName, const CustomVector2& position);

	virtual void OnColliderOverlap(const Object& other) override;
	
protected:
	virtual void OnSpriteScaleUpdated() override;

private:
	float movementSpeed = 1500;
	//RectangleCollider* collider = new RectangleCollider(Rect(position.x, position.y, texture.getSize().x, texture.getSize().y));
	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 0, 0));

	void MovementInput(float deltaTime);
	void Move(float translationX, float deltaTime);
	void ColliderPositionUpdate();
	bool CanMove(float translationX, float deltaTime);
	void virtual Update(float deltaTime) override;

};

