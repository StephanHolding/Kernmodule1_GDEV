#pragma once
#include <vector>

class Collider
{
public:
	Collider();

	enum class colliderType
	{
		Undefined,
		CircleCollider,
		RectangleCollider
	};
	colliderType colliderType = colliderType::Undefined;

	virtual bool HasCollision(const Collider& other);

private:



};

