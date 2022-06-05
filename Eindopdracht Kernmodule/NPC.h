#pragma once
#include "Object.h"
#include "RectangleCollider.h"
#include <iostream>

class NPC : public Object
{
public:
	NPC(std::string objectName, const CustomVector2& position);
	virtual ~NPC() override;

	virtual void Update(float deltaTime) override;
	virtual void OnColliderOverlap(const Object& other);

protected:
	virtual void OnSpriteScaleUpdated() override;
	
private:
	float movementSpeed = 1200;

	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 0, 0));

	void Move(float translationY, float deltaTime);
};

