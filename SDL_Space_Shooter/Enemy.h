#pragma once
#include "SDL.h"
#include "SDL_image.h"


//struct Enemy
//{
//    void move(struct Position* p, int count, float move_x, float move_y);
//    void draw(struct Body* Body);
// 
//};

struct Position 
{
    float x, y;
	
};
struct Movment
{
    float speed;
    float direction;
};
struct Body
{
  
	float width;
    float hight;
    SDL_FRect rect;
    //uint32_t color;
};


struct Enemy
{

	bool IsActive = false;
	
	Position* position;
	Movment* movement;
	Body* body;

	int EnemyIndex = 0;
	Enemy();

};
