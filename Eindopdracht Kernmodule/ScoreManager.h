#pragma once
#include "TextObject.h"

static class ScoreManager
{

public:
	static void IncreaseScore(int increaseBy);
	static void DecreaseScore(int decreaseBy);
	static void SetScore(int newScore);

private:
	static int currentScore;
	static TextObject* textObject;
	
	static void ShowOnScreen();

};

