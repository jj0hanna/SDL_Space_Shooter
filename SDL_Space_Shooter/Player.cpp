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
			this->movement->forward = true;
		}
		if (scancode == SDL_SCANCODE_A)
		{
			this->movement->left = true;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			this->movement->right = true;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			this->movement->back = true;
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
			this->movement->forward = false;
		}
		if (scancode == SDL_SCANCODE_A)
		{
			this->movement->left = false;
		}
		if (scancode == SDL_SCANCODE_D)
		{
			this->movement->right = false;
		}
		if (scancode == SDL_SCANCODE_S)
		{
			this->movement->back = false;
		}
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

float Player::GetMouseDirection(float p1, float p2)
{
	 float result;

	 float DeltaX;
	 float DeltaY;
	 DeltaX = body->rect.x - p1;
	 DeltaY = body->rect.y - p1;
	 result = (atan2(-DeltaX, DeltaY) * 180.00000) / 3.141592;

	return result;
}

void Player::PlayerDead(float xPos, float yPos)
{
	isDead = true;
	this->body->rect.y = 400;
	this->body->rect.x = 650;

	ClearPlayerScore();
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

