#include "EnemyPooling.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

EnemyPooling::EnemyPooling()
{
	CreateNewEnemies();
	srand(time(NULL));
}

EnemyPooling::~EnemyPooling(){}

void EnemyPooling::CreateNewEnemies()
{
	for (int i = 0; i < createAmount; i++)
	{
		VFreeList.push_back(new Enemy());
	}
}
	
int EnemyPooling::GetEnemies(Enemy** E, int amount = 1)
{
	int getAmount = amount;
	while (VFreeList.size() < getAmount) // create all the enemies i wanted
	{
		CreateNewEnemies();
	}

	if (getAmount + VIsActiveList.size() > max)
	{
		
		getAmount = max - VIsActiveList.size(); //change realAmount to a number that dont reach the Max
		
		if (getAmount <= 0)  // if realAmount is 0 or less, dont return and dont add any, ERROR
		{
			std::cout << "The Active list is full" << std::endl;
			getAmount = 0;
		}
		
	}
	for (int i = 0; i < getAmount; i++)
	{
		//Add enemies to activeList getAmount times
		//Add those bodies to the bodyList getAmount times
		E[i] = VFreeList.back();
		VIsActiveList.push_back(E[i]);
		VBodyList.push_back(E[i]->body);
		
		E[i]->IsActive = true;
		E[i]->EnemyIndex = VIsActiveList.size() - 1; // give the enemy the right index
		VFreeList.pop_back(); // remove last enemy from the FreeList
	}
	return getAmount; // return how many enemies we added to the ActiveList
}

void EnemyPooling::ReturnEnemyToFreeList(Enemy* enemy)
{
	VIsActiveList.back()->EnemyIndex = enemy->EnemyIndex; // The enemy in the back of the ActiveList will get the enemy that got killeds index
	std::swap(VIsActiveList[enemy->EnemyIndex], VIsActiveList.back()); // we then swap places with those two so the enemy that died is the last enemy in the list
	std::swap(VBodyList[enemy->EnemyIndex], VBodyList.back()); // we also swap the bodies so they have the right body 

	VIsActiveList.pop_back(); // remove the last enemy in the activelist(the enemy that died)
	VBodyList.pop_back(); // and remove the body

	enemy->IsActive = false;
	enemy->EnemyIndex = 0;
	VFreeList.push_back(enemy); // add the enemy that died to the FreeList
}

void EnemyPooling::ReturnAllEnemiesToFreeList()
{
	Enemy** enemy = new Enemy*;
	for (int i = VIsActiveList.size() ; i >= VIsActiveList.size() -1; i--)
	{
		*enemy = VIsActiveList.back();
		VFreeList.push_back(*enemy);
		VIsActiveList.pop_back();
		VBodyList.pop_back();
	}
	delete enemy;
}

void EnemyPooling::UpdateEnemies(float deltaTime)
{
	
	for (int i = 0; i < VIsActiveList.size(); i++)
	{
		VBodyList[i]->rect.y += VIsActiveList[i]->movement->yDirection * VIsActiveList[i]->movement->enemySpeed * deltaTime;
		VBodyList[i]->rect.x += VIsActiveList[i]->movement->xDirection * VIsActiveList[i]->movement->enemySpeed * deltaTime;

		if (VBodyList[i]->rect.y < -130)
		{
			VIsActiveList[i]->movement->yDirection = 1;
		}
		if (VBodyList[i]->rect.y > windowHeight + 130)
		{
			VIsActiveList[i]->movement->yDirection = -1;
		}
		if (VBodyList[i]->rect.x < -130)
		{
			VIsActiveList[i]->movement->xDirection = 1;
		}
		if (VBodyList[i]->rect.x > windowWidth+130)
		{
			VIsActiveList[i]->movement->xDirection = -1;
		}
	}
}

void EnemyPooling::GetWindowSize(float height, float width)
{
	windowHeight = height;
	windowWidth = width;
}
