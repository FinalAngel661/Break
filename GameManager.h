#pragma once
#include "Player.h"
#include "Ball.h"
#include "Graphics.h"

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
	void Start();
	void Draw();
	//void drawRound() const;
	bool isGameOver() const;



};

//bool isColliding(const Ball &a, const Player &b, const Boundary &c);