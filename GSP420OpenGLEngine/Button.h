#pragma once
#include "Sprite.h"
#include "Input.h"
#include "Engine.h"
#include "AudioSource.h"

class Button : public Sprite
{
private:
	std::string tag;
	AudioSource* clickSound;
	bool ButtonDown;

public:
	Button();

	// CONSTRUCTORS WITH FILE NAME
	Button(Vec2D pos, std::string t, const char* file, GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, std::string t, const char* file, GLShaderProgram* program);
	Button(Vec2D pos, Vec2D scal, std::string t, double rotat, const char* file, GLShaderProgram* program);

	// CONSTRUCTORS WITH GLTEXTURE OBJECT
	Button(Vec2D pos, std::string t, GLTexture* tex,GLShaderProgram* program);
	Button(Vec2D pos, std::string t, Vec2D scal, GLTexture* tex,GLShaderProgram* program);
	Button(Vec2D pos, std::string t, Vec2D scal, double rotat, GLTexture* tex,GLShaderProgram* program);
	
	// DECONSTRUCTOR
	~Button();

	// Sets the sound to be used when clicked
	void setClickSound(AudioSource* sound);

	// BUTTON TRANSFORMATION METHODS
	void translate(Vec2D p);
	void translate(double x, double y);
	void scaleButton(Vec2D s);
	void scaleButton(double x, double y);
	void rotate(double r);

	// CHECK IF BUTTON IS CLICK ON OR IS HOVERED OVER
	bool isClicked();
	bool isHovered();

	// UPDATE THE BUTTON
	void update(float dt);
};