#include "EnemySpawner.h"
#include "Scene.h"
#include "NPC.h"
#include "StartLights.h"

EnemySpawner::EnemySpawner(const std::string& objectName, const CustomVector2& position) : Object(objectName, position)
{
	CustomVector2 windowSize = Scene::GetWindowSize();
	this->spawnAreaXMax = windowSize.x - 100;
	this->waitTime = GetNewWaitTime();
}

void EnemySpawner::Update(float deltaTime)
{
	if (!StartLights::startLightsFinished) return;

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
	srand((unsigned int)time(NULL));
	int spriteRandomize = rand() % 19 + 1;
	npcPtr->LoadSprite("sprites/pitstop_car_" + std::to_string(spriteRandomize) + ".png");
	//npcPtr->LoadSprite("sprites/pitstop_car_5.png");
	npcPtr->SetScale(0.25);
	npcPtr->SetOriginToMiddle();
	npcPtr->SetHorizontalMovement();
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
