#include "Engine.h"
#include "DrawableObject.h"
#include "Sprite.h"
#include <ctime>

static Engine* engineInstance = 0;

void resizeWindow(GLFWwindow*,int,int);

Engine::Engine(void)
{
	engineInstance = this;
}


Engine::~Engine(void)
{
	for(auto object : allObjects) // remove all objects safely
	{
		delete object;
	}

	allObjects.clear(); // clear the array
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

	allObjects.push_back(new Sprite("data/background.png",0)); // add background Sprite to list of drawable Objects
}

void Engine::run()
{
	while(!glfwWindowShouldClose(mainWindow)) // if you close the window stop the program
	{
		drawGLScene(); // draw the scene
		updateAll(); // update all objects
		glfwPollEvents(); // handle window events
	}
}

void Engine::shutdown()
{

}

void Engine::drawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the screen and depth buffer

	glMatrixMode(GL_MODELVIEW); // set matrix mode to model vuew
	glLoadIdentity(); // load identiy matric for modelview matric

	for(auto object : allObjects) // c++ 11 syntax for a for loop
	{
		object->draw(); // draw every object
	}

	glfwSwapBuffers(mainWindow); // Swap Back buffer to front buffer
}

void Engine::updateAll()
{
	static clock_t lastTime = clock();
	clock_t time = clock();

	float dt = (float)(time - lastTime) / (float)CLOCKS_PER_SEC; // calculate the time difference from the last update

	for(auto object : allObjects) // c++ 11 syntax for a for loop
	{
		object->update(dt);  // Update every object by the time difference
	}

	lastTime = time;
}

 void Engine::AddObjectToEngine(DrawableObject* newObject)
 {
	 engineInstance->allObjects.push_back(newObject);
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