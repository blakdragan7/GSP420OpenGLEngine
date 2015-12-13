#pragma once
#include "level.h"

class Button;
class AudioSource;
class Sprite;
class lMainMenu :
	public Level
{
private:
	Sprite* Background;

	Button* Start;
	Button* Exit;
	Button* Option;
	AudioSource* clickSound;

public:
	lMainMenu(void);
	~lMainMenu(void);

	virtual void init();
	virtual void tearDown();
};

