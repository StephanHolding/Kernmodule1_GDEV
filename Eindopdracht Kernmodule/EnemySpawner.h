#pragma once
#include "Object.h"
#include "CustomVector2.h"

class EnemySpawner : public Object
{

public:
	EnemySpawner(std::string objectName, const CustomVector2& position);

	virtual void Update(float deltaTime) override;

private:

	void SpawnEnemy(const CustomVector2& position);
	float GetNewWaitTime();
	int GetRandomSpawnPosition();

	const int waitTimeMin = 300; //in milliseconds
	const int waitTimeMax = 600; //in milliseconds
	int spawnAreaXMin = 0;
	int spawnAreaXMax = 0;
	const int spawnPositionY = -200;
	float timer = 0;
	float waitTime = 0;

};

