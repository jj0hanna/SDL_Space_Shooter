#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Object
{
public:
	Object();
	
	float x = 0;
	float y = 0;

	float width;
	float hight;

	SDL_Rect rect;

	void Reset();
private:

};

