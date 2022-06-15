#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Object.h"
#include "CustomVector2.h"
#include <chrono>

class Scene
{
public:
	Scene(sf::RenderWindow* windowPtr);
	~Scene();


	static std::vector<Object*> allObjects;
	static CustomVector2 GetWindowSize();
	static void DrawOnWindow(const sf::Drawable& drawable);

	template <typename T>
	static T* FindObjectByName(const std::string& objectName)
	{
		for (int i = 0; i < allObjects.size(); i++)
		{
			if (allObjects.at(i)->objectName == objectName)
			{
				Object* toReturn = allObjects.at(i);
				return static_cast<T*>(toReturn);
			}
		}

		return nullptr;
	}

	template <typename T>
	static T* SpawnObject(const std::string& objectName, const CustomVector2& position)
	{
		T* toReturn = new T(objectName, position);
		allObjects.push_back(toReturn);

		return toReturn;
	}

	template <typename T>
	static T* SpawnObject(const std::string& objectName, const CustomVector2& position, int renderingOrder)
	{
		T* toReturn = new T(objectName, position);
		allObjects.insert(allObjects.begin() + renderingOrder, toReturn);

		return toReturn;
	}

	static void DestroyObject(Object* toDestroy);
	static void DestroyAllObjects();

	void RenderAllObjects();
	void CallUpdates();

private:
	std::chrono::high_resolution_clock::time_point lastTick;
	static sf::RenderWindow* windowPtr;
};

