#include "Input.h"
#include <iostream>



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

bool Input::mouse_Left = false;
bool Input::mouse_Right = false;
bool Input::mouse_Middle = false;

double Input::mouseX = 0.0;
double Input::mouseY = 0.0;

int Input::key = 0;
int Input::scan_code = 0;
int Input::action = 0;
int Input::mods = 0;

Input::Input()
{

}

Input::Input(const Input &I)
{

}

Input::~Input()
{

}

void Input::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Input::key = key;
	Input::scan_code = scancode;
	Input::action = action;
	Input::mods = mods;
}

void Input::Initialize(GLFWwindow* w)
{
	/*
	Setup the keyboard and mouse functions
	*/

	glfwSetKeyCallback(w, Key_Callback);						// sets up the keyboard input
	glfwSetCursorPosCallback(w, SetCursorPos);					// tracks the cursor's position
	glfwSetMouseButtonCallback(w, Mouse_Button_Callback);	// setus up the mouse button input
	//glfwSetScrollCallback(window, Scroll_Callback);				// tracks the mouse's scroll wheel
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_NORMAL);		// allows the mouse to move freely between windows
}

void Input::SetCursorPos(GLFWwindow* window, double xpos, double ypos)
{
	/*
		Poll the cursor for its position
	*/

	int width = 0;
	int height = 0;

	glfwGetWindowSize(window,&width,&height);
	glfwGetCursorPos(window, &xpos, &ypos);	// poll cursor position

	Input::mouseX = (xpos * 2.0 / (float)width) - 1.0;
	Input::mouseY = (ypos * 2.0 / (float)-height) + 1.0;

	//std::cout << Input::mouseX << " " << Input::mouseY << std::endl;
	
	return;
}

void Input::Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
{
	/*
	Setup mouse button on release to prevent multiple calls from being made per frame
	Need mouse button functionality for 3 buttons: Left, Middle, Right
	*/

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Input::mouse_Left = true;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		/*
		RIGHT mouse button has been released
		*/
		Input::mouse_Right = true;
	}

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
	{
		/*
		MIDDLE mouse button has been released
		*/
		Input::mouse_Middle = true;
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		Input::mouse_Left = false;
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		/*
		RIGHT mouse button has been released
		*/
		Input::mouse_Right = false;
	}

	if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_RELEASE)
	{
		/*
		MIDDLE mouse button has been released
		*/
		Input::mouse_Middle = false;
	}

	return;
}

//void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	/*
//	Setup mouse scrolling functionality
//	*/
//
//	return;
//}