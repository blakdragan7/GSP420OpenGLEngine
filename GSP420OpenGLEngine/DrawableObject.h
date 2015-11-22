#pragma once
#include "stdafx.h"
#include "Vector2D.hpp"

class DrawableObject
{
protected:
	std::mutex mutex;
	bool isLocked;

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

	void lockWait();
	void unlock();
};

