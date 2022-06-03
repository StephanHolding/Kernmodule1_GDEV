#include "Deathzone.h"

Deathzone::Deathzone(std::string objectName, const CustomVector2& position) : Object(objectName, position)
{
	collider.UpdatePosition(position.x, position.y);
}
