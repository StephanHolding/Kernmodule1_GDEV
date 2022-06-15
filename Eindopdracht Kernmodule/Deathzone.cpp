#include "Deathzone.h"

Deathzone::Deathzone(const std::string& objectName, const CustomVector2& position) : Object(objectName, position),
collider(this, Rect(position.x, position.y, 100, 100))
{
	collider.UpdatePosition(position.x, position.y);
}

void Deathzone::SetColliderSize(const CustomVector2& newSize)
{
	collider.SetColliderSize(newSize.x, newSize.y);
}
