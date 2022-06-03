#include "Player.h"
#include "CustomVector2.h"

Player::Player(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{

}

void Player::SpriteWasLoaded()
{
	collider.SetColliderSize(texture.getSize().x, texture.getSize().y);
}

void Player::OnColliderOverlap(const Object& other)
{
	if (other.objectName == "Player")
	{
		std::cout << "collided with Player" << std::endl;
	}
}

void Player::MovementInput(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Move(-1, deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
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

void Player::Update(float deltaTime)
{
	MovementInput(deltaTime);
	ColliderPositionUpdate();
}
