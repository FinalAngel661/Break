#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "Splash.h"


void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	GameManager gs;
	gs.init(font);

	Splash Splash;
	Splash.init(font);

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
		}
	}
	sfw::termContext();
}


/*void BoundCollision();
{



if (drawBall.posY > height)
{
drawBall.velY *= -1;
}
else (drawBall.posY < height);
{
drawBall.velY *= 1;

}
}*/

/*if (isColliding(Ball, Player, Boundary))
{
Ball.flipX();
Ball.flipY();
}
*/

//float posX = 300, posY = 500;
//float velX, velY;