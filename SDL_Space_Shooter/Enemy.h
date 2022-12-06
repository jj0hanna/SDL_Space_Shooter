#pragma once
#include "SDL.h"
#include "SDL_image.h"


//struct Enemy
//{
//    void move(struct Position* p, int count, float move_x, float move_y);
//    void draw(struct Body* Body);
// 
//};
//struct Position 
//{
//    float x, y;
//};
//struct Movment
//{
//    float speed;
//    float direction;
//};
//struct Body
//{
//    SDL_Renderer* renderer;
//   
//	  float width;
//    float hight;
//    SDL_Rect rect;
//    //uint32_t color;
//};


struct Enemy
{
	float x = 0;
	float y = 0;

	float width;
	float hight;

	SDL_Rect rect;

	bool IsActive = false;

};
