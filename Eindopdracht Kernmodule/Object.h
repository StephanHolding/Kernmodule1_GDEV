#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "CustomVector2.h"

class Object
{

public:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string objectName;
	CustomVector2 position;
	float rotation;
	float scale;
	bool draw;

	Object(std::string objectName, const CustomVector2& position);
	virtual ~Object();

	virtual void Start();
	virtual void Update(float deltaTime);

	void LoadSprite(std::string path);
	void SetPosition(int newPositionX, int newPositionY);
	void SetPosition(const CustomVector2& newPosition);
	void SetScale(const float newScale);
	void Translate(const CustomVector2& translation);
	void SetRotation(float newRotation);
	virtual void OnColliderOverlap(const Object& other);
	void SetOriginToMiddle();
	void SetOriginToUpperLeft();
	virtual sf::Drawable& GetDrawable();

protected:
	virtual void OnSpriteScaleUpdated();
};

