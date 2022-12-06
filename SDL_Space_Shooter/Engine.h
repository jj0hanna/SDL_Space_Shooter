#pragma once
#include "SDL.h"



//extern bool keys[SDL_NUM_SCANCODES];

// made the deltatime global

class Engine
{
public:
	Engine();
	~Engine();

	SDL_Window* window;
	SDL_Renderer* render;

	float delta_time;


private:

};

Engine::Engine()
{
}

Engine::~Engine()
{
}