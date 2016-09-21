#include "Victory.h"
#include "sfwdraw.h"
#include <cstdio>

void Vic::init(int a_font)
{
	font = a_font;
}

void Vic::draw()
{
	char Vic[64];
	sfw::drawString(font, "You won!", 100, 200, 20, 20);
}

void Vic::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Vic::next()
{

	if (timer < 0 || sfw::getKey(KEY_ENTER))
	{
		return ENTERGAME;
	}
	return ENTERSPLASH;
}
