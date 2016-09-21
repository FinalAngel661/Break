#include "Quit.h"
#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>
#include <stdlib.h>

void Quit::init(int a_font)
{
	font = a_font;
}

void Quit::play()
{
	timer = 3.f;
}

void Quit::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Time left: %f", timer);
	sfw::drawString(font, buffer, 100, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
}

void Quit::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Quit::next()
{
	if (timer < 0 || sfw::getKey('Q'))
	{
		 exit(0);
	}

	return QUIT;
}