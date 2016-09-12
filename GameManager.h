#pragma once

#include "sfwdraw.h"
#include <iostream>
#include <conio.h>


const float identity[16] = { 1,0,0,0,  0,1,0,0, 0,0,1,0, 0,0,0,1 };


struct Player
{
	float Tries = 2;
	float x = 300;


	void PlayerMovement()
	{
		if (sfw::getKey('W'))
		{
			x += 1;
		}

		sfw::drawLine(x, 100, x + 100, 100);

		if (sfw::getKey('S'))
		{

			x -= 1;
		}

		sfw::drawLine(x, 100, x - 100, 100);

		if (sfw::getKey('A'))
		{


		}

		if (sfw::getKey('D'))
		{


		}

	}

};


struct Obstacles
{
	float x = 300;

	void VObstacle()
	{
		sfw::drawLine(x, 100, x + 100, 100);

		sfw::drawLine(x, 100, x - 100, 100);

	}

};




struct Ball
{
	float posX = 300, posY = 500;
	float velX, velY;

	void drawBall()
	{

		velX = 1;
		velY = -1;

		posX += velX * sfw::getDeltaTime();
		posY += velY * sfw::getDeltaTime();

		printf("%f,%f\n", posX, posY);

		sfw::drawCircle(posX, posY, 12, 12, RED);
		
	}



};


struct Boundary
{
	int width = 800, height = 600;


	

	void drawBound()
	{
		unsigned r = sfw::loadTextureMap("./res/Boundary.png");
		sfw::drawTexture(r, 785, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
		sfw::drawTexture(r, 50, 595, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
	}

	void BoundCollision()
	{
		if (drawBall.posY > height)
		{
			velY *= -1;
		}
		else (drawBall.posY < height)
		{
			velY *= 1;

		}
	}

};

struct ScoreandTime
{

	void Time()
	{
		float x = 100, y = 100;
		float x2 = 500, y2 = 100;
		float counter = 0;
		float size = 400;

		while (sfw::stepContext)
		{
			counter += sfw::getDeltaTime();
			if (counter > 1.f)
			{
				counter = 0;
				size /= 2;
			}
		}

		if (sfw::getKey('W'))
			y += sfw::getDeltaTime() * 30;

		if (sfw::getKey('S'))
			y -= sfw::getDeltaTime() * 30;


		if (sfw::getKey('A'))
			y2 += sfw::getDeltaTime() * 30;

		if (sfw::getKey('D'))
			y2 -= sfw::getDeltaTime() * 30;

		sfw::drawLine(x, y, x, y + size, CYAN);
		sfw::drawLine(x2, y2, x2, y2 + size, RED);

	}

	void Score()
	{


	}



};

struct GameManager
{
	Player player1;
	int p1score;

};