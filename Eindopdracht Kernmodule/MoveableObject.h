#pragma once
#include "Object.h"
class MoveableObject : public Object
{
public:

	MoveableObject(std::string objectName, const CustomVector2& position);

	virtual void Update(float deltaTime) override;
	void Translate(const CustomVector2& translation);
	void AddForce(const CustomVector2& force);

protected:
	CustomVector2 velocity;
	CustomVector2 friction;

	bool WillStayInScreen(const CustomVector2& translation);
	void ApplyFriction(float deltaTime);
};

