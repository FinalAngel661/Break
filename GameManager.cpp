#include "sfwdraw.h"
#include <iostream>
#include <conio.h>
#include "GameManager.h"
#include "Graphics.h"

const float identity[16] = { 1,0,0,0,  0,1,0,0, 0,0,1,0, 0,0,0,1 };

void GameManager::init()
{
	//paddle logic
	playerx = 300;

	//ball logic
	 posX = 300, posY = 500;

	// time and score
	 x = 100;
	 y = 100;
	 x2 = 500;
	 y2 = 100;
	 counter = 0;
	 size = 400;

	 pl.init("%s");
	 ball.init();
	 bo.init();
	 gr.init();

}

void GameManager::update()
{

	pl.PlayerUpdate();
	ball.BallUpdate();
	if (collision(pl, ball))
	{
		ball.velY = -ball.velY;
		/*ball.posY -= pl.playery - (ball.posY + ball.radius);*/
	}
	if (BoundCollision(bo, ball))
	{
		ball.velY = -ball.velY;

	}

}


void GameManager::Draw()
{
	gr.drawBackgound();
	gr.drawBoundary();
	pl.drawPlayer();
	ball.drawBall();


}

bool GameManager::collision(Player pl,Ball ball)
{
	if (pl.playery < ball.posY && pl.playery > ball.posY - ball.radius)
	{
		if (ball.posX + ball.radius > pl.playerx - 100 && ball.posX + ball.radius < pl.playerx + 100)
		{
			return true;
		}
		else if (ball.posX - ball.radius > pl.playerx - 100 && ball.posX - ball.radius < pl.playerx + 100)
		{
			return true;
		}
	}
	return false;
}

void Bound::init()
{
	int Window_Width = 800;
	int Window_Height = 600;

}



bool GameManager::BoundCollision(Bound bo, Ball ball)
{
	if (bo.Window_Height < ball.posY && bo.Window_Height > ball.posY - ball.radius)
	{
		if (ball.posX + ball.radius > bo.Window_Width - 100 && ball.posX + ball.radius < bo.Window_Width + 100)
		{
			return true;
		}
		else if (ball.posX - ball.radius > bo.Window_Width - 100 && ball.posX - ball.radius < bo.Window_Width + 100)
		{
			return true;
		}
	}

	return false;
}


void Player::init(const char a_name[])
{
	lives = 1;

}

void Player::takeDamage(int dmg)
{
	lives -= dmg;
}

void Player::drawPlayer()
{
	sfw::drawLine(playerx, playery, playerx + 100, 300);
	sfw::drawLine(playerx, playery, playerx - 100, 300);

}

void Player::PlayerUpdate()
{

	if (sfw::getKey('W'))
	{
		playerx += 1;
	}

	if (sfw::getKey('S'))
	{
		playerx -= 1;
	}


	if (sfw::getKey('A'))
	{


	}

	if (sfw::getKey('D'))
	{


	}

}



void Ball::init()
{
	velX = 0;
	velY = -25;
	posX = 500; posY = 500;
}

void Ball::drawBall()
{
	sfw::drawCircle(posX, posY, radius, 12, RED);
}

void Ball::BallUpdate()
{

	posX += velX * sfw::getDeltaTime();
	posY += velY * sfw::getDeltaTime();
}


void Graphics::init()
{
	bounds = sfw::loadTextureMap("./res/Boundary.png");
	background = sfw::loadTextureMap("./res/Background.jpg");
}

void Graphics::drawBoundary()
{
	
	sfw::drawTexture(bounds, 785, 50, sfw::getTextureWidth(bounds), sfw::getTextureHeight(bounds), 90, false, 0, 0x88888888);
	sfw::drawTexture(bounds, 5, 50, sfw::getTextureWidth(bounds), sfw::getTextureHeight(bounds), 90, false, 0, 0x88888888);
	sfw::drawTexture(bounds, 50, 595, sfw::getTextureWidth(bounds), sfw::getTextureHeight(bounds), 0, false, 0, 0x88888888);
	sfw::drawTexture(bounds, 5, 50, sfw::getTextureWidth(bounds), sfw::getTextureHeight(bounds), 0, false, 0, 0x88888888);
}

void Graphics::drawBackgound()
{
	sfw::drawTexture(background, 400,300, sfw::getTextureWidth(background), sfw::getTextureHeight(background), 0, true);
}


bool GameManager::isGameOver() const
{
	return false;
}


//void GameManager::drawRound()
//{
//
//	
//}



