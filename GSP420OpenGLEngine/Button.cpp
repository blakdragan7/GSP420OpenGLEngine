#include "Button.h"
#include "GLTexture.h"
#include "Engine.h"
#include "GLShaderProgram.h"
#include <GL\glew.h>

using namespace std;

Button::Button() : Sprite()
{
	position = Vec2D(0, 0);
	scaleButton(0.5, 0.25);
	tag = "";
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, string t, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	position = pos;
	scaleButton(0.5, 0.25);
	tag = t;
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, Vec2D scal, string t, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	tag = t;
	position = pos;
	scaleButton(scal);
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, Vec2D scal, string t, double rotat, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	tag = t;
	position = pos;
	scale = scal;
	rotation = rotat;
	scaleButton(scal);
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, string t, GLTexture* tex,GLShaderProgram* program) : Sprite(tex, program)
{
	tag = t;
	position = pos;
	scaleButton(0.5, 0.5);
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, string t, Vec2D scal, GLTexture* tex, GLShaderProgram* program) : Sprite(tex, program)
{
	tag = t;
	position = pos;
	scale = scal;
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::Button(Vec2D pos, string t, Vec2D scal, double rotat, GLTexture* tex, GLShaderProgram* program) : Sprite(tex, program)
{
	tag = t;
	position = pos;
	scale = scal;
	rotation = rotat;
	clickSound = 0;
	ButtonDown = false;
	hasAlpha = true;
}

Button::~Button()
{

}

void Button::setClickSound(AudioSource* sound)
{
	clickSound = sound;
}

// Translate the Button based on a Vec2D
void Button::translate(Vec2D p)
{
	position = p;
}

// Translate the Button based on a double x, and double y
void Button::translate(double x, double y)
{
	position.x = x;
	position.y = y;
}

// Scale the Button based on a Vec2D
void Button::scaleButton(Vec2D s)
{
	scale = s;
}

// Scale the Button based on a double x, and double y
void Button::scaleButton(double x, double y)
{
	scale.x = x;
	scale.y = y;
}

// Rotate the button based on a double
void Button::rotate(double r)
{
	rotation = r;
}

// Checks to see if mouse is over the button and leeft mouse button is pressed
bool Button::isClicked()
{
	bool flag = false;

	if (Input::mouseX <= position.x + scale.x && Input::mouseX >= position.x - scale.x 
		&& Input::mouseY <= position.y + scale.y && Input::mouseY >= position.y - scale.y && Input::mouse_Left)
		flag = true;
	else
		flag = false;

	return flag;
}

// Checks to see if mouse is over the button
bool Button::isHovered()
{
	bool flag = false;

	if(Input::mouseX <= position.x + scale.x && Input::mouseX >= position.x - scale.x 
		&& Input::mouseY <= position.y + scale.y && Input::mouseY >= position.y - scale.y)
		flag = true;
	else
		flag = false;

	return flag;
}

// UPDATE THE BUTTON
void Button::update(float dt)
{	
	if(isClicked())
	{
		if(clickSound && !ButtonDown)
			clickSound->Play_Sound();
		ButtonDown = true;

		setBlendColor(0.4,0.4,0.4);

	}
	else if (isHovered())
	{
		if(ButtonDown)
		{
			if(tag.compare("Start")==0)
			{
				Engine::TransitionToLevel(1);
			}
			else if(tag.compare("Exit")==0)
			{
				Engine::shouldRun = false;
			}
			else
			{

			}
		}

		setBlendColor(0.8,0.8,0.8);
		ButtonDown = false;
	}
	else
	{
		setBlendColor(1,1,1);
		ButtonDown = false;
	}
}