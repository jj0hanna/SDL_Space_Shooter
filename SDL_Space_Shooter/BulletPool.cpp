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
	

	cout << "BulletPool() constructor. FreeBulletsList.size():" << FreeBulletsList.size() << std::endl;
	//cout << "BulletPool() constructor. IsActiveBulletsList.size():" << IsActiveBulletsList.size() << std::endl;
	//GetBullet();
	
	

}

void BulletPool::CreateBulletBodies()
{
	SDL_FRect* rect = new SDL_FRect;
	rect->h = 50.f;
	rect->w = 50.f;
	//rect->x = rand() % 600;
	//rect->y = rand() % 600;
	//for (int i = 0; i < CreateBulletAmount; i++)
	//{
		FreeBulletsList.push_back(rect);
	//}
	//cout << "CreateBulletBodies(). FreeBulletsList.size():" << FreeBulletsList.size() << std::endl;
	
}

void BulletPool::GetBullet()
{
	if (FreeBulletsList.size() < 1)
	{
		for (int i = 0; i < CreateBulletAmount; i++)
		{
			CreateBulletBodies();
		}
		
	}

	SDL_FRect* bulletFRect = new SDL_FRect;
	bulletFRect = FreeBulletsList.back();
	IsActiveBulletsList.push_back(bulletFRect);

	FreeBulletsList.pop_back();

	cout << "After get bullet GetBullet(). FreeBulletsList.size():" << FreeBulletsList.size() << std::endl;
	cout << "After get bullet GetBullet(). IsActiveBulletsList.size():" << IsActiveBulletsList.size() << std::endl;

}

void BulletPool::UpdateBullets()
{
	if (IsActiveBulletsList.size() > 0 )
	{
		for (int i = 0; i < IsActiveBulletsList.size(); i++)
		{
			IsActiveBulletsList[i]->y -= 2.f;
			//IsActiveBulletsList[i]->x += 2.f;
		}
	}
}

void BulletPool::ReturnBullet()
{
}
