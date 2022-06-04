#pragma once
#include "Object.h"
#include "RectangleCollider.h"

class Deathzone : public Object
{

public:
	Deathzone(std::string objectName, const CustomVector2& position);

	RectangleCollider collider = RectangleCollider(this, Rect(position.x, position.y, 100, 100));

	void SetColliderSize(const CustomVector2& newSize);
};

