#pragma once
#include "Rect.h"
#include "Object.h"

class RectangleCollider
{

public:
	RectangleCollider(Object* owner, const Rect& rect);

	Object* owner = nullptr;

	bool HasCollision(const RectangleCollider& other);
	void UpdatePosition(float x, float y);
	void SetColliderSize(float width, float height);
	void SendCollisionMessage(const RectangleCollider& other);

	Rect rect;
private:


	bool AABBDetection(const RectangleCollider& other);

};

