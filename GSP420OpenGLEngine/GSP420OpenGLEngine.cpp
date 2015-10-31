// GSP420OpenGLEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Engine engine;

	engine.init();
	engine.run();
	engine.shutdown();

	return 0;
}

