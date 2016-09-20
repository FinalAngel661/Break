#pragma once

#include "constd.h"

class Quit
{
	int font;
	float timer;
public:
	void init(int a_font);
	void play();
	void draw();
	void step();

	APP_STATE next();

};