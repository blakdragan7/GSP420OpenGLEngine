#pragma once
#include "stdafx.h"
#include <vector>

#define BACKGROUND_SPRITE 0

/*
	there shoul only ever be one engine at a time
	if more then one is created the the last one made is what will be used with  AddObjectToEngine
*/

 // Pre declar All classes as to avoid include loops

class DrawableObject;
class Level;

class Engine
{
private:
	GLFWwindow* mainWindow;
	std::vector<Level*> levels;

	int currentLevel;
	pthread_t updateThread;

	bool shouldRun;

public:
	Engine(void);
	~Engine(void);

	void init(); // initialize the engine
	void run(); // main run loop
	void shutdown(); // de init everything

	void drawGLScene(); // draw the scene
	void updateAll(); // ipdate every object

	void setLevel(int level); // sets the current level to be drawn and updated
	void setLevel(Level* level); // sets the current leleve to be dran and updated

	static void AddLevelToEngine(Level* newObject); // used to add an level to the egnine so that it is drawn and updated 

	friend void* UpdateThreadFunc(void*); // Make update thread func friend of class so it can access private variables
};

