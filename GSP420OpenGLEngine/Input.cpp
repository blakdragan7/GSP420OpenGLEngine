#include "Input.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////     CURRENT BUGS AND ISSUES      ///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																Updated:	11/15/15																						  //
//																Updated by:	Jacob Cook																						  //
//																																											  //
//	void Initialize() throws errors																																			  //
//	1. error C3867: 'Input::Key_Callback': function call missing argument list; use '&Input::Key_Callback to create pointer to member.										  //
//	2. IntelliSense: argument of type "void (Input::*)(GLFWwindow *window, int key, int scan_code, int action, int mods)" is incompatible with parameter of type "GLFWkeyfun" //
//																																											  //
//	3. error C3867: 'Input::Cursor_Position_Callback': function call missing argument list; use '&Input::Cursor_Position_Callback' to create a pointer to member.			  //
//	4. IntelliSense argument of type "void (Input::*)(GLFWwindow *window, double xpos, double ypos)" is incompatible with parameter of type "GLFWcursorfun".				  //
//																																											  //
//	5. error C3867: 'Input::Mouse_Button_Callback': function call missing argument list; use '&Input::Mouse_Button_Callback' to create a pointer to member.					  //
//	6. IntelliSense argument of type "void (Input::*)(GLFWwindow *window, int button, int action, int mods)" is incompatible with parameter of type "GLFWmousebuttonfun".	  //
//																																											  //
//	7. error C3867: 'Input::Scroll_Callback': function call missing argument list; use '&Input::Scroll_Callback' to create a pointer to member.								  //
//	8. IntelliSense argument of type "void (Input::*)(GLFWwindow *window, double xoffset, double yoffset)" is incompatible with parameter of type "GLFWscrollfun".			  //
//																																											  //
//	Placing '&' anywhere on the functions return more errors.																												  //
//	When I set the functions up as the data types such as GLFWkeyfun, or the others, it demands a return value that matches the same type.									  //
//	The example code on: http://www.glfw.org/docs/latest/input.html#input_key doesn't show any of this as being an issue so I'm unsure of what's wrong						  //
//																																											  //
//																Updated:	11/19/15																						  //
//																Updated by: Jacob Cook																						  //
//																																											  //
//	No bugs or errors are currently present.																																  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////		BUG FIXES		////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																Updated:	11/19/15																						  //
//																Updated by:	Jacob Cook																						  //
//																																											  //
//	Added function prototypes:																																				  //
//						+ void Key_Callback(GLFWwindow*, int, int, int, int);																								  //
//						+ void Cursor_Position_Callback(GLFWwindow*, double, double);																						  //
//						+ void Mouse_Button_Callback(GLFWwindow*, int, int, int);																							  //
//						+ void Scroll_Callback(GLFWwindow*, double, double);																								  //
//																																											  //
//	Changed the function definitions from class functions to regular functions.																								  //
//	Removed the commented out code.																																			  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Key_Callback(GLFWwindow*, int, int, int, int);
void Cursor_Position_Callback(GLFWwindow*, double, double);
void Mouse_Button_Callback(GLFWwindow*, int, int, int);
void Scroll_Callback(GLFWwindow*, double, double);

Input::Input()
{

}

Input::Input(const Input&)
{

}

Input::~Input()
{

}

void Input::Initialize()
{
	/*
	Setup the keyboard and mouse functions
	*/

	glfwSetKeyCallback(window, Key_Callback);						// sets up the keyboard input
	glfwSetCursorPosCallback(window, Cursor_Position_Callback);		// tracks the cursor's position
	glfwSetMouseButtonCallback(window, Mouse_Button_Callback);		// setus up the mouse button input
	glfwSetScrollCallback(window, Scroll_Callback);					// tracks the mouse's scroll wheel
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);		// allows the mouse to move freely between windows
}

void Key_Callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
{
	/*
	Setup keyboard keys that can be pressed
	Set keys to take action on release to prevent multiple calls being made per frame
	Need keys for manipulating the camera and pausing/exiting the program
	*/

	if (key == GLFW_KEY_W && action == GLFW_RELEASE)
	{
		/*
		W key has been released
		*/
	}

	if (key == GLFW_KEY_A && action == GLFW_RELEASE)
	{
		/*
		A key has been released
		*/
	}

	if (key == GLFW_KEY_S && action == GLFW_RELEASE)
	{
		/*
		S key has been released
		*/
	}

	if (key == GLFW_KEY_D && action == GLFW_RELEASE)
	{
		/*
		D key has been released
		*/
	}

	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
	{
		/*
		ESCAPE key has been released
		*/
	}

	if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
	{
		/*
		UP key has been released
		*/
	}

	if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
	{
		/*
		LEFT key has been released
		*/
	}

	if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
	{
		/*
		DOWN key has been released
		*/
	}

	if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
	{
		/*
		RIGHT key has been released
		*/
	}

	
}

void Cursor_Position_Callback(GLFWwindow* window, double xpos, double ypos)
{
	/*
	Poll the cursor for its position
	*/

	glfwGetCursorPos(window, &xpos, &ypos);	// poll cursor position

	return;
}

void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
{
	/*
	Setup mouse button on release to prevent multiple calls from being made per frame
	Need mouse button functionality for 3 buttons: Left, Middle, Right
	*/

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		/*
		LEFT mouse button has been released
		*/
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		/*
		RIGHT mouse button has been released
		*/
	}

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
	{
		/*
		MIDDLE mouse button has been released
		*/
	}

	return;
}

void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
{
	/*
	Setup mouse scrolling functionality
	*/

	return;
}