//class GameManager
//{
//
//	class Player
//	{
//		float Tries = 2;
//		float x = 300;
//
//		void PlayerMovement()
//		{
//			if (sfw::getKey('W'))
//			{
//				x += 1;
//			}
//
//			sfw::drawLine(x, 100, x + 100, 100);
//
//			if (sfw::getKey('S'))
//			{
//				x -= 1;
//			}
//
//			sfw::drawLine(x, 100, x - 100, 100);
//
//			if (sfw::getKey('A'))
//			{
//
//
//			}
//
//			if (sfw::getKey('D'))
//			{
//
//
//			}
//		}
//	};
//
//	class GameMechanics
//	{
//		//Ball Mechanics
//		float posX = 300, posY = 500;
//		float velX, velY;
//
//		void drawBall()
//		{
//
//			velX = 5;
//			velY = -5;
//
//			posX += velX * sfw::getDeltaTime();
//			posY += velY * sfw::getDeltaTime();
//
//			printf("%f,%f\n", posX, posY);
//
//			sfw::drawCircle(posX, posY, 12, 12, RED);
//
//		}
//
//		//Boundary Mechanics
//
//		int width = 800, height = 600;
//
//
//
//
//		void drawBound()
//		{
//			unsigned r = sfw::loadTextureMap("./res/Boundary.png");
//			sfw::drawTexture(r, 785, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
//			sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
//			sfw::drawTexture(r, 50, 595, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
//			sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
//		}
//
//		void BoundCollision()
//		{
//			if (float drawBall.posY > height)
//			{
//				velY *= -1;
//			}
//			else (drawBall.posY < height)
//			{
//				velY *= 1;
//
//			}
//
//		}
//
//
//
//
//		//Obstacles
//
//		float x = 300;
//
//		void VObstacle()
//		{
//			sfw::drawLine(x, 100, x + 100, 100);
//
//			sfw::drawLine(x, 100, x - 100, 100);
//
//		}
//
//		// Time and Score
//		void Time()
//		{
//			float x = 100, y = 100;
//			float x2 = 500, y2 = 100;
//			float counter = 0;
//			float size = 400;
//
//			while (sfw::stepContext)
//			{
//				counter += sfw::getDeltaTime();
//				if (counter > 1.f)
//				{
//					counter = 0;
//					size /= 2;
//				}
//			}
//
//			if (sfw::getKey('W'))
//				y += sfw::getDeltaTime() * 30;
//
//			if (sfw::getKey('S'))
//				y -= sfw::getDeltaTime() * 30;
//
//
//			if (sfw::getKey('A'))
//				y2 += sfw::getDeltaTime() * 30;
//
//			if (sfw::getKey('D'))
//				y2 -= sfw::getDeltaTime() * 30;
//
//			sfw::drawLine(x, y, x, y + size, CYAN);
//			sfw::drawLine(x2, y2, x2, y2 + size, RED);
//
//		}
//
//		void Score()
//		{
//			Player player1;
//			int p1score;
//
//		}
//
//
//
//
//
//
//
//	};
//
//};














//struct Obstacles
//{
//	float x = 300;
//
//	void VObstacle()
//	{
//		sfw::drawLine(x, 100, x + 100, 100);
//
//		sfw::drawLine(x, 100, x - 100, 100);
//
//	}
//
//};



//
//struct Ball
//{
//	float posX = 300, posY = 500;
//	float velX, velY;
//
//	void drawBall()
//	{
//
//		velX = 5;
//		velY = -5;
//
//		posX += velX * sfw::getDeltaTime();
//		posY += velY * sfw::getDeltaTime();
//
//		printf("%f,%f\n", posX, posY);
//
//		sfw::drawCircle(posX, posY, 12, 12, RED);
//		
//	}
//
//
//
//};


//struct Boundary
//{
//	int width = 800, height = 600;
//
//
//	
//
//	void drawBound()
//	{
//		unsigned r = sfw::loadTextureMap("./res/Boundary.png");
//		sfw::drawTexture(r, 785, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
//		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
//		sfw::drawTexture(r, 50, 595, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
//		sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
//	}
//
//	/*void BoundCollision()
//	{
//		if (drawBall.posY > height)
//		{
//			velY *= -1;
//		}
//		else (drawBall.posY < height)
//		{
//			velY *= 1;
//
//		}
//	}*/
//
//};

//struct ScoreandTime
//{
//
//	void Time()
//	{
//		float x = 100, y = 100;
//		float x2 = 500, y2 = 100;
//		float counter = 0;
//		float size = 400;
//
//		while (sfw::stepContext)
//		{
//			counter += sfw::getDeltaTime();
//			if (counter > 1.f)
//			{
//				counter = 0;
//				size /= 2;
//			}
//		}
//
//		if (sfw::getKey('W'))
//			y += sfw::getDeltaTime() * 30;
//
//		if (sfw::getKey('S'))
//			y -= sfw::getDeltaTime() * 30;
//
//
//		if (sfw::getKey('A'))
//			y2 += sfw::getDeltaTime() * 30;
//
//		if (sfw::getKey('D'))
//			y2 -= sfw::getDeltaTime() * 30;
//
//		sfw::drawLine(x, y, x, y + size, CYAN);
//		sfw::drawLine(x2, y2, x2, y2 + size, RED);
//
//	}
//
//	void Score()
//	{
//
//
//	}
//
//
//
//};

//struct GameManager
//{
//	Player player1;
//	int p1score;
//
//};
