#include "LTowerDefenceLevel.h"
#include "Enemy.h"
#include "Sprite.h"

LTowerDefenceLevel::LTowerDefenceLevel(void)
{
	AIMoveToPoints.push_back(Vec2D(-0.95 ,-0.55));
	AIMoveToPoints.push_back(Vec2D(-0.335,-0.55));
	AIMoveToPoints.push_back(Vec2D(-0.335,-0.11));
	AIMoveToPoints.push_back(Vec2D(0.3125,-0.11));
	AIMoveToPoints.push_back(Vec2D(0.3125, 0.223));
	AIMoveToPoints.push_back(Vec2D(0.9775, 0.223));
}


LTowerDefenceLevel::~LTowerDefenceLevel(void)
{
	AIMoveToPoints.clear();
}

void LTowerDefenceLevel::init()
{
	background = new Sprite("data/Levels/DemoBackground.png");

	addOBject(background);

	addOBject(new Enemy("data/Objects/Enemy.png",AIMoveToPoints));
}

void LTowerDefenceLevel::tearDown()
{
	Level::tearDown();
}

void LTowerDefenceLevel::update(float dt)
{
	Level::update(dt);
}