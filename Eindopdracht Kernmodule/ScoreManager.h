#pragma once
#include "TextObject.h"

static class ScoreManager
{

public:
	static void IncreaseScore(int increaseBy);
	static void DecreaseScore(int decreaseBy);
	static void SetScore(int newScore);
	static int GetScore();

private:
	static int currentScore;
	static int scoreNeededForWin;
	static TextObject* textObject;
	
	static void ShowOnScreen();
	static void CheckforWin();

};

