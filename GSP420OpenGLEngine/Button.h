#pragma once

#include "Sprite.h"

class Button : public Sprite
{
private:
	bool isClicked;
	bool isHovered;

public:
	Button();

	// CONSTRUCTORS WITH FILE NAME
	Button(Vec2D pos, const char* file, GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, const char* file, GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, double rotat, const char* file, GLShaderProgram* program);

	// CONSTRUCTORS WITH GLTEXTURE OBJECT
	Button(Vec2D pos, GLTexture* tex,GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, GLTexture* tex,GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, double rotat, GLTexture* tex,GLShaderProgram* program);
	
	~Button();

	// BUTTON TRANSFORMATION METHODS
	void translate(Vec2D p);
	void translate(double x, double y);
	void scaleButton(Vec2D s);
	void scaleButton(double x, double y);
	void rotate(double r);
};