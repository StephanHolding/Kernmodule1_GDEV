#include "ScrollingBackground.h"
#include "StartLights.h"
#include "Scene.h"

ScrollingBackground::ScrollingBackground(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
	bgs.push_back(Scene::SpawnObject<Object>("background one", CustomVector2(0, -Scene::GetWindowSize().y), 0));
	bgs.push_back(Scene::SpawnObject<Object>("background two", CustomVector2(0, 0), 0));

	LoadSprites();
}

void ScrollingBackground::Update(float deltaTime)
{
	if (!StartLights::startLightsFinished) return;

	for (int i = 0; i < bgs.size(); i++)
	{
		if (WentFullyOutOfScreen(bgs.at(i)))
		{
			ReturnToTop(bgs.at(i), FindHighestBackground());
		}
		else
		{
			Move(bgs.at(i), 1, deltaTime);
		}
	}
}

void ScrollingBackground::Move(Object* obj, float translationY, float deltaTime)
{
	obj->Translate(CustomVector2(0, translationY) * movementSpeed * deltaTime);
}

bool ScrollingBackground::WentFullyOutOfScreen(Object* obj)
{
	return obj->position.y >= Scene::GetWindowSize().y;
}

void ScrollingBackground::ReturnToTop(Object* setToTop, Object* other)
{
	int yPos = other->position.y - setToTop->texture.getSize().y;
	setToTop->position = CustomVector2(0, yPos);
}

Object* ScrollingBackground::FindHighestBackground()
{
	int highestPosition = 99999;
	Object* toReturn = nullptr;

	for (int i = 0; i < bgs.size(); i++)
	{
		if (bgs.at(i)->position.y < highestPosition)
		{
			highestPosition = bgs.at(i)->position.y;
			toReturn = bgs.at(i);
		}
	}

	return toReturn;
}

void ScrollingBackground::LoadSprites()
{
	for (int i = 0; i < bgs.size(); i++)
	{
		bgs.at(i)->LoadSprite("sprites/Racetrack Sprite.png");
	}
}
