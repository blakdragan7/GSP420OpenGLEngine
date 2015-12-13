#pragma once
#include <vector>
#include "Vector2D.hpp"
#include "level.h"

class LTowerDefenceLevel :
	public Level
{
protected:
	std::vector<Vec2D> AIMoveToPoints; // EveryPointPnTheMapThatTheAIMovesTo Only left/right/up/down no diaagols

	class Sprite* background;


public:
	LTowerDefenceLevel(void);
	~LTowerDefenceLevel(void);

	virtual void init()override;
	virtual void tearDown()override;
	virtual void update(float dt) override;
};

