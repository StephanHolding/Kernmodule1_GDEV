#include "EndScreen.h"
#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "TextObject.h"
#include "ScoreManager.h"

void EndScreen::PlayerWon()
{
	CustomVector2 windowSize = Scene::GetWindowSize();
	BlackBackground(windowSize);
	Scene::DestroyAllObjects();
	TextObject* winText = Scene::SpawnObject<TextObject>("Win Text", CustomVector2(windowSize.x / 2, windowSize.y / 2));
	winText->SetText("Congrats \n\n Score: " + std::to_string(ScoreManager::GetScore()) + "\n\n Press R to Restart");
}

void EndScreen::PlayerLost()
{
	CustomVector2 windowSize = Scene::GetWindowSize();
	BlackBackground(windowSize);
	Scene::DestroyAllObjects();
	TextObject* loseText = Scene::SpawnObject<TextObject>("Lose Text", CustomVector2(windowSize.x / 2, windowSize.y / 2));
	loseText->SetTextSize(75);
	loseText->SetText("L + Ratio + ur bad + fell off +\n get better + seethe + cope \n\n Score: " + std::to_string(ScoreManager::GetScore()) + "\n\n Press R to Restart");
}

void EndScreen::BlackBackground(CustomVector2& windowSize)
{
	sf::RectangleShape panel = sf::RectangleShape(windowSize);
	panel.setFillColor(sf::Color::Black);
	panel.setPosition(CustomVector2());
	Scene::DrawOnWindow(panel);
}
