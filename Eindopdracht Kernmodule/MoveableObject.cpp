#include "MoveableObject.h"
#include "Scene.h"

MoveableObject::MoveableObject(std::string objectName, const CustomVector2& position) : Object(objectName, position),
friction(1500, 1500)
{

}

void MoveableObject::Update(float deltaTime)
{
	ApplyFriction(deltaTime);
}

void MoveableObject::Translate(const CustomVector2& translation)
{
	SetPosition(CustomVector2(position.x + translation.x, position.y + translation.y));
}

void MoveableObject::AddForce(const CustomVector2& force)
{
	velocity += force;
}

bool MoveableObject::WillStayInScreen(const CustomVector2& translation)
{
	CustomVector2 windowSize = Scene::GetWindowSize();

	float spriteRightPos = (position.x + static_cast<float>(texture.getSize().x) / 2 * scale) + translation.x;
	float spriteLeftPos = (position.x - static_cast<float>(texture.getSize().x) / 2 * scale) + translation.x;
	float spriteUpPos = (position.y - static_cast<float>(texture.getSize().y) / 2 * scale) + translation.y;
	float spriteDownPos = (position.y + static_cast<float>(texture.getSize().y) / 2 * scale) + translation.y;


	if (spriteRightPos <= windowSize.x && spriteLeftPos >= 0 && spriteDownPos <= windowSize.y && spriteUpPos >= 0)
	{
		return true;
	}

	return false;
}

void MoveableObject::ApplyFriction(float deltaTime)
{
	if (velocity.x < 0)
	{
		velocity += CustomVector2(friction.x * deltaTime, 0);
		velocity.Clamp(CustomVector2(-9999, -9999), CustomVector2(0, 9999));
	}
	else if (velocity.x > 0)
	{
		velocity -= CustomVector2(friction.x * deltaTime, 0);
		velocity.Clamp(CustomVector2(0, -9999), CustomVector2(9999, 9999));
	}

	if (velocity.y < 0)
	{
		velocity += CustomVector2(0, friction.y * deltaTime);
		velocity.Clamp(CustomVector2(-9999, -9999), CustomVector2(9999, 0));
	}
	else if (velocity.y > 0)
	{
		velocity -= CustomVector2(0, velocity.y * deltaTime);
		velocity.Clamp(CustomVector2(-9999, 0), CustomVector2(9999, 9999));
	}

	std::cout << velocity.x << std::endl;

}
