#include "BulletPool.h"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>

using namespace std;
BulletPool::BulletPool()
{

	for (int i = 0; i < CreateBulletAmount; i++)
	{
		CreateBulletBodies();
	}
}

void BulletPool::CreateBulletBodies()
{
	SDL_FRect* rect = new SDL_FRect;
	rect->h = 10.f;
	rect->w = 10.f;
	
	FreeBulletsList.push_back(rect);
}

void BulletPool::GetBullet()
{
	if (FreeBulletsList.size() < 1) // if we dont have any bullets in the freeList create more
	{
		for (int i = 0; i < CreateBulletAmount; i++)
		{
			CreateBulletBodies();
		}
		
	}
	SDL_FRect* bulletFRect = new SDL_FRect;
	bulletFRect = FreeBulletsList.back(); // bulletFRectis the last bullet in the freeList
	IsActiveBulletsList.push_back(bulletFRect); // add bullet to the activelist

	FreeBulletsList.pop_back();  // remove bullet from the freelist
}

void BulletPool::UpdateBullets(float deltaTime)
{
	SDL_FRect* B = new SDL_FRect;

	if (IsActiveBulletsList.size() > 0 )
	{
		for (int i = 0; i < IsActiveBulletsList.size(); i++)
		{
			B = IsActiveBulletsList[i];
			B->y -= 2.f * bulletSpeed * deltaTime; // bullet speed and direction
			
			if (B->y == 0)
			{
			 ReturnBullet(B, i);
			}
		}
		
	}
	
}

void BulletPool::ReturnBullet(SDL_FRect* bulletRect, int index)
{
	FreeBulletsList.push_back(bulletRect); // take THAT bullet and add it to the freelist
	std::swap(IsActiveBulletsList[index], IsActiveBulletsList.back()); // swap the THAT bullet that died with the bullet last in the isActiveList
	IsActiveBulletsList.pop_back(); // Since we spawed so the bullet that died is last - remove last bullet 
}
