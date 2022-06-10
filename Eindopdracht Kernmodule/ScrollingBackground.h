#pragma once
#include "Object.h"
#include "MoveableObject.h"

class ScrollingBackground : public Object
{
public:
	ScrollingBackground(std::string objectName, const CustomVector2& position);

private:
	float movementSpeed = 1000;
	std::vector<MoveableObject*> bgs;

	virtual void Update(float deltaTime) override;
	void Move(MoveableObject* obj, float translationY, float deltaTime);
	bool WentFullyOutOfScreen(MoveableObject* obj);
	void ReturnToTop(MoveableObject* setToTop, MoveableObject* other);
	MoveableObject* FindHighestBackground();
	void LoadSprites();

};

