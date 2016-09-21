#pragma once
#include "Graphics.h"
#include "sfwdraw.h"
#include "constd.h"

class Player
{
	char name[64];
	int lives;

public:
	float playerx = 300;
	float playery = 300;
	void takeDamage(int dmg);
	void init(const char a_name[]);
	void drawPlayer();
	void PlayerUpdate();
};

class Ball
{

public:
	void init();
	void drawBall();
	void BallUpdate();
	float posX;
	float posY;
	int velX;
	int velY;
	float radius = 12;
	int plScore;
	int p2Score;
	float timer;
	int init2 = 1;
};

class Bound
{
	
public:
	int Window_Width = 800;
	int Window_Height = 600;
	void init();

};

class GameManager
{

public:
	void init(int a_font);
	void update();
	void Draw();
	bool collision(Player pl, Ball ball);
	bool BoundCollision(Bound, Ball &ball);
	bool isGameOver() const;
	APP_STATE next();

	Bound bo;
	Graphics gr;
	int font;
	char ans;

	//paddle logic
	Player pl;
	float playerx;

	//ball logic
	Ball ball;
	float posX, posY;
	float velX, velY;


	// time and score
	float x;
	float y;
	float x2;
	float y2;
	float counter;
	float size;
	Player *player1;
	Player *player2;

};
