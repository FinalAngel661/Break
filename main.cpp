#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "Splash.h"

void main()
{

	sfw::initContext(800, 600, "NSFW Draw");

	GameManager gs;
	gs.init();

	

	

	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	Splash Splash;
	Splash.init(font);

	APP_STATE state = ENTERSPLASH;

	//unsigned r = sfw::loadTextureMap("./res/Boundary.png");
	//unsigned s = sfw::loadTextureMap("./res/Background.jpg");

	while (sfw::stepContext())
	{
		gs.update();

		switch (state)
		{
		case ENTERSPLASH:
			Splash.play();
		case SPLASH:
			Splash.step();
			Splash.draw();
			state = Splash.next();
			break;
		}
		gs.Draw();
		//sfw::drawTexture(s, 0, height, 800, 600, 0, false);
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