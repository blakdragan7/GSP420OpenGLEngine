#pragma once
#include "drawableobject.h"

class GLTexture;
class Sprite :
	public DrawableObject
{
private:
	GLTexture* texture;

public:
	Sprite(void);
	~Sprite(void);

	virtual void draw() override{};
	virtual void update(float dt) override{};
};

