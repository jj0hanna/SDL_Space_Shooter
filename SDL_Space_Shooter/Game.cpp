#include "Game.h"
#include "RenderWindow.h"
#include "EnemyPooling.h"
#include "Player.h"
#include "SDL.h"
#include <iostream>
#include <type_traits>

Game::Game()
{
	
	gamewindow = new RenderWindow("Game", 1280, 720); // render the window from the create window scrip
	

	enemyPooling = new EnemyPooling(); // create enemies from enemy pool script
	
	player = new Player();

	gameIsRunning = false;
	
	
	
}

Game::~Game(){}

void Game::StartGame()
{
	SpawnEnemies(5); // fix bug (if i dont spawn all of the enemies in the free list)
	
	gameIsRunning = true;
	while (gameIsRunning)
	{
		EventHandler();
		Update();
		Render(); // render all the enemies
		
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

		switch (event.type)
		{
		case SDL_QUIT:
			gameIsRunning = false;
			break;
		case SDL_KEYDOWN:
			std::cout << "SOME KEY PRESSED" << std::endl;
			if (!player->Input(event))
			{
				std::cout << "Quit" << std::endl;
				gameIsRunning = false;

			}
			break;
		case SDL_KEYUP:
			player->Input(event);
			break;

		case SDL_MOUSEMOTION:
			player->MouseMovment(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			player->MouseInput(event);
			
			break;

		default:
			break;
		}

	}
	
}

void Game::Render()
{
	//std::cout << "Start of Game::Render()!\n";
	//gamewindow->render(&enemyPooling->VIsActiveList);
	gamewindow->render3(&enemyPooling->VIsActiveList, *player);
	
}

void Game::Update()
{
	enemyPooling->UpdateEnemies();
}

void Game::SpawnEnemies(int amount)
{
	int w;
	int h;
	SDL_GetWindowSize(gamewindow->window,&w,&h); // get width and hight from the window

	int amountEnemiesThatSpawned;
	Enemy** E = new Enemy * [amount]; // create an array of enemies
	amountEnemiesThatSpawned = enemyPooling->GetEnemies(E, amount);// create all enemies and give back the amount of enemies that spawned
	std::cout << "Before loop in spawn enemies, amountEnemiesThatSpawned:" << amountEnemiesThatSpawned << std::endl;

	for (int i = 0; i < amountEnemiesThatSpawned; i++)
	{
		//E[i]->position->y = 0;// fix this, what size is the window, fix error "8byte,16byte may be read"HELP
		//E[i]->position->x = 0;
		E[i]->body->rect.x = rand()% w;
		E[i]->body->rect.y = 50;
		
	}
	std::cout << "End of spawn enemies!\n"; 
	std::cout << "End of spawn enemies, amountEnemiesThatSpawned:" << amountEnemiesThatSpawned << std::endl;
	std::cout << "End of spawn enemies, ActiveList size:" << enemyPooling->VIsActiveList.size() << std::endl;
	std::cout << "End of spawn enemies, VFreeList size:" << enemyPooling->VFreeList.size() << std::endl;
	delete[] E; // remove to not leak
}
