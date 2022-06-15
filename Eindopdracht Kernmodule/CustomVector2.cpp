#include "CustomVector2.h"

CustomVector2::CustomVector2()
{
	this->x = 0;
	this->y = 0;
}

CustomVector2::CustomVector2(float xy)
{
	this->x = xy;
	this->y = xy;
}

CustomVector2::CustomVector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

CustomVector2::CustomVector2(const CustomVector2& original)
{
	this->x = original.x;
	this->y = original.y;
}

CustomVector2& CustomVector2::operator=(const CustomVector2& original)
{
	this->x = original.x;
	this->y = original.y;
	return *this;
}

CustomVector2 CustomVector2::operator+(const CustomVector2& other)
{
	CustomVector2 toReturn(x + other.x, y + other.y);
	return toReturn;
}

CustomVector2& CustomVector2::operator+=(const CustomVector2& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

CustomVector2 CustomVector2::operator-(const CustomVector2& other)
{
	CustomVector2 toReturn(x - other.x, y - other.y);
	return toReturn;
}

CustomVector2& CustomVector2::operator-=(const CustomVector2& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

CustomVector2 CustomVector2::operator*(const float scale)
{
	CustomVector2 toReturn(x * scale, y * scale);
	return toReturn;
}

CustomVector2::operator sf::Vector2f()
{
	return sf::Vector2f(this->x, this->y);
}

CustomVector2& CustomVector2::Clamp(const CustomVector2& min, const CustomVector2& max)
{
	if (x < min.x)
		x = min.x;

	if (x > max.x)
		x = max.x;

	if (y < min.y)
		y = min.y;
	
	if (y > max.y)
		y = max.y;

	return *this;
}
