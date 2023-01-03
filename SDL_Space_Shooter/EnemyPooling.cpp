#include "EnemyPooling.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

EnemyPooling::EnemyPooling()
{
	CreateNewEnemies();
	std::cout << "Enemies created in constructor" << VFreeList.size() << std::endl;
	srand(time(NULL));
	//VPositionList = new vector<Position>(); // heap
	
}

EnemyPooling::~EnemyPooling(){}

void EnemyPooling::CreateNewEnemies()
{
	for (int i = 0; i < createAmount; i++)
	{
		VFreeList.push_back(new Enemy()); // stack?
	
		//VPositionList->push_back(Position());// heap
	}
}
	
int EnemyPooling::GetEnemies(Enemy** E, int amount = 1) // this sould be called before the game starts. In source on the top? or should this be called in the contructor and the constructor get called in source?
{
	int getAmount = amount;
	while (VFreeList.size() < getAmount) // create all the enemies i wanted, but not more then im allowed
	{
		CreateNewEnemies(); // create one more enemy
	}
	if (getAmount + VIsActiveList.size() > max)
	{
		
		getAmount = max - VIsActiveList.size(); //change realAmount to a number that dont reach the Max
		
		if (getAmount <= 0)  // if realAmount is 0 or less, dont return and dont add any, ERROR
		{
			std::cout << "The Active list is full" << std::endl;
			getAmount = 0;
			// return?
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
	std::cout << "Inside GetEnemies() ActiveList size:" << VIsActiveList.size() << std::endl;
	return getAmount; // return how many enemies we added to the ActiveList
}

void EnemyPooling::ReturnEnemy(Enemy* enemy)
{
	VIsActiveList.back()->EnemyIndex = enemy->EnemyIndex; // The enemy in the back of the ActiveList will get the enemiy that got killeds index
	std::swap(VIsActiveList[enemy->EnemyIndex], VIsActiveList.back()); // we then swap places with those two so the enemy that died is the last enemy in the list
	std::swap(VBodyList[enemy->EnemyIndex], VBodyList.back()); // we also swap the bodies so they have the right body 
	

	VIsActiveList.pop_back(); // remove the last enemy in the activelist(the enemy that died)
	VBodyList.pop_back(); // and remove the body

	enemy->IsActive = false;
	enemy->EnemyIndex = 0;
	VFreeList.push_back(enemy); // add the enemy that died to the FreeList

	std::cout << "VIsActiveList size:" << VIsActiveList.size() << std::endl;
	std::cout << "VBodyList size:" << VBodyList.size() << std::endl;
	std::cout << "VFreeList size:" << VFreeList.size() << std::endl;
}

void EnemyPooling::UpdateEnemies(float deltaTime)
{
	//int WindowW;
	//int WindowH;
	//auto renderWindow = Game::getInstance().gamewindow;
	//SDL_GetWindowSize(renderWindow->window, &WindowW, &WindowH); // can i do this in a other way? im doing this in this script and in game.cpp, spawn enemies()
	//std::cout << "WindowW :" << WindowW << std::endl;
	//std::cout << "WindowH :" << WindowH << std::endl;
	
	//Body* EnemyBody = new Body;
	//if (VIsActiveList.size() > 0)
	//{
	//	for (int i = 0; i < VBodyList.size(); i++)
	//	{
	//		EnemyBody = VBodyList[i];
	//		EnemyBody->rect.y -= 2.f;
	//		std::cout << "EnemyBody->rect.y: " << EnemyBody->rect.y << std::endl;
	//		if (EnemyBody->rect.y <= 0) // funkar inte
	//		{
	//			
	//	
	//		}
	//	
	//	}
	//
	//}


	for (int i = 0; i < VIsActiveList.size(); i++)
	{
		VBodyList[i]->rect.y += VIsActiveList[i]->movement->yDirection * speed * deltaTime;
		VBodyList[i]->rect.x += VIsActiveList[i]->movement->xDirection * speed * deltaTime;

		if (VBodyList[i]->rect.y < -130)
		{
			//std::cout << " body y is less then 0: " << std::endl;
			VIsActiveList[i]->movement->yDirection = 1;
		}
		if (VBodyList[i]->rect.y > windowHeight + 130)
		{
			//std::cout << " body y is bigger then window height: " << std::endl;
			VIsActiveList[i]->movement->yDirection = -1;
		}
		if (VBodyList[i]->rect.x < -130)
		{
			//std::cout << " body x is less then 0: " << std::endl;
			VIsActiveList[i]->movement->xDirection = 1;
		}
		if (VBodyList[i]->rect.x > windowWidth+130)
		{
			//std::cout << " body x is more then windowWidth: " << std::endl;
			VIsActiveList[i]->movement->xDirection = -1;
		}
		//std::cout << "VBodyList[i]->rect.y : " << VBodyList[i]->rect.y << std::endl;
		//std::cout << "VBodyList[i]->rect.x : " << VBodyList[i]->rect.x << std::endl;
		//std::cout << "windowHeight : " << windowHeight << std::endl; 720
		//std::cout << "windowWidth : " << windowWidth << std::endl; 1280
	}
}

void EnemyPooling::GetWindowSize(float height, float width)
{
	windowHeight = height;
	windowWidth = width;
}




