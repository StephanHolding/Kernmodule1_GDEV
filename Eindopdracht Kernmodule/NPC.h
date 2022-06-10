#pragma once
#include "MoveableObject.h"
#include "RectangleCollider.h"
#include <iostream>

class NPC : public MoveableObject
{
public:
	NPC(std::string objectName, const CustomVector2& position);
	virtual ~NPC() override;

	virtual void Update(float deltaTime) override;
	virtual void OnColliderOverlap(const Object& other);

protected:
	virtual void OnSpriteScaleUpdated() override;
	
private:
	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 0, 0));
};

