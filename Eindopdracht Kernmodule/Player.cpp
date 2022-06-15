#include "Player.h"
#include "CustomVector2.h"
#include "EndScreen.h"
#include "Scene.h"
#include "StartLights.h"

Player::Player(const std::string& objectName, const CustomVector2& position) : MoveableObject(objectName, position),
collider(this, Rect(position.x, position.y, 0, 0))
{

}

void Player::OnSpriteScaleUpdated()
{
	collider.SetColliderSize(texture.getSize().x * scale, texture.getSize().y * scale);
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
		if (WillStayInScreen(velocity * deltaTime))
		{
			AddForce(CustomVector2(-7000 * deltaTime, 0));
			velocity.Clamp(CustomVector2(-1000, 0), CustomVector2(1000, 0));

			if (rotation != 175)
			{
				SetRotation(175);
			}

			return;
		}
		else
		{
			velocity = CustomVector2(0, 0);
			return;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (WillStayInScreen(velocity * deltaTime))
		{
			AddForce(CustomVector2(7000 * deltaTime, 0));
			velocity.Clamp(CustomVector2(-1000, 0), CustomVector2(1000, 0));

			if (rotation != 185)
			{
				SetRotation(185);
			}
			return;
		}
		else
		{
			velocity = CustomVector2(0, 0);
			return;
		}
	}
	else
	{
		if (rotation != 180)
		{
			SetRotation(180);
		}
	}
}

void Player::ColliderPositionUpdate()
{
	collider.UpdatePosition(position.x, position.y);
}

void Player::Update(float deltaTime)
{
	if (!StartLights::startLightsFinished) return;

	MoveableObject::Update(deltaTime);

	MovementInput(deltaTime);

	if (WillStayInScreen(velocity * deltaTime))
		Translate(velocity * deltaTime);

	ColliderPositionUpdate();
}
