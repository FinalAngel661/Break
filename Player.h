#pragma once


class Player
{
private:
	char name[64], prior[64];
	int lives;

public:
	float playerx = 300;
	void takeDamage(int dmg);
	void init(const char a_name[], const char a_occ[]);
};