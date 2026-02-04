#include "player.h"
#include "game.h"

Player::Player()
{
	image = LoadTexture("Images/spaceship.png");
	position.x = (GetScreenWidth() - image.width) / 2; 
	position.y = GetScreenHeight() - image.height;
	lastFireTime = 0.0;
}

Player::~Player()
{
	UnloadTexture(image);
}

void Player::Draw()
{
	DrawTexture(image, position.x, position.y, WHITE);
}

void Player::MoveLeft()
{
	position.x -= 7;
	if (position.x < 0)
		position.x = 0;
}

void Player::MoveRight()
{
	position.x += 7;
	if (position.x > (GetScreenWidth() - image.width))
		position.x = GetScreenWidth() - image.width;
}

void Player::FireLaser()
{
	if (GetTime() - lastFireTime >= 0.35)
	{
		lasers.push_back(Laser({ position.x + image.width / 2 - 2,position.y }, -6));
		lastFireTime = GetTime();
	}
	
}

