#include "Rect.h"

Rect::Rect()
{
	this->positionX = 0;
	this->positionY = 0;
	this->width = 0;
	this->height = 0;
}

Rect::Rect(float posX, float posY, float width, float height)
{
	this->positionX = posX;
	this->positionY = posY;
	this->width = width;
	this->height = height;
}
