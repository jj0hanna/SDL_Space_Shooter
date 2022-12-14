#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

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
		float forwardSpeed = 2;
		float turnSpeed = 0;
		float direction = 0;

		bool forward = false;
		bool right = false;
		bool left = false;
		bool back = false;
	
	};
	struct Position
	{
		float x, y;
	};


	Movment* movement;
	Position* position;
	Body* body;

	std::vector< SDL_Vertex > verts = { { SDL_FPoint{ 400, 150 }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, },{ SDL_FPoint{ 200, 450 }, SDL_Color{ 0, 0, 255, 255 }, SDL_FPoint{ 0 },},{ SDL_FPoint{ 600, 450 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }} };
	bool shooting = false;
		
	
	bool Input(SDL_Event event);
	void MouseMovment(SDL_Event event);
	void MouseInput(SDL_Event event);
	void PlayerMovment();
	//void PlayerMovment(Position* position);
	void Draw();
	Player();

};

