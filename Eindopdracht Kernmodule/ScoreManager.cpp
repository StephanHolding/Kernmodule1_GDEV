#include "ScoreManager.h"
#include "Scene.h"
#include "EndScreen.h"

void ScoreManager::IncreaseScore(int increaseBy)
{
	currentScore += increaseBy;
	ShowOnScreen();
	CheckforWin();
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

void ScoreManager::CheckforWin()
{
	if (currentScore >= scoreNeededForWin)
	{
		EndScreen::PlayerWon();
	}
}

void ScoreManager::SetScore(int newScore)
{
	currentScore = newScore;
	ShowOnScreen();
}

int ScoreManager::GetScore()
{
	return currentScore;
}

int ScoreManager::currentScore = 0;
int ScoreManager::scoreNeededForWin = 100;
TextObject* ScoreManager::textObject = Scene::SpawnObject<TextObject>("Text Object", CustomVector2(60, 40));
