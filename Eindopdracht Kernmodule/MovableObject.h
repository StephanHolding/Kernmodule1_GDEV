#pragma once
#include "Object.h"
class MovableObject : public Object
{

public:

	MovableObject(std::string objectName, const CustomVector2& position);

	void Translate(const CustomVector2& translation);
	void AddForce(const CustomVector2& force);

protected:
	float movementSpeed = 0;

	bool WillMoveOutOfScreen(const CustomVector2& translation, float deltaTime);

};

