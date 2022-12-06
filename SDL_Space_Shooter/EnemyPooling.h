#pragma once
#include <list>
#include <vector>
#include "Enemy.h"
#include "SDL.h"
#include "SDL_image.h"

class EnemyPooling
{
public:
	EnemyPooling();
	~EnemyPooling();
	
	std::list<Enemy> FreeList;
	std::list<Enemy> IsActiveList; // use list when the list gonna be hughe, otherwise vector

	std::vector<Enemy> VIsActiveList; // vector better then list?
	std::vector<Enemy> VFreeList;
	std::vector<int> VIntList;

	void CreateNewEnemy();
	Enemy GetEnemies();
	void ReturnEnemy(Enemy enemy); // not here?

	void RenderEnemy(Enemy& p_enemy);// dereffering here?
	//void Update(float& delta);
	
private:
	float Max = 5;
	SDL_Renderer* renderer;
};
