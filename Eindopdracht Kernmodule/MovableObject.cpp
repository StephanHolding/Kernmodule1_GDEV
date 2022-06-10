#include "MovableObject.h"
#include "Scene.h"

MovableObject::MovableObject(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
}

void MovableObject::Translate(const CustomVector2& translation)
{
	SetPosition(CustomVector2(position.x + translation.x, position.y + translation.y));
}

void MovableObject::AddForce(const CustomVector2& force)
{

}

bool MovableObject::WillMoveOutOfScreen(const CustomVector2& translation, float deltaTime)
{
	CustomVector2 windowSize = Scene::GetWindowSize();

	float spriteRightPos = (position.x + static_cast<float>(texture.getSize().x) / 2 * scale) + translation.x * movementSpeed * deltaTime;
	float spriteLeftPos = (position.x - static_cast<float>(texture.getSize().x) / 2 * scale) + translation.x * movementSpeed * deltaTime;
	float spriteUpPos = (position.y - static_cast<float>(texture.getSize().y) / 2 * scale) + translation.y * movementSpeed * deltaTime;
	float spriteDownPos = (position.y + static_cast<float>(texture.getSize().y) / 2 * scale) + translation.y * movementSpeed * deltaTime;

	if (spriteRightPos <= windowSize.x && spriteLeftPos >= 0 && spriteDownPos <= windowSize.y && spriteUpPos >= 0)
	{
		return true;
	}

	return false;
}
