#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Object.h"
#include "Scene.h"
#include "Player.h"
#include "NPC.h"
#include "CustomVector2.h"
#include "Deathzone.h"
#include "ScoreManager.h"
#include "EnemySpawner.h"
#include "StartLights.h"
#include "ScrollingBackground.h"
#include "CollisionManager.h"

bool restartKeyWasPressedLastFrame;

void StartGame()
{
	Player* player = Scene::SpawnObject<Player>("Player", CustomVector2(600, 650));
	player->LoadSprite("sprites/player.png");
	player->SetOriginToMiddle();
	player->SetScale(0.275);
	player->SetRotation(180);

	Deathzone* deathZone = Scene::SpawnObject<Deathzone>("DeathZone", CustomVector2(0, 1300));
	deathZone->SetColliderSize(CustomVector2(1500, 100));

	EnemySpawner* enemySpawner = Scene::SpawnObject<EnemySpawner>("Enemy Spawner", CustomVector2());

	TextObject* scoreText = Scene::SpawnObject<TextObject>("ScoreText", CustomVector2(60, 40));

	ScoreManager::SetScore(0);

	ScrollingBackground* scrollingBackground = Scene::SpawnObject<ScrollingBackground>("scrolling background", CustomVector2());

	StartLights* startLights = Scene::SpawnObject<StartLights>("startlights", CustomVector2());
	startLights->SetPosition(350, 100);
	startLights->SetScale(0.75);
	startLights->BeginStartLights();

	//All these pointers go out of scope, but thats okay, the scene keeps track of all spawned objects.
}

void RestartGame()
{
	Scene::DestroyAllObjects();
	ScoreManager::Reset();
	StartGame();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Eindopdracht Kernmodule DEV");

	Scene scene(&window);

	StartGame();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			if (!restartKeyWasPressedLastFrame)
			{
				RestartGame();
			}

			restartKeyWasPressedLastFrame = true;
		}
		else
		{
			restartKeyWasPressedLastFrame = false;
		}

		window.clear();

		CollisionManager::CheckCollision();
		scene.CallUpdates();

		scene.RenderAllObjects();
		window.display();
	}

	return 0;
}

