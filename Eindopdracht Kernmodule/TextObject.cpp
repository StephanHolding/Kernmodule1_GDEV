#include "TextObject.h"
#include "Scene.h"

TextObject::TextObject(const std::string& objectName, const CustomVector2& position) : Object(objectName, position)
{
	text = sf::Text();
	if (!font.loadFromFile("fonts/ARIAL.TTF")) { std::cout << "failed to load font" << std::endl; }
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	text.setOutlineThickness(2);
}

void TextObject::Update(float deltaTime)
{
	UpdateTextPosition();
	Scene::DrawOnWindow(text);
}

void TextObject::SetText(const std::string& message)
{
	text.setString(message);
	SetPivotToMiddle();
}

void TextObject::SetTextSize(int size)
{
	text.setCharacterSize(size);
}

sf::Drawable& TextObject::GetDrawable()
{
	return text;
}

void TextObject::UpdateTextPosition()
{
	text.setPosition(position.x, position.y);
}

void TextObject::SetPivotToMiddle()
{
	text.setOrigin(CustomVector2(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
}
