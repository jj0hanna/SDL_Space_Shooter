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
	//VPositionList = new vector<Position>(); // heap
	
	
}

EnemyPooling::~EnemyPooling(){}

void EnemyPooling::CreateNewEnemies()
{
	std::cout << "CreateNewEnemy()\n";
	std::cout << "Inside CreateNewEnemies before loop. VFreeList.size():" << VFreeList.size() << std::endl;
	
		//for (int i = 0; i < CreateAmount; i++)
		//{
			VFreeList.push_back(new Enemy());
			VBodyList.push_back(VFreeList.back()->body);
			//VPositionList.push_back(new Position()); // do i have to remove from list?
			//VFreeList.back()->body = VBodyList.back();
			//VPositionList->push_back(Position());

		
			std::cout << "Inside CreateNewEnemies() VFreeList.size():" << VFreeList.size() << std::endl;
		
		//}
	
	
}
	
int EnemyPooling::GetEnemies(Enemy** E,int amount = 1) // this sould be called before the game starts. In source on the top? or should this be called in the contructor and the constructor get called in source?
{
	int getAmount = amount;
	int maxAmountImAllowedToCreate = 100;
	int createAmount = 2;
	while (VFreeList.size() < getAmount) // create all the enemies i wanted, but not more then im allowed
	{
		
		CreateNewEnemies(); // create one more enemy
		
	}
	if (getAmount + VIsActiveList.size() > Max)
	{
		
		getAmount = Max - VIsActiveList.size(); //change realAmount to a number that dont reach the Max
		
		if (getAmount <= 0)  // if realAmount is 0 or less, dont return and dont add any, ERROR
		{
			std::cout << "The Active list is full" << std::endl;
			getAmount = 0;
			// return?
		}
		
	}
	for (int i = 0; i < getAmount; i++)
	{
		//Add enemies to active list realAmount times
		E[i] = VFreeList.back();
		VIsActiveList.push_back(E[i]);
		
		std::swap(VFreeList.back()->body, VBodyList[VIsActiveList.size()-1]);
		E[i]->IsActive = true;
		E[i]->EnemyIndex = VIsActiveList.size() - 1;
		VFreeList.pop_back();

		//std::cout << "VFreeList.back()->body:" << VFreeList.back()->body << std::endl;
		//std::cout << "VBodyList[IsActiveList.size()-1]" << VIsActiveList.size() << std::endl;
	}
	std::cout << "Inside GetEnemies() ActiveList size:" << VIsActiveList.size() << std::endl;
	return getAmount;
}

void EnemyPooling::ReturnEnemy(Enemy* enemy)
{

	VIsActiveList.back()->EnemyIndex = enemy->EnemyIndex;
	std::swap(VIsActiveList[enemy->EnemyIndex], VIsActiveList.back());
	//std::swap(VPositionList[enemy->EnemyIndex], VPositionList.back());
	std::swap(VBodyList[enemy->EnemyIndex], VBodyList.back());
	//VIsActiveList[enemy->EnemyIndex]->EnemyIndex = enemy->EnemyIndex;

	VIsActiveList.pop_back();

	enemy->IsActive = false;
	//call enemy->ResetValues();
	VFreeList.push_back(enemy);
	
}

void EnemyPooling::UpdateEnemies()
{

	for (int i = 0; i < VIsActiveList.size(); i++)
	{
	
		if (currentDirection > 0 )
		{
			
			std::cout << "Going down" << std::endl;
			
			VBodyList[i]->rect.y += newDirectionDown;
			
			if (VBodyList[i]->rect.y >= 600.f)
			{
				currentDirection = newDirectionUp;
			}
			
		}
		if (currentDirection < 0)
		{
			std::cout << "Going up" << std::endl;
			if (VBodyList[i]->rect.y > 1.f)
			{
				VBodyList[i]->rect.y += newDirectionUp;
			}
			else
			{
				currentDirection = newDirectionDown;
			}
			
		}
		
	}
	
}




