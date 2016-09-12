
#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"

void main()
{

	GameManager gs;


	int width = 800, height = 600;
	float posX = 300, posY = 500;
	float velX, velY;

	sfw::initContext(width,height,"NSFW Draw");

	sfw::setBackgroundColor(CYAN);

	unsigned r = sfw::loadTextureMap("./res/Boundary.png");

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


	while (sfw::stepContext())
	{
		gs.update();
		
		/*if (isColliding(Ball, Player, Boundary))
		{
			Ball.flipX();
			Ball.flipY();
		}
		*/

		gs.drawStatus();
	}
	sfw::termContext();
}