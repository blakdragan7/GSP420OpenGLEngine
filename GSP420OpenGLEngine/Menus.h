#ifndef MENUS_H
#define MENUS_H

#include <string>
#include "Sprite.h"

enum Buttons
{
	Start_Game,
	Exit,
	Single_Player,
	Multiplayer,
	Back
};

class Menus : public Sprite
{
private:
	float x;
	float y;
	std::string text;
	Buttons button;

public:
	Menus();
	Menus(float x, float y, std::string text, Buttons);
	Menus(float x, float y, const char* file, GLShaderProgram* program);
	void Draw();
	bool ButtonPressed();
	bool ButtonHovered();
};

#endif