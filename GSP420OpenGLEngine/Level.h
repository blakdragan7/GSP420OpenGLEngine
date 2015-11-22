#pragma once
#include <map>
#include "DrawableObject.h"

class Level : public DrawableObject
{
private:
	std::map<long long,DrawableObject*> allObjects;

public:
	Level(void);
	~Level(void);

	virtual void draw() override;
	virtual void update(float dt) override;

	void addOBject(DrawableObject* object);
};

