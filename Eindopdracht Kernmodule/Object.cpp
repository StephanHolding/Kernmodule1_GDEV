#include "Object.h"

Object::Object(std::string objectName, const CustomVector2& position)
{
	this->objectName = objectName;
	SetRotation(0);
	SetPosition(position);
	SetScale(1);
	this->draw = true;
}

Object::~Object()
{

}

void Object::SetPosition(int newPositionX, int newPositionY)
{
	position = CustomVector2(newPositionX, newPositionY);
	sprite.setPosition(position);
}

void Object::SetPosition(const CustomVector2& newPosition)
{
	position = newPosition;
	sprite.setPosition(position);
}

void Object::SetScale(const float newScale)
{
	scale = newScale;
	sprite.setScale(CustomVector2(scale));
	OnSpriteScaleUpdated();
}

void Object::SetOriginToMiddle()
{
	if (sprite.getTexture() == NULL) return;
	sprite.setOrigin(CustomVector2(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2));
}

void Object::SetOriginToUpperLeft()
{
	if (sprite.getTexture() == NULL) return;
	sprite.setOrigin(CustomVector2());
}

sf::Drawable& Object::GetDrawable()
{
	return sprite;
}

void Object::OnSpriteScaleUpdated()
{
}

void Object::OnColliderOverlap(const Object& other)
{
}

void Object::SetRotation(float newRotation)
{
	rotation = newRotation;
	sprite.setRotation(rotation);
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

		sprite.setPosition(position);
		sprite.setRotation(rotation);
		sprite.setScale(CustomVector2(scale));

		OnSpriteScaleUpdated();
	}
}
