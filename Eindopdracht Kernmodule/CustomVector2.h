#pragma once
#include "SFML/Graphics.hpp"

class CustomVector2
{

public:

	CustomVector2();
	CustomVector2(float x, float y);
	CustomVector2(const CustomVector2& original);
	//~CustomVector2();

	CustomVector2& operator=(const CustomVector2& original);
	CustomVector2& operator+(const CustomVector2& other);
	CustomVector2& operator-(const CustomVector2& other);
	CustomVector2& operator*(const float scale);
	operator sf::Vector2f();

	float x;
	float y;

};

