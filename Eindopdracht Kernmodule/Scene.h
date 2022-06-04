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
	static T* SpawnObject(std::string objectName, CustomVector2 position)
	{
		T* toReturn = new T(objectName, position);
		allObjects.push_back(toReturn);

		return toReturn;
	}

	static void DestroyObject(Object* toDestroy);


	void RenderAllObjects();
	void CallUpdates();

private:
	std::chrono::high_resolution_clock::time_point lastTick;
	static sf::RenderWindow* windowPtr;
};

