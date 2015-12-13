#include "lMainMenu.h"
#include "AudioSource.h"
#include "Button.h"

lMainMenu::lMainMenu(void)
{
}


lMainMenu::~lMainMenu(void)
{
}

void lMainMenu::init()
{
	Background = new Sprite("data/Levels/background.png",0);

	Start = new Button(Vec2D(0, .5), Vec2D(0.25, 0.125), "Start", "data/Buttons/Start.png", 0);
	Option = new Button(Vec2D(0, 0), Vec2D(0.25, 0.125), "Option", "data/Buttons/Options.png", 0);
	Exit = new Button(Vec2D(0, -.5), Vec2D(0.25, 0.125), "Exit", "data/Buttons/Exit.png", 0);

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

void lMainMenu::tearDown()
{
	clickSound->Delete();
	delete clickSound;
	clickSound = 0;

	Level::tearDown();
}
