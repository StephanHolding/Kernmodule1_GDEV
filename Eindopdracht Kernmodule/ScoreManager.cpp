#include "ScoreManager.h"
#include "Scene.h"

void ScoreManager::IncreaseScore(int increaseBy)
{
	currentScore += increaseBy;
	ShowOnScreen();
}

void ScoreManager::DecreaseScore(int decreaseBy)
{
	currentScore -= decreaseBy;
	ShowOnScreen();
}

void ScoreManager::ShowOnScreen()
{
	textObject->SetText(std::to_string(currentScore));
}

void ScoreManager::SetScore(int newScore)
{
	currentScore = newScore;
	ShowOnScreen();
}

int ScoreManager::currentScore = 0;
TextObject* ScoreManager::textObject = Scene::SpawnObject<TextObject>("Text Object", CustomVector2(20, 20));
