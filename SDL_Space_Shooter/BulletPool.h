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
	void UpdateBullets(float deltaTime);
	void ReturnBullet(SDL_FRect* bulletRect, int index);
	vector<SDL_FRect*> IsActiveBulletsList;
	vector<SDL_FRect*> FreeBulletsList;

private:

	int CreateBulletAmount = 100;
	void CreateBulletBodies();
	float bulletSpeed = 200.f;
};
