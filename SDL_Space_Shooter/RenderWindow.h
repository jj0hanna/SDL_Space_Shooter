#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <type_traits>

using namespace std;
class RenderWindow
{

public:
	RenderWindow(const char* title, int width, int hight);

	void render3(vector<Enemy*>* Objects, vector<SDL_FRect*>* BulletRects, Player player);
	
	void cleanUp();
	
	SDL_Window* window;

private:
	
	SDL_Renderer* renderer;
	bool fullscreen;
};

