#include "Player.h"
#include "sfwdraw.h"
#include <iostream>

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
	sfw::drawLine(playerx, 100, playerx + 100, 100);
	sfw::drawLine(playerx, 100, playerx - 100, 100);

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