#pragma once


class GameManager
{
	////paddle logic
	//float playerx = 300;

	////ball logic
	//float posX = 300, posY = 500;
	//float velX, velY;

	//// time and score
	//float x = 100;
	//float y = 100;
	//float x2 = 500;
	//float y2 = 100;
	//float counter = 0;
	//float size = 400;


public:
	void init();
	void update();
	void Start();
	void drawStatus() const;
	//void drawRound() const;
	bool isGameOver() const;



};

bool isColliding(const Ball &a, const Player &b, const Boundary &c);