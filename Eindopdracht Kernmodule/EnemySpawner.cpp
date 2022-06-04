#include "EnemySpawner.h"
#include "Scene.h"
#include "NPC.h"

EnemySpawner::EnemySpawner(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
	CustomVector2 windowSize = Scene::GetWindowSize();
	this->spawnAreaXMax = windowSize.x - 100;
	this->waitTime = GetNewWaitTime();
}

void EnemySpawner::Update(float deltaTime)
{
	timer += deltaTime;

	if (timer >= waitTime)
	{
		SpawnEnemy(CustomVector2(GetRandomSpawnPosition(), spawnPositionY));
		timer = 0;
		waitTime = GetNewWaitTime();
	}
}

void EnemySpawner::SpawnEnemy(const CustomVector2& position)
{
	std::string enemyName = "Enemy " + std::to_string(position.x);
	NPC* npcPtr = Scene::SpawnObject<NPC>(enemyName, position);
	npcPtr->LoadSprite("sprites/player.png");
}

float EnemySpawner::GetNewWaitTime()
{
	const int waitTimeInMilliseconds = rand() % waitTimeMax + waitTimeMin;
	const float toReturn = static_cast<float>(waitTimeInMilliseconds) / 1000;
	return toReturn;
}

int EnemySpawner::GetRandomSpawnPosition()
{
	return rand() % spawnAreaXMax + spawnAreaXMin;
}
