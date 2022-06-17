#include "NPC.h"
#include "Scene.h"
#include "ScoreManager.h"

NPC::NPC(const std::string& objectName, const CustomVector2& position) : MoveableObject(objectName, position),
collider(this, Rect(position.x, position.y, 0, 0))
{
	horizontalMovement = 0;
}

NPC::~NPC()
{

}

void NPC::Update(float deltaTime)
{
	MoveableObject::Update(deltaTime);

	if (!WillStayInScreen(CustomVector2(horizontalMovement * deltaTime, 0)))
	{
		ReverseHorizontalTranslation();
	}

	AddForce(CustomVector2(horizontalMovement, 1000));
	velocity.Clamp(CustomVector2(horizontalMovement, 0), CustomVector2(horizontalMovement, 1000));

	collider.UpdatePosition(position.x, position.y);
	Translate(velocity * deltaTime);
}

void NPC::OnColliderOverlap(const Object& other)
{
	if (other.objectName == "DeathZone")
	{
		ScoreManager::IncreaseScore(1);
		Scene::DestroyObject(this);
	}
}

void NPC::SetHorizontalMovement()
{
	horizontalMovement = rand() % 150 + 50;
	int negative = rand() % 2;

	if (negative == 0)
	{
		horizontalMovement = -horizontalMovement;
	}
}

void NPC::OnSpriteScaleUpdated()
{
	collider.SetColliderSize(texture.getSize().x * scale, texture.getSize().y * scale);
}

void NPC::ReverseHorizontalTranslation()
{
	horizontalMovement = -horizontalMovement;
}


