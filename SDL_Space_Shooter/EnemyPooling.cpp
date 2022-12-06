#include "EnemyPooling.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

EnemyPooling::EnemyPooling()
{
	
	
}

EnemyPooling::~EnemyPooling(){}

void EnemyPooling::CreateNewEnemy()
{
	//Enemy* enemy = new Enemy();
	Enemy enemy ; // new insted how?
	
	//if (VFreeList.size() != Max)
	//{
		VFreeList.push_back(enemy);
		//std::cout << "CreateNewEnemy()\n";
	//}
		
	//}

		//for (int i = 1; i <= 5; i++)
			//VIntList.push_back(i);

//		for (auto i = VIntList.begin(); i != VIntList.end(); ++i)
//			std::cout << *i << " "; // value in the list
			//std::cout << &i << " "; // Address in the list
	
	
	std::cout << "CreateNewEnemy() Freelist size:" << VFreeList.size() << std::endl;
	//std::cout << VIsActiveList.size() << std::endl;

	//new Enemy = enemy
	//VFreeList.push_back(enemy)
	//FreeList.push_back(enemy)
	
}

Enemy EnemyPooling::GetEnemies() // this sould be called before the game starts. In source on the top? or should this be called in the contructor and the constructor get called in source?
{
	Enemy E;

	//for (auto i = VFreeList.begin(); i != VFreeList.end(); ++i)
		//std::cout << *i << " ";
	
	
	for (int i = 0;  i < VFreeList.size() +1; i++) //4//3
	{
		if (VFreeList.size() != Max)
		{
			CreateNewEnemy();
			E = VFreeList.at(i); // Is this taking a enemy from theFree list to push it in the active list?
			VIsActiveList.push_back(E);
			std::cout << "Inside GetEnemies() ActiveList size:" << VIsActiveList.size() << std::endl;
			//VFreeList.erase(VFreeList.begin() + i); // how to remove from freelist?
		}
	}
	
	//remove THAT Enemy from FreeList
	//Add THAT enemy to usedList
	std::cout << "Inside GetEnemies() Freelist size End:" << VFreeList.size() << std::endl;
	
	//std::cout << VIsActiveList.size() << std::endl;
	return E;
}

void EnemyPooling::ReturnEnemy(Enemy enemy)
{
	//reset, remove enemy from usedList when they die and add to freeList
	//IsActiveList.remove(enemy);
	//FreeList.push_back(enemy);
	//enemy.IsActive = false;
}

void EnemyPooling::RenderEnemy(Enemy& p_enemy)
{
	SDL_Rect src;
	src.x = p_enemy.rect.x;
	src.y = p_enemy.rect.y;
	src.w = p_enemy.rect.w;
	src.h = p_enemy.rect.h;

	SDL_SetRenderDrawColor(renderer, 25, 25, 40, 255);
	//SDL_RenderClear(renderer);

	//SDL_RenderFillRect(renderer, &src);
	SDL_RenderPresent(renderer);
}



