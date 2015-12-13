#pragma once
#include "sprite.h"
#include <vector>

class Enemy :
	public Sprite
{
private:
	std::vector<Vec2D> AIMoveToPoints; // EveryPointPnTheMapThatTheAIMovesTo Only left/right/up/down no diaagols
	int currentPosition; // last point from AIMoveToPoints that this enemy arrived at
	float speed; // speed that this enemy moves
	float health; // TotalNumberOfhitsLeft

public:
	Enemy(const char* spriteImage,std::vector<Vec2D> points);
	~Enemy(void);

	virtual void update(float dt)override;
	bool wasHit();
};

