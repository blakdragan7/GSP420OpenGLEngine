#include "lMainMenu.h"
#include "AudioSource.h"
#include "Button.h"

lMainMenu::lMainMenu(void)
{
	Background = new Sprite("data/background.png",0);

	Start = new Button(Vec2D(0, .5), Vec2D(0.25, 0.125), "Start", "data/Start.png", 0);
	Option = new Button(Vec2D(0, 0), Vec2D(0.25, 0.125), "Option", "data/Start.png", 0);
	Exit = new Button(Vec2D(0, -.5), Vec2D(0.25, 0.125), "Exit", "data/Start.png", 0);

	clickSound = new AudioSource();
	clickSound->Load("data\\Sound Effects and Music\\Button click\\Button click_2.wav",AL_FALSE);

	Start->setClickSound(clickSound);
	Exit->setClickSound(clickSound);
	Option->setClickSound(clickSound);

	addOBject(Background);
	addOBject(Start);
	addOBject(Option);
	addOBject(Exit);
}


lMainMenu::~lMainMenu(void)
{
	clickSound->Delete();
	delete clickSound;
	clickSound = 0;
}
