#pragma once
#include "MoveableObject.h"
#include "RectangleCollider.h"
#include <iostream>

class NPC : public MoveableObject
{
public:
	NPC(const std::string& objectName, const CustomVector2& position);
	virtual ~NPC() override;

	virtual void Update(float deltaTime) override;
	virtual void OnColliderOverlap(const Object& other);

protected:
	virtual void OnSpriteScaleUpdated() override;
	
private:
	RectangleCollider collider;
};

