#pragma once
#include "stdafx.h"

////////////////////////////////////////////////////////////////////////////
//	Author: Jacob Cook													  //
//	Input Core Class													  //
//																		  //
//	Sets up the keyboard, mouse buttons, mouse position, and mouse wheel. //
//	Gets the state of the keys of the keyboard.							  //
//	Gets the state of the mouse buttons.								  //
//	Gets the state of the mouse wheel.									  //
//	Tracks the position of the mouse.									  //
//																		  //
//	UPDATED:	11/19/2015												  //
//	CHANGES MADE:														  //
//	+ Deleted 4 public functions										  //
//		- void Key_Callback(GLFWwindow*, int, int, int, int);			  //
//		- void Cursor_Position_Callback(GLFWwindow*, double, double);	  //
//		- void Mouse_Button_Callback(GLFWwindow*, int, int, int);		  //
//		- void Scroll_Callback(GLFWwindow*, double, double);			  //
////////////////////////////////////////////////////////////////////////////

class Input
{
private:
	

public:
	
	static void Initialize(GLFWwindow* w);	// sets up the mouse and keyboard
	static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void SetCursorPos(GLFWwindow* window, double xpos, double ypos);
	static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods);

	// Mouse Info
	static double mouseX;
	static double mouseY;

	// Mouse Press Info
	static bool mouse_Left;
	static bool mouse_Right;
	static bool mouse_Middle;

	// Keyboard Info
	static int key;
	static int scan_code;
	static int action;
	static int mods;
	
	Input();
	Input(const Input&);
	~Input();
	

	
};