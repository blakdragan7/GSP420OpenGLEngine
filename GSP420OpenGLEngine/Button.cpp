#include "Button.h"
#include "GLTexture.h"
#include "GLShaderProgram.h"
#include <GL\glew.h>

Button::Button() : Sprite()
{
	position = Vec2D(0, 0);
	isHovered = false;
	isClicked = false;

	scaleButton(0.5, 0.25);
}

Button::Button(Vec2D pos, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	position = pos;
	isHovered = false;
	isClicked = false;

	scaleButton(0.5, 0.25);
}

Button::Button(Vec2D pos, Vec2D scal, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	position = pos;
	isHovered = false;
	isClicked = false;

	scaleButton(scal);
}

Button::Button(Vec2D pos, Vec2D scal, double rotat, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	position = pos;
	scale = scal;
	rotation = rotat;

	isClicked = false;
	isHovered = false;

	scaleButton(scal);
}

Button::Button(Vec2D pos, GLTexture* tex,GLShaderProgram* program) : Sprite(tex, program)
{
	position = pos;
	isHovered = false;
	isClicked = false;

	scaleButton(0.5, 0.5);
}

Button::Button(Vec2D pos, Vec2D scal, GLTexture* tex, GLShaderProgram* program) : Sprite(tex, program)
{
	position = pos;
	scale = scal;

	isHovered = false;
	isClicked = false;
}

Button::Button(Vec2D pos, Vec2D scal, double rotat, GLTexture* tex, GLShaderProgram* program) : Sprite(tex, program)
{
	position = pos;
	scale = scal;
	rotation = rotat;

	isHovered = false;
	isClicked = false;
}

Button::~Button()
{

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
