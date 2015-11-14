#pragma once
#include "stdafx.h"
#include <vector>

#define BACKGROUND_SPRITE 0

/*
	there shoul only ever be one engine at a time
	if more then one is created the the last one made is what will be used with  AddObjectToEngine
*/

class DrawableObject;
class Engine
{
private:
	GLFWwindow* mainWindow;
	std::vector<DrawableObject*> allObjects;

public:
	Engine(void);
	~Engine(void);

	void init(); // initialize the engine
	void run(); // main run loop
	void shutdown(); // de init everything

	void drawGLScene(); // draw the scene
	void updateAll(); // ipdate every object

	static void AddObjectToEngine(DrawableObject* newObject); // used to add an object to the egnine so that it is drawn and updated 
};

