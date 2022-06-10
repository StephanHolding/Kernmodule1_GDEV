#include "NPC.h"
#include "Scene.h"
#include "ScoreManager.h"

NPC::NPC(std::string objectName, const CustomVector2& position) : MoveableObject(objectName, position)
{

}

NPC::~NPC()
{

}

void NPC::Update(float deltaTime)
{
	MoveableObject::Update(deltaTime);

	AddForce(CustomVector2(0, 1000));
	velocity.Clamp(CustomVector2(0, 0), CustomVector2(0, 1000));

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

void NPC::OnSpriteScaleUpdated()
{
	collider.SetColliderSize(texture.getSize().x * scale, texture.getSize().y * scale);
}


