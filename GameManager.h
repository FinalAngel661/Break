#pragma once
#include "Graphics.h"

class Player
{
	char name[64];
	int lives;

public:
	float playerx = 300;
	void takeDamage(int dmg);
	void init(const char a_name[]);
	void drawPlayer();
	void PlayerUpdate();
};

class Ball
{
	float posX;
	float posY;
	int velX;
	int velY;
public:
	void init();
	void drawBall();
	void BallUpdate();

};


class GameManager
{

	Graphics gr;

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


public:
	void init();
	void update();
	void Draw();
	//void drawRound() const;
	bool isGameOver() const;



};

//bool isColliding(const Ball &a, const Player &b, const Boundary &c);

class TimeScore
{
	int plScore;
	float timer;
public:
	void drawTime();
	void drawScore();

};