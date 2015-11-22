#include "Engine.h"
#include "DrawableObject.h"
#include "Level.h"
#include "Sprite.h"
#include <ctime>

static Engine* engineInstance = 0;

void resizeWindow(GLFWwindow*,int,int);
void* UpdateThreadFunc(void* data);

Engine::Engine(void)
{
	engineInstance = this;
	shouldRun = true;
}


Engine::~Engine(void)
{
}

void Engine::init()
{
	glfwInit(); // init window library
	
	// Normally you specify Whcih Version you want to use but we dont really care since we are using legacy code anyway.
	//We willl just accept whatever version glfw gives us

	mainWindow = glfwCreateWindow(800,600,"Test Window",0,0); // create window with size 800,600
	glewExperimental = GL_FALSE; // allows glue to acess more current features its not be needed

	glfwMakeContextCurrent(mainWindow); // set the opngl context to the window
	GLenum res = glewInit();

	if ( res != GLEW_OK ) // If GLEW didnt init right then we can not continue 
	{
		throw std::exception("Error initializing Glew");
	}

	glfwSetWindowSizeCallback(mainWindow,resizeWindow);

	glViewport(0,0,800,600);
	glClearColor(0.0,0.0,0.0,1.0);

	glEnable(GL_TEXTURE_2D); // enable textures
	glDisable(GL_DEPTH_TEST); // make sure depth testing is turned off since we are 2D 

	glClearColor(1.0,0.0,0.0,1.0); // Set the Clear Color to red its not needed just something I always do

	levels.push_back(new Level()); // Add a default level

	levels[0]->addOBject(new Sprite("data/background.png",0)); // add background to default level

	currentLevel = 0; // Set current level to default level

	pthread_create(&updateThread,0,UpdateThreadFunc,this); // spawn thread for updates
}

void Engine::run()
{
	while(!glfwWindowShouldClose(mainWindow)) // if you close the window stop the program
	{
		drawGLScene(); // draw the scene
		glfwPollEvents(); // handle window events
	}
}

void Engine::shutdown()
{

	shouldRun = false;

	pthread_join(updateThread,0);

	for (auto level : levels)
	{
		delete level;
	}

	levels.clear();
}

void Engine::drawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen and depth buffer

	glMatrixMode(GL_MODELVIEW); // set matrix mode to model vuew
	glLoadIdentity(); // load identiy matric for modelview matric

	if(levels.size() > currentLevel && currentLevel >= 0)	// check to make sure the current level is valid
		levels[currentLevel]->draw();	// if so draw the level

	glfwSwapBuffers(mainWindow); // Swap Back buffer to front buffer
}

void Engine::updateAll()
{
	static clock_t lastTime = clock();
	clock_t time = clock();

	float dt = (float)(time - lastTime) / (float)CLOCKS_PER_SEC; // calculate the time difference from the last update

	if(levels.size() > currentLevel && currentLevel >= 0)	// check to make sure the current level is valid
		levels[currentLevel]->update(dt);	// if so update the level

	lastTime = time;
}

 void Engine::AddLevelToEngine(Level* newObject)
 {
	 engineInstance->levels.push_back(newObject);
 }

 void resizeWindow(GLFWwindow* window,int w,int h)
 {
	 glfwMakeContextCurrent(window);	// make sure the view being resized is the same context that changed
	 glViewport(0,0,w,h);				// resize the opengl view to cover the entire window

	 glMatrixMode(GL_PROJECTION);		
	 glLoadIdentity();
	 gluOrtho2D(-1,1,-1,1);				// set the bounds of the view to [-1, 1] in x and y

	 glMatrixMode(GL_MODELVIEW);		// set the matrix back to the modelmatrix
 }

 void* UpdateThreadFunc(void* data) // Background thread to update Engine
 {
	 Engine* engine = static_cast<Engine*>(data);

	 while(engine->shouldRun)
	 {
		 engine->updateAll();
	 }

	 return 0;
 }