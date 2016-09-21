#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "Splash.h"
#include "Quit.h"


void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	GameManager gs;
	gs.init(font);

	Splash Splash;
	Splash.init(font);

	Quit quit;
	quit.init(font);

	APP_STATE state = ENTERSPLASH;


	while (sfw::stepContext())
	{
		switch (state)
		{
		case ENTERSPLASH:
			Splash.play();
		case SPLASH:
			Splash.step();
			Splash.draw();
			state = Splash.next();
			break;
		case ENTERGAME:
			gs.init(font);
		case GAME:
			gs.update();
			gs.Draw();
			state = gs.next();
			break;
		case ENTERQUIT:
			quit.play();
		case QUIT:
			quit.step();
			quit.draw();
			state = quit.next();
			break;
		}
	}
	sfw::termContext();
}
