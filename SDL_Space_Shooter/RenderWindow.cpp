#include "RenderWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Enemy.h"


RenderWindow::RenderWindow(const char* title, int width, int hight)
{
	fullscreen = false;
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // what is this use or not?
	{
		std::cout << "Subsystems Initialized!\n";
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, hight, flags);
		if (window)
		{
			std::cout << "Window Created!\n";
			//SDL_SetWindowMinimumSize(window, 100, 100);
		}
		
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 25, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			//isRunning = true;
		}
	}
	
}

void RenderWindow::render()
{
	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderClear(renderer);
	//your stuff to render would typically go here.

	//SDL_RenderCopy(renderer,texture,NULL,NULL); // if i want to render a texture copy
	SDL_RenderPresent(renderer); // use display() to show the renderer insted?

}

void RenderWindow::render2(Enemy& p_enemy)
{
	
	SDL_Rect src;
	src.x = p_enemy.rect.x;
	src.y = p_enemy.rect.y;
	src.w = p_enemy.rect.w;
	src.h = p_enemy.rect.h;

	SDL_Rect dst;
	dst.x = p_enemy.x;
	dst.y = p_enemy.y;
	dst.w = p_enemy.rect.w;
	dst.h = p_enemy.rect.h;
	SDL_SetRenderDrawColor(renderer, 25, 25, 40, 255);
	SDL_RenderClear(renderer);
	
	SDL_RenderFillRect(renderer, &src);
	SDL_RenderPresent(renderer);
	//SDL_RenderDrawRect(renderer, &src);
	
	//SDL_RenderCopy();
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::clear()
{
	//SDL_RenderClear(renderer);
}

void RenderWindow::display()
{
	//SDL_RenderPresent(renderer);
}
