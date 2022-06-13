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
	if (FindScoreText())
	{
		textObject->SetText(std::to_string(currentScore));
	}
}

void ScoreManager::CheckforWin()
{
	if (currentScore >= scoreNeededForWin)
	{
		EndScreen::PlayerWon();
	}
}

bool ScoreManager::FindScoreText()
{
	if (textObject != nullptr) return true;

	textObject = Scene::FindObjectByName<TextObject>("ScoreText");

	return textObject != nullptr;
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

void ScoreManager::Reset()
{
	currentScore = 0;
	textObject = nullptr;
}

int ScoreManager::currentScore = 0;
int ScoreManager::scoreNeededForWin = 100;
TextObject* ScoreManager::textObject = nullptr;
