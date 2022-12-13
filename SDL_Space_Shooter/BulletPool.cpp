#include "BulletPool.h"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>

using namespace std;
BulletPool::BulletPool()
{
	CreateBulletBodies();
	cout << "Inside BulletPool() constructor. bulletBodies.size():" << bulletBodies.size() << std::endl;
}

void BulletPool::CreateBulletBodies()
{
	SDL_Rect* rect = new SDL_Rect;
	rect->h = 50.f;
	rect->w = 50.f;
	for (int i = 0; i < CreateBulletAmount; i++)
	{
		bulletBodies.push_back(new SDL_FRect());
	}
	
}

void BulletPool::GetBullet()
{
 
	
}

void BulletPool::ReturnBullet()
{
}
