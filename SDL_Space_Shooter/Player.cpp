#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "BulletPool.h"
#include "Game.h"
#include <iostream>

bool Player::Input(SDL_Event event)
{
	int scancode;

	if (event.type == SDL_KEYDOWN)
	{
		scancode = event.key.keysym.scancode;
		
		if (scancode == SDL_SCANCODE_W)
		{
			std::cout << "W KEY PRESSED" << std::endl;
			std::cout << "GO FORWARD" << std::endl;
			this->movement->forward = true;

		}
		if (scancode == SDL_SCANCODE_A)
		{
			std::cout << "A KEY PRESSED" << std::endl;
			std::cout << "GO LEFT" << std::endl;
			this->movement->left = true;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			std::cout << "D KEY PRESSED" << std::endl;
			std::cout << "GO RIGHT" << std::endl;
			this->movement->right = true;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			std::cout << "S KEY PRESSED" << std::endl;
			this->movement->back = true;
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
			std::cout << "W KEY released" << std::endl;
			this->movement->forward = false;
		}
		if (scancode == SDL_SCANCODE_A)
		{
			std::cout << "A KEY released" << std::endl;
			this->movement->left = false;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			std::cout << "D KEY released" << std::endl;
			this->movement->right = false;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			std::cout << "S KEY released" << std::endl;
			this->movement->back = false;
		}
		
	}

	//return true;
}

void Player::MouseMovment(SDL_Event event)
{
	if (event.type == SDL_MOUSEMOTION)
	{
		//std::cout << "MOUSE  HAS BEEN MOVED" << std::endl;
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
		
		//std::cout << "&mouseX:" << mouseX << std::endl;
		//std::cout << "&mouseY:" << mouseY << std::endl;
		std::cout << "&mouseX:" << event.button.x << std::endl;
		std::cout << "&mouseX:" << event.button.y << std::endl;
	
		std::cout << "LEFT MOUSE HAS BEEN KLICKED" << std::endl;
		std::cout << "Shoot" << std::endl;
		shooting = true;
	}
	
	
	//shooting = false;
	
	// fix so we return the cordinates on where we klicked
}

void Player::PlayerMovment()
{

	if (this->movement->right)
	{
		this->body->rect.x += this->movement->forwardSpeed;
		
	}
	if (this->movement->left)
	{
		this->body->rect.x -= this->movement->forwardSpeed;
	}
	if (this->movement->forward)
	{
		this->body->rect.y -= this->movement->forwardSpeed;
	}
	if (this->movement->back)
	{
		this->body->rect.y += this->movement->forwardSpeed;
	}

}

//void Player::PlayerMovment(Position* position)
//{
//	
//}
//
void Player::Draw()
{
	
}

Player::Player()
{
	position = new Position();
	movement = new Movment();
	body = new Body();

	body->rect = { 50, 50, 25, 50 };
}
