#include "SDL.h"
#undef main
#include <iostream>
#include "Enemy.h"
#include "RenderWindow.h"
#include "EnemyPooling.h"
#include "Game.h"


int main() {
	Game::getInstance().StartGame();
	return 0;
}
