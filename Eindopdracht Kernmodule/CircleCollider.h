#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{

public:
	CircleCollider(float radius);

	virtual bool HasCollision(const Collider& other) override;

private:
	float radius;


};

