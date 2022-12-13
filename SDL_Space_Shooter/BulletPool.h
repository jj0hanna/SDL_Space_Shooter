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

	

private:

	vector<SDL_FRect*> bulletBodies;
	
	int CreateBulletAmount = 4;
	//bool Active = false;

	void CreateBulletBodies();
	void GetBullet();
	void ReturnBullet();

};
