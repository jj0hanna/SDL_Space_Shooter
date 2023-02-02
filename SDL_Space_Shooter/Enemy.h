#pragma once
#include "SDL.h"
#include "SDL_image.h"

struct Movment
{
    float minSpeed;
	float maxSpeed;
	float enemySpeed;
    float yDirection;
	float xDirection;
};
struct Body
{
  
	float width;
    float hight;
    SDL_FRect rect;
	Uint8 r = 255;
	Uint8 g = 0;
	Uint8 b = 0;
};


struct Enemy
{
	bool IsActive = false;
	Movment* movement;
	Body* body;

	float prevRectSize = 0.f;
	int EnemyIndex = 0;
	void setEnemySize();
	Enemy();
};
