#include "RenderWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <vector>



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
		//std::cout << "Subsystems Initialized!\n";
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, hight, flags);
		
		if (window)
		{
			//std::cout << "Window Created!\n";
			//SDL_SetWindowMinimumSize(window, 100, 100);
		}
		
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 25, 121, 121, 255);
		}
	}
	
}

//void RenderWindow::render(vector<Enemy*>* Objects)
//{
//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//	SDL_RenderClear(renderer);
//	
//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//	for (Enemy* each : *Objects)
//	{
//		SDL_RenderFillRectF(renderer, &each->body->rect);
//	}
//
//	//SDL_RenderCopy(renderer,texture,NULL,NULL); // if i want to render a texture copy
//	SDL_RenderPresent(renderer); // use display() to show the renderer insted?
//	SDL_Delay(4);
//
//
//}

void RenderWindow::render3(vector<Enemy*>* Objects, vector<SDL_FRect*>* BulletRects, Player player)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	//Player
	SDL_SetRenderDrawColor(renderer, player.body->r,player.body->g, player.body->b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRectF(renderer, &player.body->rect);
	
	//How to draw a triangle
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	//SDL_RenderGeometry(renderer, nullptr, player.verts.data(), player.verts.size(), nullptr,0);
	
	// Enemies
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (Enemy* each : *Objects)
	{
		SDL_RenderFillRectF(renderer, &each->body->rect); // render enemies
	}

	// bullets
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (SDL_FRect* each : *BulletRects)
	{
		SDL_RenderFillRectF(renderer, each); //render bullets
	}
	
	//SDL_RenderCopy(renderer,texture,NULL,NULL); // if i want to render a texture copy
	SDL_RenderPresent(renderer);
	SDL_Delay(4);
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