#pragma once
#include "SFML/Graphics.hpp"

class CustomVector2
{

public:

	CustomVector2();
	CustomVector2(float xy);
	CustomVector2(float x, float y);
	CustomVector2(const CustomVector2& original);
	//~CustomVector2();

	CustomVector2& operator=(const CustomVector2& original);
	CustomVector2 operator+(const CustomVector2& other);
	CustomVector2& operator+=(const CustomVector2& other);
	CustomVector2 operator-(const CustomVector2& other);
	CustomVector2& operator-=(const CustomVector2& other);
	CustomVector2 operator*(const float scale);
	operator sf::Vector2f();

	CustomVector2& Clamp(const CustomVector2& min, const CustomVector2& max);

	float x;
	float y;

};

