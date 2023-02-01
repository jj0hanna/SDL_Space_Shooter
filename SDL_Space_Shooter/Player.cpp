#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "BulletPool.h"
#include "Game.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

bool Player::Input(SDL_Event event)
{
	int scancode;

	if (event.type == SDL_KEYDOWN)
	{
		scancode = event.key.keysym.scancode;
		
		if (scancode == SDL_SCANCODE_W)
		{
			//std::cout << "W KEY PRESSED" << std::endl;
			this->movement->forward = true;

		}
		if (scancode == SDL_SCANCODE_A)
		{
			//std::cout << "A KEY PRESSED" << std::endl;
			this->movement->left = true;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			//std::cout << "D KEY PRESSED" << std::endl;
			this->movement->right = true;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			//std::cout << "S KEY PRESSED" << std::endl;
			this->movement->back = true;
		}
		if (scancode == SDL_SCANCODE_P)
		{
			//std::cout << "S KEY PRESSED" << std::endl;
			//isDead = false;
		}
		if (scancode == SDL_SCANCODE_ESCAPE)
		{
			return false;
		}
		
	}
	if (event.type == SDL_KEYUP)
	{
		scancode = event.key.keysym.scancode;

		if (scancode == SDL_SCANCODE_W)
		{
			//std::cout << "W KEY released" << std::endl;
			this->movement->forward = false;
		}
		if (scancode == SDL_SCANCODE_A)
		{
			//std::cout << "A KEY released" << std::endl;
			this->movement->left = false;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			//std::cout << "D KEY released" << std::endl;
			this->movement->right = false;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			//std::cout << "S KEY released" << std::endl;
			this->movement->back = false;
		}
		
	}
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
	if (!isDead)
	{
		SDL_MouseButtonEvent& b = event.button;
		int mouseX, mouseY;
		if (b.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&mouseX, &mouseY);
			shooting = true;
		}
	}
	
}

void Player::PlayerMovment(float deltaTime)
{
	if (!isDead)
	{
		if (this->movement->right)
		{
			this->body->rect.x += this->movement->forwardSpeed * deltaTime;
		}
		if (this->movement->left)
		{
			this->body->rect.x -= this->movement->forwardSpeed * deltaTime;
		}
		if (this->movement->forward)
		{
			this->body->rect.y -= this->movement->forwardSpeed * deltaTime;
		}
		if (this->movement->back)
		{
			this->body->rect.y += this->movement->forwardSpeed * deltaTime;
		}
	}
}

void Player::RotatePlayer()
{
	//int mouseX, mouseY;
	//SDL_GetMouseState(&mouseX, &mouseY);
	////cout << "MouseX" << mouseX << std::endl;
	////cout << "MouseY" << mouseY << std::endl;
	//int DeltaX;
	//int DeltaY;
	//double result;
	//DeltaX = position->x - mouseX;
	//DeltaY = position->y - mouseY;
	//result = (atan2(-DeltaX, DeltaY) * 180.00000) / 3.141592;
	//cout << "result" << result << std::endl;
	//movement->angle = result;
}

float Player::GetMouseDirection(float p1, float p2)
{
	 float result;
	//int mouseX, mouseY;
	//SDL_GetMouseState(&mouseX, &mouseY);
	 float DeltaX;
	 float DeltaY;
	 DeltaX = body->rect.x - p1;
	 DeltaY = body->rect.y - p1;
	 result = (atan2(-DeltaX, DeltaY) * 180.00000) / 3.141592;


	//float inv_length = 1.0f / sqrt(p1 * p1 + p2 * p2);
    //p1 *= inv_length;
	//p2 *= inv_length;


	cout << "result" << result << std::endl;
	return result;
}

void Player::PlayerDead(float xPos, float yPos)
{
	isDead = true;
	this->body->rect.y = 400;
	this->body->rect.x = 650;

	ClearPlayerScore();
	//this->body->rect = { xPos/2, yPos/2, 25, 50 };
}

void Player::SetPlayerScore(int score)
{
	playerScore += score;
	std::cout << "playerScore: " << playerScore << std::endl;
}

void Player::ClearPlayerScore()
{
	playerScore = 0;
}

Player::Player()
{
	movement = new Movment();
	body = new Body();
}
