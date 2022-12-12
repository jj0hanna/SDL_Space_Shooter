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
	void render(vector<Enemy*>* Objects);

	//template<typename T>
	//void render2(vector<T*>* Objects);
	void render3(vector<Enemy*>* Objects, Player player);

	void cleanUp();
	void clear();
	void display();
	//~RenderWindow();
	SDL_Window* window; // fix get function for this

private:
	
	SDL_Renderer* renderer;

	bool fullscreen;
};

