#pragma once
#include "Enemy.h"
#include "EnemyPooling.h"
#include "RenderWindow.h"
#include "BulletPool.h"
#include "Player.h"
#include "Timer.h"

//extern Enemy enemy; // sould i do extern?

class Game
{
#define WIDTH 1280
#define HEIGHT 720

public:
	Game();
	~Game();
	
	void StartGame();

	static Game& getInstance();

	Game(Game const&) = delete; // makes so we cant copy objectinstance
	void operator=(Game const&) = delete; // remove assigment operator to singelton


private:

	SDL_Renderer* render;
	EnemyPooling* enemyPool;
	RenderWindow* gamewindow;
	BulletPool* bulletpool;
	Player* player;
	Timer* timer;

	void EventHandler();
	void Render();
	void Update();
	void SpawnEnemies(int amount);
	void SpawnBullet();
	void CheckCollision();
	
	bool gameIsRunning;
	
	
	float spawnTimer = 0.0;
	float spawnDelay = 800.0f; // 100 = 2sec fix this
	bool spawnedFinished = false;

	// test deltatime
	float deltaTimeTest;
	Uint64 prevTicks;
	void CalcFrameRate();

	Timer* timer2;
	float deltaTimeTest2 = 0.0;

	//Window
	int windowHight = 720;
	int windowWidth = 1280;

	//int windowW;
	//int windowH;
	//int windowT;
	//int windowL;
	//int windowB;
	//int windowR;

	//For collision, not pretty..
	int enemyL;
	int enemyR;
	int enemyT;
	int enemyB;

	int bulletL;
	int bulletR;
	int bulletT;
	int bulletB;

	int playerL;
	int playerR;
	int playerT;
	int playerB;

};


