#pragma once
#include "stdafx.h"

class Engine
{
private:
	GLFWwindow* mainWindow;

public:
	Engine(void);
	~Engine(void);

	void init();
	void run();
	void shutdown();
};

