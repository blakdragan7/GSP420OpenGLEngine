#include "stdafx.h"
#include "DrawableObject.h"
#include "helper.h"

static long long lastUUID = 0;

DrawableObject::DrawableObject(void)
{
	scale = Vec2D(1,1);
	position = Vec2D(0,0);
	rotation = 0;
	isLocked = false;

	blendR=blendG=blendB=1;

	uuid = lastUUID++;
}


DrawableObject::~DrawableObject(void)
{
	if(isLocked)
		unlock();
}

void DrawableObject::lockWait()
{
	while(!mutex.try_lock())Sleep(1);
	isLocked = true;
}

void DrawableObject::unlock()
{
	mutex.unlock();
	isLocked = false;
}

void DrawableObject::setBlendColor(float r,float g,float b)
{
	blendR = r;
	blendG = g;
	blendB = b;
}