#pragma once
#include "Enemy.h"
#include "EnemyPooling.h"
#include "RenderWindow.h";

extern Enemy enemy; // sould i do extern?

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

	bool gameIsRunning;
	int windowHight;
	int windowWidth;


	SDL_Renderer* render;
	EnemyPooling* enemyPooling;
	RenderWindow* gamewindow;

};


