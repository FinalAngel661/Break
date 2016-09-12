#include "Player.h"
#include <iostream>

void Player::init(const char a_name[], const char a_occ[])
{
	lives = 1;

}

void Player::takeDamage(int dmg)
{
	lives -= dmg;
}