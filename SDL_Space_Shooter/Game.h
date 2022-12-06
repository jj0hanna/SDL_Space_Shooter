#pragma once
#include "Enemy.h"

extern Enemy enemy; // sould i do extern?

class Game
{
public:
	Game();
	~Game();
	
	void StartGame();

	static Game& getInstance();

	Game(Game const&) = delete; // what does this do?
	void operator=(Game const&) = delete; // what does this do?


private:
	void EventHandler();
	void Render();
	void Update();

	bool gameIsRunning;
	SDL_Renderer* render;
};


