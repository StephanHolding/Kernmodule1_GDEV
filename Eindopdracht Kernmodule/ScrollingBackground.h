#pragma once
#include "Object.h"

class ScrollingBackground : public Object
{
public:
	ScrollingBackground(std::string objectName, const CustomVector2& position);

private:
	float movementSpeed = 1200;
	std::vector<Object*> bgs;

	virtual void Update(float deltaTime) override;
	void Move(Object* obj, float translationY, float deltaTime);
	bool WentFullyOutOfScreen(Object* obj);
	void ReturnToTop(Object* setToTop, Object* other);
	Object* FindHighestBackground();
	void LoadSprites();

};

