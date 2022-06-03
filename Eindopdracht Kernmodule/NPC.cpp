#include "NPC.h"

NPC::NPC(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
}

void NPC::Update(float deltaTime)
{
	collider.UpdatePosition(position.x, position.y);
	MovementInput(deltaTime);
}

void NPC::OnColliderOverlap(const Object& other)
{
	if (other.objectName == "DeathZone")
	{
		std::cout << "oh no im dead" << std::endl;
	}
}

void NPC::SpriteWasLoaded()
{
	collider.SetColliderSize(texture.getSize().x, texture.getSize().y);
}

void NPC::MovementInput(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Move(-1, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Move(1, deltaTime);
	}
}

void NPC::Move(float translationY, float deltaTime)
{
	Translate(CustomVector2(0, translationY) * movementSpeed * deltaTime);
}


