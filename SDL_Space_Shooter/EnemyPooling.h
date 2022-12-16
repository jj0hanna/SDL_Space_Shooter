#pragma once
#include <list>
#include <vector>
#include "Enemy.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace std;
class EnemyPooling
{
public:
	EnemyPooling();
	~EnemyPooling();
	
	vector<Enemy*> VIsActiveList; // vector better then list?
	vector<Enemy*> VFreeList; // stack allocarad, listaq av pointers

	
	vector<Body*> VBodyList;
	//vector<Position*> VPositionList; // // or vector<Position>* VPositionList; // heap allocerad lista av Positions

	int GetEnemies(Enemy** E, int amount);
	void ReturnEnemy(Enemy* enemy);

	void UpdateEnemies();
	
private:
	void CreateNewEnemies();


	float max = 1000;
	float createAmount = 10;
	SDL_Renderer* renderer;

	float currentDirection = 1;
	float newDirectionUp = -1;
	float newDirectionDown = 1;
};
