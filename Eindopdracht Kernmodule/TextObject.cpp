#include "TextObject.h"
#include "Scene.h"

TextObject::TextObject(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
	text = sf::Text();
	if (!font.loadFromFile("fonts/ARIAL.TTF")) { std::cout << "failed to load font" << std::endl; }
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	std::cout << "called" << std::endl;
}

void TextObject::Update(float deltaTime)
{
	UpdateTextPosition();
	Scene::DrawOnWindow(text);
}

void TextObject::SetText(const std::string& message)
{
	text.setString(message);
}

void TextObject::UpdateTextPosition()
{
	text.setPosition(position.x, position.y);
}
