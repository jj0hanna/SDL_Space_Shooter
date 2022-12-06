#include "Game.h"
#include "RenderWindow.h"
#include "EnemyPooling.h"
#include "SDL.h"

//Enemy enemy;

Game::Game()
{
	
	RenderWindow Gamewindow("Game", 1280, 720); // render the window from the create window scrip
	Gamewindow.render();

	EnemyPooling EnemyPooling;
	//EnemyPooling.CreateNewEnemy();
	EnemyPooling.GetEnemies();// create all enemies?


	bool gameIsRunning = false;
	
	// create enemies from enemy pool script
	
}

Game::~Game(){}

void Game::StartGame()
{
	gameIsRunning = true;
	while (gameIsRunning)
	{
		EventHandler();
		Render(); // render all the enemies
	}
	
}

Game& Game::getInstance()
{
	static Game instance;
	return instance;
}

void Game::EventHandler()
{
	bool gameIsRunning = true;
	SDL_Event event;
	while (gameIsRunning)
	{
		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				gameIsRunning = false;
			}
			//window.render();
			//window.render2(E);
			//enemypooling.RenderEnemy(E);

			//window.display();

		}
	}

	//window.cleanUp();
	SDL_Quit();

}

void Game::Render()
{
	//SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	//SDL_RenderClear(render);
	// EnemiesPool.GetEnemies - Render the enemies from the IsActiveList
	//SDL_RenderPresent(render);
}

void Game::Update()
{
}
