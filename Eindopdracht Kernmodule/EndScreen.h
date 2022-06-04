#pragma once
#include "CustomVector2.h"

static class EndScreen
{

public:
	static void PlayerWon();
	static void PlayerLost();

private:
	static void BlackBackground(CustomVector2& windowSize);

};

