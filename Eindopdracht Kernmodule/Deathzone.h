#pragma once
#include "Object.h"
#include "RectangleCollider.h"

class Deathzone : public Object
{

public:
	Deathzone(const std::string& objectName, const CustomVector2& position);

	RectangleCollider collider;

	void SetColliderSize(const CustomVector2& newSize);
};

