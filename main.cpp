
#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"

void main()
{
	int width = 800, height = 600;
	float posX = 300, posY = 500;
	float velX, velY;

	sfw::initContext(width,height,"NSFW Draw");


	sfw::setBackgroundColor(CYAN);
	
	Player myPlayer;
	myPlayer.Tries = 2;

	Player PlayerMovement;

	ScoreandTime Time;

	Boundary drawBound;
	Ball drawBall;

	unsigned r = sfw::loadTextureMap("./res/Boundary.png");

	void BoundCollision();
	{



		if (drawBall.posY > height)
		{
			drawBall.velY *= -1;
		}
		else (drawBall.posY < height);
		{
			drawBall.velY *= 1;

		}
	}


	while (sfw::stepContext())
	{
		
		PlayerMovement.PlayerMovement();
		drawBound.drawBound();
		drawBall.drawBall();
		BoundCollision;

	}
	sfw::termContext();
}