#include "Game.h"
#include "RenderWindow.h"
#include "EnemyPooling.h"
#include "Player.h"
#include "BulletPool.h"
#include "Timer.h"
#include "SDL.h"
#include <iostream>
#include <type_traits>

Game::Game()
{
	gamewindow = new RenderWindow("Game", WIDTH, HEIGHT); // render the window from the create window scrip
	enemyPool = new EnemyPooling(); // create enemies from enemy pool script
	bulletpool = new BulletPool(); // create bulets from bullet pool script
	player = new Player();

	gameIsRunning = false;

	timer = Timer::Instance();

	prevTicks = SDL_GetPerformanceCounter();
	deltaTimeTest = 0.0f;
}

Game::~Game(){
	Timer::Release();
	timer = NULL;
}

void Game::StartGame()
{
	gameIsRunning = true;
	player->body->rect = { WIDTH/2, HEIGHT/2, 25, 50 };

	while (gameIsRunning)
	{
		CalcFrameRate();
		timer->Update();
		EventHandler();
		Update();
		Render(); 
	}

	gamewindow->cleanUp();
	SDL_Quit();
}

Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::EventHandler()
{
	SDL_Event event;
	int scancode;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_WINDOWEVENT)
		{
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			
				windowHight = event.window.data1;
				windowWidth = event.window.data2;
				
				enemyPool->GetWindowSize(event.window.data1, event.window.data2);
			default:
				break;
			}
		}

		switch (event.type)
		{
		case SDL_QUIT:
			gameIsRunning = false;
			break;
		case SDL_KEYDOWN:
			if (!player->Input(event))
			{
				gameIsRunning = false;
			}
			break;
		case SDL_KEYUP:
			player->Input(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			player->MouseInput(event);
			if (player->shooting)
			{
				SpawnBullet();
			}
			break;
		case SDL_MOUSEBUTTONUP:
			player->shooting = false;
			break;
		default:
			break;
		}
	}
}

void Game::Render()
{
	gamewindow->render3(&enemyPool->VIsActiveList, &bulletpool->IsActiveBulletsList ,*player);
}

void Game::Update()
{
	bulletpool->UpdateBullets(deltaTimeTest);
	enemyPool->UpdateEnemies(deltaTimeTest);
	player->PlayerMovment(deltaTimeTest);
	CheckCollision();

	spawnTimer += timer->GetDeltaTime();
	if (spawnTimer >= spawnDelay && !player->isDead && firstEnemyWaveHaveSpawned) // one spawndelay for when the game is ungoing and the first wave have spawned already
	{
		SpawnEnemies(6); // fix so they dont spawn on eachother
		spawnTimer = 0;
		if (spawnDelay > 500)
		{
			spawnDelay -= 500;
		}
	}
	else if(spawnTimer >= firstSpawnDelay && !player->isDead && !firstEnemyWaveHaveSpawned) // one spawndelay for the first time the game starts
	{
		SpawnEnemies(5);
		firstEnemyWaveHaveSpawned = true;
		spawnTimer = 0;
	}
	timer->Reset();
}

void Game::SpawnEnemies(int amount)
{
	
	int WindowW;
	int WindowH;
	int t;
	int l;
	int b;
	int r;

	int randomNr = 0;
	SDL_GetWindowSize(gamewindow->window,&WindowW, &WindowH); // get width and hight from the windows
	SDL_GetWindowBordersSize(gamewindow->window, &t, &l, &b, &r);
	
	int amountEnemiesThatSpawned;
	Enemy** E = new Enemy * [amount]; // create an array of enemies
	amountEnemiesThatSpawned = enemyPool->GetEnemies(E, amount);// create all enemies and give back the amount of enemies that spawned

	for (int i = 0; i < amountEnemiesThatSpawned; i++)
	{
		randomNr = 1 + rand() % 2;

		switch (randomNr)
		{
		case 1:
			// Get the edge of the Left side of the window
			E[i]->body->rect.x = 0.f; 
			E[i]->body->rect.y = rand() % WindowH;
			E[i]->movement->yDirection = 1.0f;
			E[i]->movement->xDirection = 1.0f;
			break;
		case 2:
			// Get the edge of the right of the window 
			E[i]->body->rect.x = WindowW - r; 
			E[i]->body->rect.y = rand() % WindowH;
			E[i]->movement->yDirection = -1.0f;
			E[i]->movement->xDirection = -1.0f;
			break;
		default:
			break;
		};
	}
	delete[] E; // remove to not leak
}

void Game::SpawnBullet()
{
	bulletpool->GetBullet();
	auto b = bulletpool->IsActiveBulletsList.back();
	
	b->x = player->body->rect.x + 8.f;
	b->y = player->body->rect.y - 10.f;
}

void Game::CheckCollision()
{
	playerL = player->body->rect.x; //left
	playerR = player->body->rect.x + player->body->rect.w; //right
	playerT = player->body->rect.y; //top
	playerB = player->body->rect.y + player->body->rect.h; // bottom 

	for (Enemy* each : enemyPool->VIsActiveList)
	{
		enemyL = each->body->rect.x; //left
		enemyR = each->body->rect.x + each->body->rect.w; //right
		enemyT = each->body->rect.y; //top
		enemyB = each->body->rect.y + each->body->rect.h; // bottom
		for (int i = 0; i < bulletpool->IsActiveBulletsList.size(); i++)
		{
			bulletL = bulletpool->IsActiveBulletsList[i]->x;
			bulletR = bulletpool->IsActiveBulletsList[i]->x + bulletpool->IsActiveBulletsList[i]->w; //right
			bulletT = bulletpool->IsActiveBulletsList[i]->y; //top
			bulletB = bulletpool->IsActiveBulletsList[i]->y + bulletpool->IsActiveBulletsList[i]->h; // bottom

			if (enemyL > bulletR || bulletL > enemyR || enemyT > bulletB || bulletT > enemyB) {
			}
			else
			{
				enemyPool->ReturnEnemyToFreeList(each);
				bulletpool->ReturnBullet(bulletpool->IsActiveBulletsList[i],i);
				player->SetPlayerScore(1);

				break;
			}
		}
		if (playerL > enemyR || enemyL > playerR || playerT > enemyB || enemyT > playerB){ // do this in a other way
		}
		else
		{
			player->PlayerDead(windowWidth, windowHight);
			enemyPool->ReturnAllEnemiesToFreeList();

			// set the spawnDelay to the default value again
			spawnDelay = 5000.f;

			player->isDead = false;
			firstEnemyWaveHaveSpawned = false;
			break;
		}
	}
}

void Game::CalcFrameRate()
{
	Uint64 ticks = SDL_GetPerformanceCounter();

	deltaTimeTest = (float)(ticks - prevTicks) / SDL_GetPerformanceFrequency();

	prevTicks = ticks;
}




