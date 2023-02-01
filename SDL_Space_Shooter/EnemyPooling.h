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
	void ReturnAllEnemies();

	void UpdateEnemies(float deltaTime);

	void GetWindowSize(float height, float width);
	
private:
	void CreateNewEnemies();


	float max = 1000;
	float createAmount = 100;
	SDL_Renderer* renderer;

	float windowHeight = 720;
	float windowWidth = 1280;

	int minSpeed = 50.f;
	int maxSpeed = 200.f;
};
