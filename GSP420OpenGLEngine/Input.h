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
	GLFWwindow* window;
	int key;
	int scan_code;
	int action;
	int mods;

public:
	Input();
	Input(const Input&);
	~Input();
	void Initialize();	// sets up the mouse and keyboard
	
};