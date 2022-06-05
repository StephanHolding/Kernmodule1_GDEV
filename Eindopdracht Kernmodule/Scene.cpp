#include "Scene.h"
#include "Player.h"
#include <iostream>

Scene::Scene(sf::RenderWindow* windowPtr)
{
	this->lastTick = std::chrono::high_resolution_clock::now();
	this->windowPtr = windowPtr;
}

Scene::~Scene()
{
	for (int i = 0; i < allObjects.size(); i++)
	{
		delete allObjects.at(i);
		//allObjects.at(i) = nullptr;
	}

	allObjects.clear();
	windowPtr = nullptr;
}

void Scene::DrawOnWindow(const sf::Drawable& drawable)
{
	windowPtr->draw(drawable);
}

void Scene::DestroyObject(Object* toDestroy)
{
	for (int i = 0; i < allObjects.size(); i++)
	{
		if (allObjects.at(i) == toDestroy)
		{
			delete allObjects.at(i);
			allObjects.erase(allObjects.begin() + i);
		}
	}
}

void Scene::DestroyAllObjects()
{
	for (int i = 0; i < allObjects.size(); i++)
	{
		delete allObjects.at(i);
	}

	allObjects.clear();
}

void Scene::RenderAllObjects()
{
	for (int i = 0; i < allObjects.size(); i++)
	{
		Object* object = allObjects.at(i);
		if (object->draw)
			windowPtr->draw(object->GetDrawable());
		object = nullptr;
	}
}

CustomVector2 Scene::GetWindowSize()
{
	return CustomVector2(windowPtr->getSize().x, windowPtr->getSize().y);
}

void Scene::CallUpdates()
{
	//CALCULATE DELTATIME
	std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> deltaTime = currentTime - lastTick;

	for (int i = 0; i < allObjects.size(); i++)
	{
		allObjects.at(i)->Update(deltaTime.count());
	}

	this->lastTick = currentTime;
}


std::vector<Object*> Scene::allObjects;
sf::RenderWindow* Scene::windowPtr;
