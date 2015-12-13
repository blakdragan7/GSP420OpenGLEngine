#pragma once
#include "drawableobject.h"

class GLTexture;
class GLShaderProgram;
class Sprite :
	public DrawableObject
{
protected:
	GLTexture* texture; // texture shown by this sprite
	GLShaderProgram* program; // The Shader Program Used By This Sprite.

	bool shouldRenderTexture; // if true then will bind and render texture
	bool shouldUseProgram;    // if true then will use a shader program 
	bool hasAlpha;			  //If set to true will enable alhp blending for drawing 
	bool needsDelete;		  // Set To True if this Instance Spawned The Textures and not a manager 
							
public:
	Sprite();
	Sprite(GLTexture* tex,GLShaderProgram* program=0);
	Sprite(const char* file,GLShaderProgram* program=0);
	~Sprite(void);

	virtual void draw() override; // draw call
	virtual void update(float dt) override; // update call

	void setAlpha(bool alpha=true);
};

