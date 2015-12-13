#include "Enemy.h"

Enemy::Enemy(const char* spriteImage,std::vector<Vec2D> points) : Sprite(spriteImage)
{
	AIMoveToPoints = points;
	currentPosition = 0;
	health = 2;

	position = points[0];
	scale = Vec2D(0.08,0.08);

	speed = 0.02;
}

Enemy::~Enemy(void)
{
}

void Enemy::update(float dt)
{
	if(currentPosition >= AIMoveToPoints.size()-1)
		return;

	Vec2D nextPoint = AIMoveToPoints[currentPosition+1];
	Vec2D direction = nextPoint - position;
	Vec2D diff = direction;
	direction.normalize();

	Vec2D deltaT = direction * speed * (double)dt;

	if(deltaT < diff)
		position += deltaT;
	else
	{
		position = nextPoint;
		currentPosition++;
	}
}

bool Enemy::wasHit()
{
	health -= 1;

	return health > 0;
}