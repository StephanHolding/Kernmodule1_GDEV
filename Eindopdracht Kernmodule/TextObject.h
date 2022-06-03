#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"
#include "CustomVector2.h"
#include <iostream>

class TextObject : public Object
{

public:
	TextObject(std::string objectName, const CustomVector2& position);

	virtual void Update(float deltaTime) override;
	void SetText(const std::string& message);

private:
	sf::Text text;
	sf::Font font;

	void UpdateTextPosition();

};

