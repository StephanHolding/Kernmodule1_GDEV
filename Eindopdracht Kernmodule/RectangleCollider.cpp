#include "RectangleCollider.h"
#include "CollisionManager.h"
#include <iostream>

RectangleCollider::RectangleCollider(Object* owner, const Rect& rect)
{
	this->rect = rect;
	this->owner = owner;
	CollisionManager::ColliderWasCreated(this);
}

RectangleCollider::~RectangleCollider()
{
	CollisionManager::ColliderWasDestroyed(this);
}

bool RectangleCollider::HasCollision(const RectangleCollider& other)
{
	return AABBDetection(other);
}

void RectangleCollider::UpdatePosition(float x, float y)
{
	rect.positionX = x;
	rect.positionY = y;
}

void RectangleCollider::SetColliderSize(float width, float height)
{
	this->rect.width = width;
	this->rect.height = height;
}

void RectangleCollider::SendCollisionMessage(const RectangleCollider& other)
{
	owner->OnColliderOverlap(*other.owner);
}

bool RectangleCollider::AABBDetection(const RectangleCollider& other)
{
	if (rect.positionX + rect.width >= other.rect.positionX &&
		other.rect.positionX + other.rect.width >= rect.positionX &&
		rect.positionY + rect.height >= other.rect.positionY &&
		other.rect.positionY + other.rect.height >= rect.positionY)
	{
		return true;
	}

	return false;
}
