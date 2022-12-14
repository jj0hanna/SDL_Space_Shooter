#pragma once
#include "Enemy.h"
#include "EnemyPooling.h"
#include "RenderWindow.h"
#include "BulletPool.h"
#include "Player.h"

//extern Enemy enemy; // sould i do extern?

class Game
{
public:
	Game();
	~Game();
	
	void StartGame();

	static Game& getInstance();

	Game(Game const&) = delete; // makes so we cant copy objectinstance
	void operator=(Game const&) = delete; // remove assigment operator to singelton


private:
	void EventHandler();
	void Render();
	void Update();
	void SpawnEnemies(int amount);
	void SpawnBullet();

	bool gameIsRunning;
	int windowHight;
	int windowWidth;


	SDL_Renderer* render;
	EnemyPooling* enemyPool;
	RenderWindow* gamewindow;
	BulletPool* bulletpool;
	Player* player;

};


