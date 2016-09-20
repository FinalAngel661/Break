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
	//float posX;
	//float posY;
	//int velX;
	//int velY;
	//float radius = 12;
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
	float timer;

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
	//Bound bo;
	//Graphics gr;

	////paddle logic
	//Player pl;
	//float playerx;

	////ball logic
	//Ball ball;
	//float posX, posY;
	//float velX, velY;


	//// time and score
	//float x;
	//float y;
	//float x2;
	//float y2;
	//float counter;
	//float size;


public:
	void init(int a_font);
	void update();
	void Draw();
	bool collision(Player pl, Ball ball);
	bool BoundCollision(Bound, Ball &ball);
	//void drawRound() const;
	bool isGameOver() const;
	APP_STATE next();

	Bound bo;
	Graphics gr;
	int font;

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

};

//bool isColliding(const Ball &a, const Player &b, const Boundary &c);

//class TimeScore
//{
//	int plScore;
//	float timer;
//public:
//	void drawTime();
//	void ScoreUp();
//	int plScore;
//	float timer;
//
//};