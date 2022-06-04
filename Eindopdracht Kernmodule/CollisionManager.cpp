#include "CollisionManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Scene.h"

void CollisionManager::CheckCollision()
{
	for (int i = 0; i < allColliders.size(); i++)
	{
		for (int j = 0; j < allColliders.size(); j++)
		{
			//Debug(allColliders.at(i)->rect, allColliders.at(j)->rect);

			if (i != j)
			{
				if (allColliders.at(i)->HasCollision(*allColliders.at(j)))
				{
					allColliders.at(i)->SendCollisionMessage(*allColliders.at(j));
					allColliders.at(j)->SendCollisionMessage(*allColliders.at(i));
				}
			}
		}
	}
}

void CollisionManager::ColliderWasCreated(RectangleCollider* collider)
{
	allColliders.push_back(collider);
}

void CollisionManager::ColliderWasDestroyed(RectangleCollider* destroyed)
{
	for (int i = 0; i < allColliders.size(); i++)
	{
		if (allColliders.at(i) == destroyed)
		{
			std::cout << "erased" << std::endl;
			allColliders.erase(allColliders.begin() + i);
		}
	}
}

void CollisionManager::Debug(const Rect& one, const Rect& two)
{
	sf::RectangleShape debugOne = sf::RectangleShape(sf::Vector2f(one.width, one.height));
	debugOne.setPosition(sf::Vector2f(one.positionX, one.positionY));

	sf::RectangleShape debugTwo = sf::RectangleShape(sf::Vector2f(two.width, two.height));
	debugTwo.setPosition(sf::Vector2f(two.positionX, two.positionY));

	Scene::DrawOnWindow(debugOne);
	Scene::DrawOnWindow(debugTwo);
}

std::vector<RectangleCollider*> CollisionManager::allColliders;
