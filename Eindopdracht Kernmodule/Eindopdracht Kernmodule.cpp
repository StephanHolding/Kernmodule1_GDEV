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
#include "CollisionManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Eindopdracht Kernmodule DEV");

	Scene scene(&window);

	Player* player = Scene::SpawnObject<Player>("Player", CustomVector2(500, 700));
	player->LoadSprite("sprites/player.png");

	NPC* npc = Scene::SpawnObject<NPC>("NPC", CustomVector2(500, 200));
	npc->LoadSprite("sprites/player.png");

	Deathzone* deathZone = Scene::SpawnObject<Deathzone>("DeathZone", CustomVector2(0, 810));

	ScoreManager::SetScore(0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		CollisionManager::CheckCollision();
		scene.CallUpdates();

		scene.RenderAllObjects();
		window.display();
	}

	return 0;
}