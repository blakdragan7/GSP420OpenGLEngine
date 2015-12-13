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

	int currentLevel,nextLevel,lastLevel;
	pthread_t updateThread;

public:
	Engine(void);
	~Engine(void);

	void init(int argc, _TCHAR* argv[]); // initialize the engine
	void run(); // main run loop
	void shutdown(); // de init everything

	void drawGLScene(); // draw the scene
	void updateAll(); // ipdate every object

	void setLevel(int level); // sets the current level to be drawn and updated
	void setLevel(Level* level); // sets the current leleve to be dran and updated

	static int AddLevelToEngine(Level* newObject); // used to add an level to the egnine so that it is drawn and updated  returns the index of the level added
	static void TransitionToLevel(int LevelIndex); // UseToChangeLevels

	friend void* UpdateThreadFunc(void*); // Make update thread func friend of class so it can access private variables

	static int argc;
	static _TCHAR** argv;

	static bool shouldRun;
};

