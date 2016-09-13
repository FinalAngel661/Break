#include "sfwdraw.h"
#include <iostream>
#include "Graphics.h"

void Graphics::drawBoundary()
{
	unsigned r = sfw::loadTextureMap("./res/Boundary.png");
	sfw::drawTexture(r, 785, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
	sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 90, false, 0, 0x88888888);
	sfw::drawTexture(r, 50, 595, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
	sfw::drawTexture(r, 5, 50, sfw::getTextureWidth(r), sfw::getTextureHeight(r), 0, false, 0, 0x88888888);
}

void Graphics::drawBackgound()
{
	unsigned s = sfw::loadTextureMap("./res/Background.png");
	sfw::drawTexture(s, 0, 0, 800, 600, 0, false, 0, 0x88888888);
}
