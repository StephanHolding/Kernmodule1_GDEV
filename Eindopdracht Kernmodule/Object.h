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

	Object(const std::string& objectName, const CustomVector2& position);
	virtual ~Object();

	virtual void Start();
	virtual void Update(float deltaTime);

	void LoadSprite(const std::string& path);
	void SetPosition(int newPositionX, int newPositionY);
	void SetPosition(const CustomVector2& newPosition);
	void SetScale(float newScale);
	void SetRotation(float newRotation);
	virtual void OnColliderOverlap(const Object& other);
	void SetOriginToMiddle();
	void SetOriginToUpperLeft();
	virtual sf::Drawable& GetDrawable();

protected:
	virtual void OnSpriteScaleUpdated();
};

