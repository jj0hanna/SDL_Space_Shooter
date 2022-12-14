#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <list>
#include <vector>

using namespace std;
class BulletPool
{
public:
	BulletPool();

	void GetBullet();
	void UpdateBullets();
	vector<SDL_FRect*> IsActiveBulletsList;
	vector<SDL_FRect*> FreeBulletsList;



private:

	
	
	int CreateBulletAmount = 100;
	//bool Active = false;

	void CreateBulletBodies();
	
	void ReturnBullet();

};
