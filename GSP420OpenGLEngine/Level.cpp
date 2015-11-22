#include "stdafx.h"
#include "Level.h"
#include "DrawableObject.h"
#include "Sprite.h"
#include <iostream>

Level::Level(void) : DrawableObject()
{
}


Level::~Level(void)
{
	for(auto object : allObjects) // remove all objects safely
	{
		delete object.second;
	}

	allObjects.clear(); // clear the array
}

void Level::draw()
{
	lockWait();

	glPushMatrix();

	for(auto object : allObjects) // c++ 11 syntax for a for loop
	{
		object.second->draw(); // draw every object
	}
	glPopMatrix();


	unlock();
}

void Level::update(float dt)
{
	lockWait();

	for(auto object : allObjects) // c++ 11 syntax for a for loop
	{
		object.second->update(dt); // draw every object
	}

	unlock();
}

void Level::addOBject(DrawableObject* object)
{
	lockWait();

	allObjects.insert(std::pair<long long,DrawableObject*>(object->uuid,object));

	unlock();
}