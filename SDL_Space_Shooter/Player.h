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
		float forwardSpeed = 200;
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

	bool shooting = false;
	bool isDead = false;
	int playerScore = 0;
	
	bool Input(SDL_Event event);
	void MouseInput(SDL_Event event);
	void PlayerMovment(float deltaTime);
	float GetMouseDirection(float p1, float p2);
	void PlayerDead(float xPos, float yPos);

	void SetPlayerScore(int score);
	void ClearPlayerScore();

	Player();
	

};

