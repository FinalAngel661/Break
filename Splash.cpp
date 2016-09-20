#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>

void Splash::init(int a_font)
{
	font = a_font;
}

void Splash::play()
{
	timer = 3.f;
}

void Splash::draw()
{
	char buffer[64];
	char splash[64];
	sprintf_s(splash, "LOADING...");
	sprintf_s(buffer, "Time left: %f", timer);
	sfw::drawString(font, buffer, 100, 100, 20, 20);
	sfw::drawString(font, splash, 100, 200, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
}

void Splash::step()
{
	timer -= sfw::getDeltaTime();
}

APP_STATE Splash::next()
{
	if (timer < 0 || sfw::getKey(KEY_ENTER))
		return ENTERGAME;

	return SPLASH;
}
