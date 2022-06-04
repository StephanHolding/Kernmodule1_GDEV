#include "Player.h"
#include "CustomVector2.h"
#include "EndScreen.h"
#include "Scene.h"

Player::Player(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{

}

void Player::SpriteWasLoaded()
{
	collider.SetColliderSize(texture.getSize().x, texture.getSize().y);
}

void Player::OnColliderOverlap(const Object& other)
{
	std::size_t found = other.objectName.find("Enemy");

	if (found != std::string::npos)
	{
		EndScreen::PlayerLost();
	}
}

void Player::MovementInput(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (CanMove(-1, deltaTime))
			Move(-1, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (CanMove(1, deltaTime))
			Move(1, deltaTime);
	}
}

void Player::Move(float translationX, float deltaTime)
{
	Translate(CustomVector2(translationX, 0) * movementSpeed * deltaTime);
}

void Player::ColliderPositionUpdate()
{
	collider.UpdatePosition(position.x, position.y);
}

bool Player::CanMove(float translationX, float deltaTime)
{
	CustomVector2 windowSize = Scene::GetWindowSize();

	if (translationX > 0)
	{
		if (position.x + texture.getSize().x + translationX * movementSpeed * deltaTime < windowSize.x)
		{
			return true;
		}
	}
	else if (translationX < 0)
	{
		if (position.x + translationX * movementSpeed * deltaTime > 0)
		{
			return true;
		}
	}

	return false;
}

void Player::Update(float deltaTime)
{
	MovementInput(deltaTime);
	ColliderPositionUpdate();
}
