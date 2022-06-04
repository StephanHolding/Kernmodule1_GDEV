#include "Object.h"

Object::Object(std::string objectName, const CustomVector2& position)
{
	this->objectName = objectName;
	this->rotation = 0;
	this->position = position;
	this->transformationChanged = true;
}

Object::~Object()
{

}

void Object::SetPosition(int newPositionX, int newPositionY)
{
	position = CustomVector2(newPositionX, newPositionY);
	transformationChanged = true;
}

void Object::SetPosition(const CustomVector2& newPosition)
{
	position = newPosition;
	transformationChanged = true;
}

void Object::SetRotation(float newRotation)
{
	rotation = newRotation;
	transformationChanged = true;
}

void Object::ObjectWasRenderedThisFrame()
{
	transformationChanged = false;
}

void Object::SetOriginToMiddle()
{
	if (sprite.getTexture() == NULL) return;
	sprite.setOrigin(CustomVector2(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2));
}

void Object::SpriteWasLoaded()
{
}

void Object::OnColliderOverlap(const Object& other)
{
}


void Object::Translate(const CustomVector2& translation)
{
	SetPosition(CustomVector2(position.x + translation.x, position.y + translation.y));
}

void Object::Start()
{

}

void Object::Update(float deltaTime)
{

}

void Object::LoadSprite(std::string path)
{
	sf::Texture t;
	if (t.loadFromFile(path))
	{
		texture = t;

		sf::Sprite s;
		s.setTexture(texture);
		
		sprite = s;

		//SetOriginToMiddle();
		SpriteWasLoaded();
	}
}
