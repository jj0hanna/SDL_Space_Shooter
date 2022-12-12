#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

bool Player::Input(SDL_Event event)
{
	int scancode;

	if (event.type == SDL_KEYDOWN)
	{
		scancode = event.key.keysym.scancode;
		
		if (scancode == SDL_SCANCODE_A)
		{
			std::cout << "A KEY PRESSED" << std::endl;
			std::cout << "GO LEFT" << std::endl;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			std::cout << "D KEY PRESSED" << std::endl;
			std::cout << "GO RIGHT" << std::endl;
		}
		if (scancode == SDL_SCANCODE_W)
		{
			std::cout << "W KEY PRESSED" << std::endl;
			std::cout << "GO FORWARD" << std::endl;
		}
		
		if (scancode == SDL_SCANCODE_ESCAPE)
		{
			//gameIsRunning = false;
			return false;
			std::cout << "ESCAPE KEY PRESSED" << std::endl;
		}
		
	}
	if (event.type == SDL_KEYUP)
	{
		scancode = event.key.keysym.scancode;

		if (scancode == SDL_SCANCODE_W)
		{
			std::cout << "W KEY PRESSED" << std::endl;
		}
		if (scancode == SDL_SCANCODE_A)
		{
			std::cout << "A KEY released" << std::endl;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			std::cout << "D KEY released" << std::endl;
		}
		
	}

	//return true;
}

void Player::MouseMovment(SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
	{
		std::cout << "MOUSE  HAS BEEN MOVED" << std::endl;
	}
	
}

void Player::MouseInput(SDL_Event event)
{
	SDL_MouseButtonEvent& b = event.button;
	int mouseX, mouseY;
	if (b.button == SDL_BUTTON_LEFT)
	{
		//SDL_GetGlobalMouseState(&mouseX, &mouseY);
	    SDL_GetMouseState(&mouseX, &mouseY);
		
		std::cout << "&mouseX:" << mouseX << std::endl;
		std::cout << "&mouseY:" << mouseY << std::endl;
		std::cout << "&mouseX:" << event.button.x << std::endl;
		std::cout << "&mouseX:" << event.button.y << std::endl;
		std::cout << "&mouseY:" << mouseY << std::endl;
		std::cout << "LEFT MOUSE HAS BEEN KLICKED" << std::endl;
	}
	// fix so we return the cordinates on where we klicked
}

//void Player::PlayerMovment(Position* position)
//{
//	
//}
//
//void Player::Draw()
//{
//	
//}

Player::Player()
{
	position = new Position();
	movement = new Movment();
	body = new Body();

	body->rect = { 1, 1, 200, 200 };
	
}
