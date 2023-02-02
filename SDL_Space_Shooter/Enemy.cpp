#include "Enemy.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>   
#include <time.h>       
#include <iostream>

using namespace std;
	
void Enemy::setEnemySize()
{
	float rectSize = rand() % 100 + 20;
	body->rect = { 1, 1, float(rectSize), float(rectSize) };
	prevRectSize = rectSize;
}

Enemy::Enemy()
{
	
	movement = new Movment();
	body = new Body();

	EnemyIndex = 0;

	movement->enemySpeed = rand() % 121 + 80; //give the enemies different speed between 80-200
	setEnemySize(); //give the enemies different size

}
