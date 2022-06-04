#pragma once
#include <vector>
#include "RectangleCollider.h"

static class CollisionManager
{

public:
	static void CheckCollision();
	static void ColliderWasCreated(RectangleCollider* collider);
	static void ColliderWasDestroyed(RectangleCollider* destroyed);

private:
	static std::vector<RectangleCollider*> allColliders;

	static void Debug(const Rect& one, const Rect& two);

};

