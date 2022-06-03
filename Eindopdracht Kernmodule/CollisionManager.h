#pragma once
#include <vector>
#include "RectangleCollider.h"

static class CollisionManager
{

public:
	static void CheckCollision();
	static void ColliderWasCreated(RectangleCollider* collider);

private:
	static std::vector<RectangleCollider*> allColliders;

	static void Debug(const Rect& one, const Rect& two);

};

