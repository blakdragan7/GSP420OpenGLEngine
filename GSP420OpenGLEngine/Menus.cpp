#include "stdafx.h"
#include "Menus.h"
#include "GLTexture.h"
#include "GLShaderProgram.h"
#include <GL\glew.h>

Menus::Menus()
{
	this->x = 100;
	this->y = 100;
	this->text = "";
}

Menus::Menus(float x, float y, std::string text, Buttons button)
{
	this->x = x;
	this->y = y;
	this->text = text;
}

Menus::Menus(float x, float y, const char* file, GLShaderProgram* program) : Sprite(file, program)
{
	this->x = x;
	this->y = y;

	glMatrixMode(GL_MODELVIEW); // Set The Current Matrix being modified (options are ModelView , Model, View, Projection, and Texture)

	glPushMatrix(); // Save Current Matrix and copy we only modify the copy

	// We use Matricies to translate rotate and scale the sprite instead of modifiy vertecie 
	// location becasue matrix multiplications are very faster and easier to store

	glTranslatef(position.x, position.y, 0);	// Translate the ModelView
	glScalef(scale.x, scale.y, 1.0);			// Scale The ModelView     
	glRotatef(rotation, 0, 0, 1.0);			// we rotate on the z axis since it is only a 2D scene

	// Texture and Shader 

	if (texture && shouldRenderTexture)
		texture->bindTexture(GL_TEXTURE0); // binds the texture to slot 0

	if (program && shouldUseProgram)
		program->useProgram(); // tells opengl to use our custom shader
	else
		glUseProgram(0); // Sets the current shader program to the default program

	glBegin(GL_QUADS); // Begin Drawing QUADS

	// Drawing is done in a counter clockwise order because openGl CULLS (doesnt render) 
	// things going in a clockwise direction as they are assumed to be facing away from the camera

	glTexCoord2f(0, 0);
	glVertex2f(-x, -y);
	glTexCoord2f(1, 0);
	glVertex2f(x, -y);
	glTexCoord2f(1, -1);
	glVertex2f(x, y);
	glTexCoord2f(0, 1);
	glVertex2f(-x, y);

	glScalef(x - 100, y - 100, 1.0f);

	glEnd();

	glPopMatrix();
}

void Menus::Draw()
{
	glMatrixMode(GL_MODELVIEW); // Set The Current Matrix being modified (options are ModelView , Model, View, Projection, and Texture)

	glPushMatrix(); // Save Current Matrix and copy we only modify the copy

	// We use Matricies to translate rotate and scale the sprite instead of modifiy vertecie 
	// location becasue matrix multiplications are very faster and easier to store

	glTranslatef(position.x, position.y, 0);	// Translate the ModelView
	glScalef(scale.x, scale.y, 1.0);			// Scale The ModelView     
	glRotatef(rotation, 0, 0, 1.0);			// we rotate on the z axis since it is only a 2D scene

	// Texture and Shader 

	if (texture && shouldRenderTexture)
		texture->bindTexture(GL_TEXTURE0); // binds the texture to slot 0

	if (program && shouldUseProgram)
		program->useProgram(); // tells opengl to use our custom shader
	else
		glUseProgram(0); // Sets the current shader program to the default program

	glBegin(GL_QUADS); // Begin Drawing QUADS

	// Drawing is done in a counter clockwise order because openGl CULLS (doesnt render) 
	// things going in a clockwise direction as they are assumed to be facing away from the camera

	glTexCoord2f(0, 0);
	glVertex2f(-x, -y);
	glTexCoord2f(1, 0);
	glVertex2f(x, -y);
	glTexCoord2f(1, -1);
	glVertex2f(x, y);
	glTexCoord2f(0, 1);
	glVertex2f(-x, y);

	glEnd();

	glPopMatrix();
}

bool Menus::ButtonHovered()
{
	bool hovered = false;

	//if (hovered == true)
	//{
	//	switch (hovered)
	//	{
	//	case Buttons::Start_Game:
	//		// scale button
	//		glScalef(x, y, 0);
	//		break;

	//	case Buttons::Exit:
	//		// scale button
	//		glScalef(x, y, 0);
	//		break;

	//	case Buttons::Single_Player:
	//		// scale button
	//		glScalef(x, y, 0);
	//		break;

	//	case Buttons::Multiplayer:
	//		// scale button
	//		glScalef(x, y, 0);
	//		break;

	//	case Buttons::Back:
	//		// scale button
	//		glScalef(x, y, 0);
	//		break;

	//	default:
	//		// unscale button
	//		glScalef(x, y, 0);
	//	}
	//}
	return hovered;
}

bool Menus::ButtonPressed()
{
	bool pressed = false;

	return pressed;
}