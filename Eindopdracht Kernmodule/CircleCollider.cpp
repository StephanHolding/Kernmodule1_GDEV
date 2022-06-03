#include "CircleCollider.h"
#include <iostream>

CircleCollider::CircleCollider(float radius) : Collider()
{
	this->radius = radius;
	this->colliderType = colliderType::CircleCollider;
}

bool CircleCollider::HasCollision(const Collider& other)
{
	switch (other.colliderType)
	{
	case (colliderType::CircleCollider):

		break;
	case (colliderType::RectangleCollider):

		break;
	}

	return false;
}