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
	bool transformationChanged;

	Object(std::string objectName, const CustomVector2& position);
	virtual ~Object();

	virtual void Start();
	virtual void Update(float deltaTime);

	void LoadSprite(std::string path);
	void SetPosition(int newPositionX, int newPositionY);
	void SetPosition(const CustomVector2& newPosition);
	void Translate(const CustomVector2& translation);
	void SetRotation(float newRotation);
	void ObjectWasRenderedThisFrame();
	virtual void OnColliderOverlap(const Object& other);

protected:
	virtual void SpriteWasLoaded();

private:
	void SetOriginToMiddle();
};

