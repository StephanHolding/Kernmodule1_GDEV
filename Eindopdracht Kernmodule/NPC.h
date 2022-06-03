#pragma once
#include "Object.h"
#include "RectangleCollider.h"
#include <iostream>

class NPC : public Object
{
public:
	NPC(std::string objectName, const CustomVector2& position);

	virtual void Update(float deltaTime) override;
	virtual void OnColliderOverlap(const Object& other);

protected:
	virtual void SpriteWasLoaded() override;
	
private:
	float movementSpeed = 500;

	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 0, 0));

	void MovementInput(float deltaTime);
	void Move(float translationY, float deltaTime);
};

