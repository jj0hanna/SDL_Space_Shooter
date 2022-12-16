#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Enemy.h"

using namespace std;

struct Player
{
	struct Body
	{

		float width;
		float hight;
		SDL_FRect rect;
		SDL_Rect collision;
		Uint8 r = 0;
		Uint8 g = 0;
		Uint8 b = 255;
	};
	struct Movment
	{
		float forwardSpeed = 2;
		float turnSpeed = 0;
		float angle = 0;
		float mouseDirection = 0;

		bool forward = false;
		bool right = false;
		bool left = false;
		bool back = false;
	
	};
	
	Movment* movement;
	Body* body;

	std::vector< SDL_Vertex > verts = { { SDL_FPoint{ 400, 150 }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, },{ SDL_FPoint{ 200, 450 }, SDL_Color{ 0, 0, 255, 255 }, SDL_FPoint{ 0 },},{ SDL_FPoint{ 600, 450 }, SDL_Color{ 0, 255, 0, 255 }, SDL_FPoint{ 0 }} };
	bool shooting = false;
		
	
	bool Input(SDL_Event event);
	void MouseMovment(SDL_Event event);
	void MouseInput(SDL_Event event);
	void PlayerMovment();
	void RotatePlayer();
	float GetMouseDirection(float p1, float p2);
	Player();

};

