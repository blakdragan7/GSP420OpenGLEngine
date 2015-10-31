#include "Engine.h"


Engine::Engine(void)
{
}


Engine::~Engine(void)
{
}

void Engine::init()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	mainWindow = glfwCreateWindow(800,600,"Test Window",0,0);
	glewExperimental = GL_TRUE;

	glfwMakeContextCurrent(mainWindow);
	GLenum res = glewInit();

	if ( res != GLEW_OK )
	{
		throw std::exception("Error initializing Glew");
	}

	glViewport(0,0,800,600);
	glClearColor(0.0,0.0,0.0,1.0);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}

void Engine::run()
{

}

void Engine::shutdown()
{

}