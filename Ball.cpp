#include "sfwdraw.h"
#include <iostream>
#include "Ball.h"

void Ball::drawBall()
{
	sfw::drawCircle(posX, posY, 12, 12, RED);
}

void Ball::BallUpdate()
{
	velX = 5;
	velY = -5;

	posX += velX * sfw::getDeltaTime();
	posY += velY * sfw::getDeltaTime();
}
