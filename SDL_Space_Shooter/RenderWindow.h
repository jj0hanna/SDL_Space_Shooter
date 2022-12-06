#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Enemy.h"

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int hight);
	void render();
	void render2(Enemy& p_enemy);
	void cleanUp();
	void clear();
	void display();
	//~RenderWindow();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool fullscreen;
};

