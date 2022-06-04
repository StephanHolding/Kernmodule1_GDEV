#include "NPC.h"
#include "Scene.h"
#include "ScoreManager.h"

NPC::NPC(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{

}

NPC::~NPC()
{

}

void NPC::Update(float deltaTime)
{
	collider.UpdatePosition(position.x, position.y);
	Move(1, deltaTime);
}

void NPC::OnColliderOverlap(const Object& other)
{
	if (other.objectName == "DeathZone")
	{
		ScoreManager::IncreaseScore(1);
		Scene::DestroyObject(this);
	}
}

void NPC::SpriteWasLoaded()
{
	collider.SetColliderSize(texture.getSize().x, texture.getSize().y);
}

void NPC::Move(float translationY, float deltaTime)
{
	Translate(CustomVector2(0, translationY) * movementSpeed * deltaTime);
}


