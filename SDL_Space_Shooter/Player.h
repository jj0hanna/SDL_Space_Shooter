#pragma once
#include "SDL.h"
#include "SDL_image.h"

struct Player
{
	struct Body
	{

		float width;
		float hight;
		SDL_FRect rect;
		Uint8 r = 0;
		Uint8 g = 0;
		Uint8 b = 255;
	};
	struct Movment
	{
		float speed = 0;
		float direction = 0;
	};
	struct Position
	{
		float x, y;
	};


	Movment* movement;
	Position* position;
	Body* body;

	
	bool Input(SDL_Event event);
	void MouseMovment(SDL_Event event);
	void MouseInput(SDL_Event event);
	//void PlayerMovment(Position* position);
	//void Draw();
	Player();

};

