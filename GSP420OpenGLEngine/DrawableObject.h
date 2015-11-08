#pragma once
#include "Vector2D.hpp"

class DrawableObject
{
public:
	Vec2D position;
	Vec2D Scale;
	double rotation;

public:
	DrawableObject(void);
	~DrawableObject(void);

	virtual void draw()=0;
	virtual void update(float dt)=0;
};

