#pragma once
#include "stdafx.h"
#include "Vector2D.hpp"

class DrawableObject
{
protected:
	std::mutex mutex;
	bool isLocked;

	float blendR,blendG,blendB; // Colors to blend (mix) texture color with white means no blend (1,1,1)

public:
	Vec2D position;
	Vec2D scale;
	double rotation;


	long long uuid;
public:
	DrawableObject(void);
	~DrawableObject(void);

	virtual void draw()=0;
	virtual void update(float dt)=0;

	void setBlendColor(float r,float g,float b);

	void lockWait();
	void unlock();
};

