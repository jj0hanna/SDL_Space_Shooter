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
	//void render(vector<Enemy*>* Objects);

	void render3(vector<Enemy*>* Objects, vector<SDL_FRect*>* BulletRects, Player player);
	
	void cleanUp();
	void clear();
	void display();
	//~RenderWindow();
	SDL_Window* window; // fix get function for this

private:
	
	SDL_Renderer* renderer;

	bool fullscreen;
};

