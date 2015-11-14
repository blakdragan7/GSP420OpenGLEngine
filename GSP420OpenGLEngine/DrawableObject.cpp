#include "DrawableObject.h"


DrawableObject::DrawableObject(void)
{
	scale = Vec2D(1,1);
	position = Vec2D(0,0);
	rotation = 0;
}


DrawableObject::~DrawableObject(void)
{
}
