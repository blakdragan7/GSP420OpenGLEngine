#pragma once
#include "drawableobject.h"

class GLTexture;
class GLShaderProgram;
class Sprite :
	public DrawableObject
{
private:
	GLTexture* texture; // texture shown by this sprite
	GLShaderProgram* program; // The Shader Program Used By This Sprite.

protected:
	bool shouldRenderTexture; // if true then will bind and render texture
	bool shouldUseProgram;    // if true then will use a shader program 
							
public:
	Sprite();
	Sprite(GLTexture* tex,GLShaderProgram* program);
	Sprite(const char* file,GLShaderProgram* program);
	~Sprite(void);

	virtual void draw() override; // draw call
	virtual void update(float dt) override; // update call
};

